# Memory Maps

## 1. Stack Example - Recursion (stack_example.c)

### Purpose and execution

`walk_stack(0, 3)` recursively enters depths 0, 1, 2, and 3, then returns in reverse order. Each call has its own stack frame and `marker = depth * 10`.

`dump_frame()` creates `local_int = 100 + depth`, a 16-byte `local_buf`, and `p_local` pointing to `local_int`.

### Memory map at depth 3

During `dump_frame("enter", 3)`:

```text
STACK (active frames, newest first)

dump_frame(3): local_int=103, local_buf, p_local -> local_int
walk_stack(3): marker=30
walk_stack(2): marker=20
walk_stack(1): marker=10
walk_stack(0): marker=0
main()

HEAP: no dynamic allocation
```

### Lifetime and observed behavior

- Every `dump_frame()` entry creates local objects; they cease to exist when it returns. Its `walk_stack()` caller remains active.
- `walk_stack()` frames then return from depth 3 to 0, ending each frame's `marker` lifetime.
- At every depth, `p_local == &local_int`. The observed `local_int` address changed from `0x7fff031e6ec4` (depth 0) to `0x7fff031e6e34` (depth 3).
- The `enter` and `exit` calls at a given depth reused the same stack addresses, but their local objects were different. Addresses vary between runs.

### AI analysis review

The stack-frame and pointer-lifetime explanation was checked against the recorded output. Reused addresses do not mean a local variable survives after its function returns.

## 2. Aliasing Example - Use-After-Free (aliasing_example.c)

### Purpose and execution

`make_numbers(5)` allocates one heap array and fills it with `[0, 11, 22, 33, 44]`. In `main()`, `b = a` makes two pointers refer to the same array.

| Step | Operation                     | Memory change                                                           |
| ---- | ----------------------------- | ----------------------------------------------------------------------- |
| 1    | `a = NULL; b = NULL; n = 5`   | Local variables initialized in `main()`                                 |
| 2    | `make_numbers(n)`             | New stack frame: `n`, `i`, `arr`                                        |
| 3    | `malloc(5 * sizeof(int))`     | Heap array allocated (initially uninitialized)                          |
| 4    | Initialization loop           | Array becomes `[0, 11, 22, 33, 44]`                                     |
| 5    | `return arr`                  | Function frame ends; heap array remains valid; `a` receives its address |
| 6    | `b = a`                       | `a` and `b` alias the same allocation                                   |
| 7    | `free(a)`                     | Array lifetime ends; both pointers become dangling                      |
| 8    | `b[2]`, `b[3] = 1234`, `b[3]` | Invalid read, write, and read (undefined behavior)                      |

### Memory maps

**Inside `make_numbers()` after initialization:**

```text
STACK                             HEAP
main: a=NULL, b=NULL, n=5
make_numbers: n=5, i=5,
              arr -------------> [0, 11, 22, 33, 44]
```

**After `b = a` (valid) and after `free(a)` (invalid):**

```text
Before free(a):                  After free(a):
STACK         HEAP               STACK         HEAP
a --+                            a --+
    +-------> [0,11,22,33,44]        +----X     freed block
b --+                            b --+         (no valid access)
```

### Lifetime and observed behavior

- `return arr` ends the local `arr` variable's lifetime, **not** the heap allocation's lifetime.
- `free(a)` does not set `a` or `b` to `NULL`.
- The recorded run printed `b[2]=-370166616` after `free(a)` and later printed `b[3]=1234`. Neither result makes those accesses valid; both are undefined behavior.
- The heap array is owned by main() after make_numbers() returns. main() is responsible for freeing it exactly once. The pointer b is only an alias, not a separate allocation.

### AI error / omission

**Omission:** The AI's first memory map showed only `main()` variables (`a`, `b`, `n`), leaving out the `make_numbers()` stack frame.

**Correction:** During `make_numbers()`, its stack frame also contains the parameter `n` and locals `i` and `arr`. These objects cease to exist on return, while the heap array remains allocated until `free(a)`.

## 3. Heap Example - Memory Leak (heap_example.c)

### Purpose and execution

`person_new()` allocates two heap blocks per person: a `Person` structure and a separate name string. Its temporary local variables (`i`, `len`, `p`) belong to the function call and cease to exist when it returns.

| Step | Operation                     | Memory change                                          |
| ---- | ----------------------------- | ------------------------------------------------------ |
| 1    | `person_new("Alice", 30)`     | Allocates a `Person` and 6 bytes for `"Alice\0"`       |
| 2    | `person_new("Bob", 41)`       | Allocates another `Person` and 4 bytes for `"Bob\0"`   |
| 3    | `free(bob->name); free(bob);` | Releases both of Bob's heap blocks                     |
| 4    | `person_free_partial(alice)`  | Releases Alice's structure but **not** her name string |

### Memory map before cleanup

```text
STACK (main)                 HEAP
alice ---------------------> Person {name ------> "Alice\0", age=30}
bob -----------------------> Person {name ------> "Bob\0",   age=41}
```

### Lifetime and observed behavior

- The run printed different addresses for the two `Person` structures and their name buffers.
- Bob's structure and name are both freed correctly.
- Alice's structure is freed, but the separate 6-byte `"Alice\0"` buffer is not. Its last stored pointer is lost, causing a **memory leak**.
- The source performs four allocations and three frees, leaving Alice's 6-byte name buffer allocated.
- `main()` owns both `Person` structures and their name buffers. It must free both allocations for each person. Bob's memory is fully released, but Alice's name buffer is leaked.
