# Valgrind Analysis

Valgrind Memcheck 3.18.1 was used to check `stack_example`, `aliasing_example`, and `heap_example`. The findings below were cross-checked against the C code and the memory maps.

## 1. Stack Example (stack_example.c)

### Results

- **0 errors; no leaks.** Valgrind reports 1 allocation, 1 free, and 4,096 bytes allocated in total.
- No invalid reads/writes or uninitialized-value warnings were reported.

### Explanation

The recursive `walk_stack()` calls create separate stack frames. Each `dump_frame()` call uses local variables that cease to exist when it returns. The program does not access these objects after their lifetime ends. No explicit heap allocation occurs in this program's source code.

### AI Error / Omission

**Omission:** The AI described the heap as empty in `stack_example.c`, overlooking possible runtime allocations. Valgrind reported 1 allocation and 1 free (4,096 bytes).

**Correction:** The program makes no explicit heap allocations, but the C runtime may allocate memory internally. Valgrind confirms that all allocated memory was freed, so no leak occurred.

## 2. Aliasing Example (aliasing_example.c)

### Reported errors

| Valgrind warning         | Source          | Memory misuse                          |
| ------------------------ | --------------- | -------------------------------------- |
| Invalid read of 4 bytes  | `main`, line 42 | Reading `b[2]` after `free(a)`         |
| Invalid write of 4 bytes | `main`, line 44 | Writing `b[3] = 1234` after `free(a)`  |
| Invalid read of 4 bytes  | `main`, line 45 | Reading `b[3]` after the invalid write |

**Summary:** 3 errors in 3 contexts; **0 leaks** (2 allocations, 2 frees).

### Explanation and memory map

`make_numbers()` allocates a 20-byte array (5 integers) at line 12. The assignment `b = a` makes `a` and `b` aliases of the same heap block:

```text
Before free(a):                  After free(a):
a --+                            a --+
    +--> [0, 11, 22, 33, 44]         +--X freed allocation
b --+                            b --+
```

`free(a)` at line 38 ends the array's lifetime, leaving **both pointers dangling**. The three later accesses through `b` are **use-after-free**, which is undefined behavior. Printing `22` or `1234` does not make these operations valid. Valgrind reports no leak because the array was freed.

## 3. Heap Example (heap_example.c)

### Results

- **Definitely lost:** 6 bytes in 1 block.
- **Allocation site:** `person_new()`, line 21 (called from `main()`, line 51).
- **Heap summary:** 5 allocations, 4 frees, 4,138 bytes allocated in total.
- No invalid-access or uninitialized-value warnings were reported.

### Explanation and memory map

`person_new()` allocates two separate objects for each person: a `Person` structure and a name buffer.

```text
alice --> Person --> "Alice\0" (6 bytes)
bob   --> Person --> "Bob\0"   (4 bytes)
```

Both `bob->name` and `bob` are freed. However, `person_free_partial(alice)` only frees Alice's `Person` structure. It does **not** free the separate name buffer. The pointer to that buffer is lost, causing a **memory leak due to lost ownership**. No pointer to the leaked block remains available when the program exits.