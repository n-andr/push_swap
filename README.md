# Push-Swap

Push-Swap is a sorting algorithm project at [Your School/Institution], where the goal is to create a program that sorts a stack of integers using a limited set of instructions. The project challenges students to devise an efficient algorithm to sort the stack with the least number of operations possible.

## Overview

The Push-Swap project consists of two main programs:

1. **push_swap**: This program takes a list of integers as input and outputs a sequence of operations that sorts the list using only two stacks, A and B, along with a limited set of instructions.

2. **checker**: This program verifies whether a sequence of operations provided by push_swap successfully sorts the list of integers. It reads the sequence of operations from standard input and applies them to the list, then checks if the list is sorted.

## Performance

3 numbers: max 3 moves.
5 numbers: max 12 moves.
100 numbers: average 582 moves.
500 numbers: average 5163 moves.

## Instructions

The push_swap and checker programs utilize the following set of instructions to manipulate the stacks:

- **sa**: Swap the first two elements of stack A.
- **sb**: Swap the first two elements of stack B.
- **ss**: sa and sb combined.
- **pa**: Push the first element of stack A onto stack B.
- **pb**: Push the first element of stack B onto stack A.
- **ra**: Rotate stack A, moving the first element to the bottom.
- **rb**: Rotate stack B, moving the first element to the bottom.
- **rr**: ra and rb combined.
- **rra**: Reverse rotate stack A, moving the last element to the top.
- **rrb**: Reverse rotate stack B, moving the last element to the top.
- **rrr**: rra and rrb combined.

## Usage

To use the Push-Swap program, follow these steps:

1. Clone the repository to your local machine:

```bash
git clone https://github.com/your_username/push-swap.git

```bash
make

```bash
./push_swap 4 67 2 15 9

 
