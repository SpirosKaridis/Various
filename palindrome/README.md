# Number Analysis Utility

## Overview

This project is a **Number Analysis Utility** written in C that performs various mathematical and numerical checks on integers and floating-point numbers.
The program includes functions to check if a number is a prime, verify if a number is a palindrome, and determine if a number is a decimal.
It is optimized for performance, making it suitable for handling large integers.

### Key Features
- **Prime Number Check**: Efficiently checks if a given integer is a prime number.
- **Palindrome Check**: Determines if a given number is palindromic, meaning it reads the same backward as forward.
- **Decimal Check**: Verifies if a floating-point number is a decimal or a whole number.
- **Fast Algorithms**: Utilizes optimized algorithms for prime detection and palindrome verification.

## Functions

### 1. `checkifdecimal(long double n)`
- **Description**: Checks if a number is a decimal (i.e., has a fractional component).
- **Returns**: 
  - `0` if the number is a whole number.
  - `1` if the number has a fractional part.

### 2. `isPrime(unsigned long long int rt)`
- **Description**: Checks if a given number is prime.
- **Returns**:
  - `0` if the number is prime.
  - `1` if the number is not prime.

### 3. `fastPalindomic(unsigned long long int x)`
- **Description**: Checks if the first and last digits of a number match, used as an initial filter for palindromic numbers.
- **Returns**:
  - `1` if the number passes the initial palindrome check.
  - `0` otherwise.

## Compilation & Usage

### Requirements
- GCC (or any standard C compiler)
- Standard C libraries (e.g., `<stdio.h>`, `<stdlib.h>`, `<math.h>`, `<string.h>`)

### Compilation
To compile the program, use the following command:
```bash
gcc -o number_analysis mirror.c -lm
