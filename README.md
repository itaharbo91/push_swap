# Push Swap

An optimized sorting algorithm using two stacks and a limited set of operations to efficiently arrange a list of random numbers.

## 📋 Description

**Push Swap** sorts a stack of integers using only **two stacks** (A and B) and specific operations. The main objective is to achieve sorting with the **minimum number of movements possible**.

## 🎯 Objective

Transform from:
```
Stack A: [4, 67, 3, 87, 23]
Stack B: []
```

To:
```
Stack A: [3, 4, 23, 67, 87]  ✓ Sorted
Stack B: []
```

## 🛠️ Available Operations

### Swaps
- `sa` : Swap the first 2 elements of A
- `sb` : Swap the first 2 elements of B
- `ss` : Execute `sa` and `sb` simultaneously

### Push
- `pa` : Push the first element from B to A
- `pb` : Push the first element from A to B

### Rotate
- `ra` : Rotate all elements of A upward (first goes to last)
- `rb` : Rotate all elements of B upward
- `rr` : Execute `ra` and `rb` simultaneously

### Reverse Rotate
- `rra` : Rotate all elements of A downward (last goes to first)
- `rrb` : Rotate all elements of B downward
- `rrr` : Execute `rra` and `rrb` simultaneously

## 🧠 Algorithm Logic

### 1️⃣ Special Cases (≤ 5 elements)
For small lists, direct optimized sorting is used:
- **Size 2** : Simple swap if needed
- **Size 3** : Combination of rotates and swaps (max 2 operations)
- **Size 4** : Push minimum to B, sort the rest, return (max 6 operations)
- **Size 5** : Push 2 minimums to B, sort the rest, return in order (max 12 operations)

### 2️⃣ General Case (> 5 elements) - Divide & Conquer

#### Phase 1: Median-based Partition
```
1. Calculate the median of stack A
2. Push all elements < median to B
3. Push all elements >= median to B
```

#### Phase 2: Sorting via "Best Index"
The core of the algorithm: **select the best element to move**

For each element in B, calculate the **total cost** of movement:
```
cost = rotations_needed_in_B + rotations_needed_in_A
```

**Select the element with minimal cost** and insert it at the correct position in A.

#### Phase 3: Rotation Optimization
When both A and B need rotations:
- If both need **rotate** : use `rr` (2 operations in 1)
- If both need **reverse rotate** : use `rrr` (2 operations in 1)

#### Phase 4: Finalization
```
1. Push all remaining elements from B to A
2. Place the minimum of A at the top (first position)
```

### 📊 Optimization Example

Without optimization:
```
ra          (10 times)
rb          (5 times)
pb
...
Total: 15 operations
```

With optimization (rr/rrr):
```
rr          (5 times)
ra          (5 times)
pb
...
Total: 11 operations
```

## 🚀 Compilation

```bash
# Compile the main program
make

# Compile with bonus (checker program)
make bonus

# Clean object files
make clean

# Complete cleanup
make fclean

# Recompile
make re
```

## 💻 Usage

### Main Program
```bash
./push_swap 4 67 3 87 23
# Outputs the optimal sequence of operations:
# pb
# pb
# ra
# pa
# pa
```

With parameters as a string:
```bash
./push_swap "4 67 3 87 23"
```

### Bonus Program - Checker
```bash
./checker 4 67 3 87 23
# Reads operations from standard input
# Prints "OK" if sorted, "KO" otherwise

echo -e "pb\npb\nra\npa\npa" | ./checker 4 67 3 87 23
# OK
```

## 📈 Complexity

- **Small lists** (n ≤ 5) : O(1) in number of operations (fixed max)
- **Large lists** (n > 5) : O(n²) on average
  - Best index calculation : O(n)
  - Number of iterations : O(n)

## ✨ Applied Optimizations

✅ **Median-based partitioning** for balanced division
✅ **Best index** : selection of element with minimal cost
✅ **Double rotations** (rr/rrr) to reduce movements
✅ **Direction choice** : rotate vs reverse_rotate based on position (top/bottom of stack)
✅ **Memory management** : dynamic allocation, no leaks

## 🧪 Testing

```bash
# Simple test
./push_swap 3 2 1

# Test with negative numbers
./push_swap -3 -2 -1 0 1

# Test with duplicates (generates error)
./push_swap 1 2 2 3
# Error (duplicates not allowed)

# Test with non-integers (generates error)
./push_swap 1 2 abc 3
# Error
```

## 📚 Project Structure

```
push_swap/
├── Makefile                    # Compilation
├── srcs/
│   ├── main.c                  # Entry point
│   ├── push_swap.h             # Main header
│   ├── error_code.c            # Input validation
│   ├── instructions/           # Operations (sa, sb, pa, pb, ra, rb, etc.)
│   ├── sort/
│   │   ├── sort_small.c        # Direct sorting (n ≤ 5)
│   │   ├── sort_all.c          # Median-based and best_index sorting
│   │   ├── best_index.c        # Best element selection
│   │   └── rotate_to_top.c     # Optimized rotation
│   ├── tab/                    # Parsing and conversion
│   ├── utils/                  # Utilities (find_median, etc.)
│   └── opti/                   # Optimizations (rr, rrr)
└── bonus/                      # Checker program
```

## 🎓 42 School

Common Core Project - Cercle 2

## 📌 Key Points

- ✅ Robust error handling
- ✅ No memory leaks
- ✅ Maximum optimization of operation count
- ✅ Well-structured and modular code
- ✅ Bonus program (checker) to validate solutions

## 👤 Author

[@itaharbo91](https://github.com/itaharbo91)

---

**GitHub Description** : Stack-based sorting algorithm with optimized divide-and-conquer strategy using limited operations.
