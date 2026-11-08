*This project has been created as part of the 42 curriculum by wli-ting, cchien-s.*

# push_swap

## Description

**push_swap** sorts a list of integers using only two stacks (`Stack A` and
`Stack B`) and a fixed set of 11 operations
(`sa sb ss pa pb ra rb rr rra rrb rrr`). The program prints the operations, one
per line, that leave stack A sorted in ascending order (smallest number on top)
with stack B empty. The goal is to use as few operations as possible, which
makes algorithmic complexity very concrete: the same input can need a few
hundred or tens of thousands of moves depending on the algorithm.

As required by the subject, the binary embeds **four strategies**: Simple
(`O(n²)`), Medium (`O(n√n)`), Complex (`O(n log n)`) and Adaptive, which picks
one of the other three from the measured disorder of the input.

## Instructions

> **BUILD**

```
make
make clean
make fclean
make re
```

- `make`: builds `libft` and `./push_swap` (`cc -Wall -Wextra -Werror`)
- `make clean`: removes the object files
- `make fclean`: removes the objects and the binary
- `make re`: `fclean` + `all`

> **RUN**

```
./push_swap [flags] int1 int2 int3 ...
```

The first integer is the **top** of stack A. Flags must come **before** the
numbers.

| Strategy | Flag | Complexity (in operations) | Technique |
| --- | :---: | :---: | --- |
| Simple | `--simple` | O(n²) | Selection sort (extract the minimum) |
| Medium | `--medium` | O(n√n) | Bucket sort with about √n/2 buckets |
| Complex | `--complex` | O(n log n) | LSD radix sort on ranks |
| Adaptive | `--adaptive` *(default)* | Based on `disorder` | Chooses one of the three above |

| Option | Effect |
| --- | --- |
| `--bench` | After sorting, prints on **stderr**: the disorder (%), the strategy used and its complexity class, the total number of operations and the count of each operation |

Errors (arguments that are not integers, values outside the `int` range,
duplicates) print `Error` followed by a newline on **stderr**. With no
arguments the program prints nothing.

Examples:

```
./push_swap 2 1 3 6 5 8
```

```
./push_swap --simple 5 4 3 2 1
```

```
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
```

```
shuf -i 0-9999 -n 500 > args.txt
./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
cat bench.txt
```

Example of a `--bench` report (500 random numbers):

```
[bench] disorder: 49.87%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 8915
[bench] sa: 0 sb: 0 ss: 0 pa: 500 pb: 500
[bench] ra: 5000 rb: 1498 rr: 0 rra: 0 rrb: 1417 rrr: 0
```

# Algorithms and Explanation

## Common preparation

1. **Parsing and validation.** The arguments are joined, split on spaces and
   checked: integer syntax, `int` range, no duplicates.
2. **Ranks.** Each value is replaced by its rank (0 to n-1) = the number of
   values smaller than it. All strategies work on ranks, so there are no negative
   numbers or large gaps, and radix sort can work on bits.
3. **Disorder.** Measured once, **before any move**:
   `disorder = mistakes / total_pairs`, where a mistake is a pair `i < j` with
   `a[i] > a[j]`. It is `0` for a sorted input, `1` for a reversed one, and about
   `0.5` for a random one. This costs O(n²) CPU time, which is not part of the
   operation count.

All complexities below are measured in **Push_swap operations**, as the subject
requires, not in CPU time.

## Simple algorithm: selection sort, O(n²)

1. Find the smallest remaining rank in stack A.
2. Rotate A to bring it to the top, with `ra` or `rra`, whichever is shorter.
3. Push it to B (`pb`).
4. Repeat until A is empty, then push everything back with `pa`.

B receives the ranks in increasing order, so its top is always the largest: after
all the `pa`, A is sorted in ascending order.

**Bound:** each of the n rounds costs at most size/2 rotations plus one push, and
n pushes bring everything back: at most about n²/2 + 2n operations, so O(n²).
**Space:** O(1) extra besides the two stacks.

## Medium algorithm: bucket sort, O(n√n)

The ranks are split into `k = max(1, floor(√n) / 2)` contiguous value ranges
(buckets) of size `ceil(n / k)`: 5 buckets for 100 numbers, 11 for 500. The
buckets are processed from the highest ranks down to the lowest:

1. **distribute_bucket:** scan stack A once. A value that belongs to the current
   bucket is pushed to B (`pb`); any other value is rotated out of the way
   (`ra`).
2. **sort_bucket:** pull the bucket back to A from its largest rank down: rotate
   B the shorter way (`rb` or `rrb`) until the wanted rank is on top, then `pa`.

After the lowest bucket has been pulled back, A is sorted.

