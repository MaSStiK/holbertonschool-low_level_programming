# Simple Calculator on C

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator
```

## How the program works

1. The program displays a menu with 5 options to choose from

```
Simple Calculator
1) Add
2) Subtract
3) Multiply
4) Divide
0) Quit
Choice:
```

1. The user selects the option
2. The program executes the selected option and prompts the user to enter two numbers
3. After the user enters two numbers, the program will display the desired result
4. After the function has been executed, the program will ask you to select an option again
5. If the user selects option 0, the program will close

### Addition

> A: 245
> B: 11
> Result: 256

_The function will print the result as an **int**._

### Subtraction

> A: 100
> B: 125
> Result: -25

_The function will print the result as an **int**._

### Multiplication

> A: 7
> B: 40
> Result: 280

_The function will print the result as an **int**._

### Division

> A: 10
> B: 3
> Result: 3.33

_The function will print the result as a **double**, truncating any trailing zeros._

_If the user enters 0 as the second number, the program will display `Error: division by zero` as an error message._
