# Mertens Function Computation Utility

## Overview

This project is a **Mertens Function Computation Utility** written in C.
It is designed to compute values related to the Mertens function, often denoted as \( M(n) \), which is defined as the summation of the Möbius function \( \mu(k) \) for all integers \( k \leq n \).
The program uses efficient looping mechanisms to handle calculations for large ranges, making it suitable for mathematical research and analysis involving number theory.

### Key Features
- **Mertens Function Calculation**: Computes Mertens function values for a given range.
- **Möbius Function Support**: Includes logic for calculating the Möbius function \( \mu(n) \).
- **Efficient Segmentation**: Handles large number ranges through segmentation for optimized performance.
- **Customizable Exponent Limits**: Allows the user to define the maximum exponent (`MAXEXP`) for range calculations.

## How It Works
The program computes values within specific ranges determined by powers of 10:
- **Workspace Range**: The main calculation workspace is generated using \( 10^{\text{MAXEXP}} + 9 \).
- **Segments**: Utilizes segments defined by powers of 10 to optimize calculations for large ranges.

### Functions and Calculations
- **Mertens Function \( M(n) \)**: This is calculated as:
  \[
  M(n) = \sum_{k=1}^{n} \mu(k)
  \]
  where \( \mu(k) \) is the Möbius function.
- **Möbius Function \( \mu(n) \)**:
  - Returns `0` if \( n \) has a squared prime factor.
  - Returns `1` if \( n \) is a product of an even number of distinct primes.
  - Returns `-1` if \( n \) is a product of an odd number of distinct primes.

## Compilation & Usage

### Requirements
- GCC (or any standard C compiler)
- Standard C libraries (e.g., `<stdio.h>`)

### Compilation
To compile the program, use the following command:
```bash
gcc -o mertens_computation mersumb.c