**Why divide √n by 2?** A smaller bucket count would make the extraction in B
more expensive, a larger one would make us scan A more often. Dividing by 2 gave
better operation count in our benchmarks.

**Bound:** each scan costs at most n operations, so the distribution costs at
most k·n. The extraction rotates a stack of at most n/k elements, so at most
n/(2k) rotations plus one push for each of the n values. Since k is about √n/2
(so n/k is about 2√n), both parts are O(n√n).
**Space:** O(1) extra besides the two stacks.

## Complex algorithm: LSD radix sort, O(n log n)

A least-significant-bit-first radix sort on the ranks. For each bit position,
from the lowest:

1. Look at each of the n values at the top of A, one by one.
2. If the current bit is 1, rotate it to the bottom of A (`ra`); if it is 0, push
   it to B (`pb`).
3. Push everything from B back to A (`pa`).

The sort stops early if A is already sorted at the start of a pass.

**Bound:** the number of passes is the bit length of the largest rank (7 for 100
numbers, 9 for 500), that is `floor(log2(n-1)) + 1`. Each pass costs at most 2n
operations (n for `pb`/`ra` and at most n for `pa`), so at most
2n·(floor(log2 n) + 1) operations: O(n log n). The count does not depend on the
order of the input, only on n (always 1084 for 100 numbers and 6784 for 500).
**Space:** O(1) extra besides the two stacks.

## Adaptive algorithm

The adaptive strategy measures the disorder first, then picks the method:

| Disorder | Method | Class |
| --- | --- | --- |
| `< 0.2` | Simple (selection sort) | O(n²) |
| `0.2 <= d < 0.5` | Medium (bucket sort) | O(n√n) |
| `>= 0.5` | Complex (radix sort) | O(n log n) |

- **Thresholds:** `0.2` and `0.5` are the boundaries given by the subject. The
  methods behind each regime are our own choice.
- **Why these methods:** a nearly sorted input has few wrong pairs, so a simple,
  low-overhead method is enough. A random input has a disorder close to 0.5,
  where bucket sort and radix sort pay off.
- **Small inputs:** for 5 numbers or fewer, any strategy is O(1), so we use
  dedicated sorters for 2, 3, 4 and 5 numbers (`limit_five`), which produce the
  shortest output. The `--bench` label still reports the disorder regime.
- **Complexity of the whole:** the cost is that of the chosen method, so it is
  bounded by O(n²), O(n√n) or O(n log n) in the three regimes. **Space:** O(n)
  for the stacks, plus O(1) extra.

# Performance

Operation counts on random inputs (distinct values):

| n | Strategy | Min | Max | Avg | Amount |
| --- | :---: | :---: | :---: | :--- | :--- |
| 100 | `--simple` | 1411 | 1614 | 1512 | 30 |
| 100 | `--medium` | 834 | 894 | 864 | 30 |
| 100 | `--complex` | 1084 | 1084 | 1084 | 30 |
| 100 | `--adaptive` | 835 | 1084 | 959 | 30 |
| 500 | `--simple` | 31630 | 33768 | 32699 | 30 |
| 500 | `--medium` | 8767 | 8996 | 8881 | 30 |
| 500 | `--complex` | 6784 | 6784 | 6784 | 30 |
| 500 | `--adaptive` | 6784 | 9031 | 7908 | 30 |

Subject targets: 100 numbers: `< 2000` pass, `< 1500` good, `< 700` excellent.
500 numbers: `< 12000` pass, `< 8000` good, `< 5500` excellent.

The default (adaptive) mode stays below the pass limit for both sizes. Random
inputs have a disorder close to 0.5, so the adaptive mode uses the medium or the
complex strategy on them. `--simple` is only used by the default mode on nearly
sorted inputs, so its 500-number result does not affect the default benchmark.

# Resources

- Subject: *push_swap* (42 curriculum), version 1.2
- Push swap visualizer: https://push-swap42-visualizer.vercel.app
- A. Yigit Ogun, *Push Swap: A journey to find most efficient sorting
  algorithm*, a walkthrough of the project and of the "Turk" cheapest-move
  approach: https://medium.com/@ayogun/push-swap-c1f5d2d41e97

## Use of AI

- Reviewing our code against the subject and checking edge cases.
- Writing test scripts: sorting verification with the checker, operation counts
  and benchmarks over random inputs, memory-leak checks.
- Helping to fix compile errors (unused parameter, unused static declaration).
- Helping to improve the readability and the language of this README.

We reviewed and tested everything produced with AI and we can explain it.

# Contributions

- **cchien-s**: complex algorithm, input validation, disorder metric, input parsing,norminette.

- **wli-ting**: simple algorithm, medium algorithm, benchmark mode, norminette, README.
