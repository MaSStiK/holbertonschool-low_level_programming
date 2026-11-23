# Valgrind Analysis

Valgrind Memcheck 3.18.1 was used to check `aliasing_example` and `heap_example`. The findings below were cross-checked against the C code and the memory maps.

## 1. Aliasing Example (aliasing_example.c)

### Reported errors

| Valgrind warning         | Source          | Memory misuse                         |
| ------------------------ | --------------- | ------------------------------------- |
| Invalid read of 4 bytes  | `main`, line 42 | Reading `b[2]` after `free(a)`        |
| Invalid write of 4 bytes | `main`, line 44 | Writing `b[3] = 1234` after `free(a)` |
| Invalid read of 4 bytes  | `main`, line 45 | Reading `b[3]` after free(a)          |

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

### AI Error / Omission

**Omission:** The AI's initial analysis mentioned the invalid read of `b[2]` and the invalid write to `b[3]`, but missed the final read of `b[3]` in `printf()`.

**Correction:** After `free(a)`, all three accesses are use-after-free. Valgrind confirms two invalid reads (lines 42 and 45) and one invalid write (line 44).

## 2. Heap Example (heap_example.c)

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
