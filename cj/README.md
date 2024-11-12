# Collatz Sequence Length Finder

This C program finds the longest **Collatz sequence** length for any integer within a specified range. 
The program accepts two integer inputs via the command line, representing the lower and upper bounds of the range, and then calculates the Collatz sequence for each number in that range.
It outputs the longest sequence length found.

## Overview

The **Collatz Conjecture** (also known as the "3n + 1 problem") is an unsolved problem in mathematics that involves sequences defined as follows:

1. If the number is even, divide it by 2.
2. If the number is odd, multiply it by 3 and add 1.
3. Repeat the process until the number reaches 1.

This program calculates the length of such sequences for numbers within a user-specified range and determines which number in that range produces the longest sequence.

## How It Works

- The program takes two command-line arguments:
  - `BotBorder`: The lower bound of the range.
  - `TopBorder`: The upper bound of the range.
- It then iterates through all integers within that range and calculates their Collatz sequence lengths.
- The program skips even numbers and numbers where `(n % 6 == 5)` for optimization.
- It tracks and prints the maximum sequence length found during the search.

## Requirements

- A C compiler (e.g., `gcc`)
- Compatible with Linux, macOS, and Windows environments
