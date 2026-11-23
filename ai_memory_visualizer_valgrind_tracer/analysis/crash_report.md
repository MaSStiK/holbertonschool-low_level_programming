# Crash Report

## 1. Crash Description

`crash_example` terminates with `SIGSEGV`. Valgrind reports **Invalid write of size 4** at `crash_example.c:32`, targeting address `0x0`.

## 2. Root Cause

1. `main()` sets `n = 0`.
2. `allocate_numbers(0)` returns `NULL` at the `n <= 0` check, before calling `malloc()`.
3. `nums` receives `NULL`.
4. `nums[0] = 42` dereferences that null pointer, causing the invalid write and crash.

## 3. Invalid Memory Access

`nums` is a local pointer in `main()` (stack), but it points to **no valid object**. The write targets address `0x0`, not a valid stack or heap allocation. This is **undefined behavior: null pointer dereference**. No integer array was allocated. Valgrind also reports 512 bytes **still reachable** at termination; this does not explain the crash and is not a confirmed leak.

## 4. AI Explanation Review

**Correct:** The unchecked `NULL` return from `allocate_numbers()` causes the invalid write. Checking `nums` before accessing `nums[0]` would prevent this crash.

**Incorrect AI hypothesis:** `malloc()` failed and returned `NULL`. In fact, the `n <= 0` condition returns `NULL` **before `malloc()` is reached**. A stack-overflow explanation is also unsupported by the code and Valgrind's reported address.

**Suggested fix (not applied):** Add `if (nums == NULL) return 1;` before `nums[0] = 42;`.
