# Push Swap

A program that sorts numbers using two stacks and a limited set of operations.

## Overview

Push Swap is a program that takes a list of numbers as input and sorts them using two stacks (A and B) with a specific set of allowed operations. The goal is to sort the numbers in ascending order using the minimum possible number of operations.

## Available Operations

- `sa`: swap the first two elements of stack A
- `sb`: swap the first two elements of stack B
- `ss`: perform sa and sb simultaneously
- `pa`: push the top element from stack B to stack A
- `pb`: push the top element from stack A to stack B
- `ra`: rotate stack A (first element becomes last)
- `rb`: rotate stack B (first element becomes last)
- `rr`: perform ra and rb simultaneously
- `rra`: reverse rotate stack A (last element becomes first)
- `rrb`: reverse rotate stack B (last element becomes first)
- `rrr`: perform rra and rrb simultaneously

## Installation

```bash
git https://github.com/Assanfakou/42cursus
cd 42cursus
cd push_swap
make
```

## Usage

```bash
./push_swap 4 67 3 87 23
```

To test with random numbers:

```bash
ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')"); ./push_swap $ARG
```

To count the number of operations:

```bash
ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l
```

## Example

Input:
```bash
./push_swap 3 1 4 2
```

Output:
```
pb
pb
sa
pa
pa
```

## Error Handling

The program handles the following error cases:
- Duplicate numbers
- Non-numeric input
- Numbers outside integer range
- Empty input

In case of error, the program displays "Error" on the standard error.
