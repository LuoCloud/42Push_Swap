*This project has been created as part of the 42 curriculum by wli-ting, cchien-s.*

# push_swap

## 1. Description

**Goal**

The goal of push_swap is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, you have to manipulate various types of sorting algorithms and choose the most appropriate solution for an optimized data sorting process.

**Brief Overview**

This project involves sorting a randomized array of integers using two stacks (Stack A and Stack B). You are only allowed a specific set of operations, such as pushing the top element to the other stack (pa, pb), rotating the stack (ra, rb), or swapping the top elements (sa, sb).

Because sorting massive lists using basic comparison methods takes too many moves, this implementation dynamically adapts. It uses manual flags or automated detection to route the stack to the perfect mathematical algorithm—ranging from simple comparisons to bucket sorts and highly optimized bitwise Radix sorts.

## 2. Instructions

> **Step 1: BUILD**

You can type the following in your teminal provided you are at the root of where 
the file is:

```
make
make clean
make fclean
make re
```

- `make`: Compiles the source files and generates the ./push_swap executable.
- `make clean`: Removes all intermediate object (.o) files to free up space.
- `make fclean`: Removes all object files AND the final compiled executable.
- `make re`: Performs a complete fclean followed by a make to force a totally fresh recompilation.

> **Step 2: RUN**

You can now run the program by typing the following in the terminal:

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

## 3. Architecture & Program Roadmap

The program executes in a strict, memory-safe pipeline to ensure no leaks occur (even on crashes). Here is the lifecycle of a ./push_swap execution:

1.  main: The entry point. It captures the arguments and passes them to the parsing engine (error_checker & error_checkercont).

2.  error_checker & error_checkercont: The string parsing layer. It joins arguments, safely splits them using ft_split, and natively intercepts manual flags (like --complex) without tripping validation errors.

3.  helper_nodecreator: The validation layer. It loops through the parsed strings, running them through num_checker (to reject letters and bad signs) and a custom ft_atol (to safely catch integer overflows). Valid numbers are built into a Linked List (t_node).

4.  index_creator: Replaces the raw numbers with a sequential "Rank" (from 0 to N-1). This ensures the sorting algorithm deals with small, predictable, positive binary numbers instead of massive or negative integers.

5.  assigner: The dispatcher. It looks at the stack size, the disorder ratio, and any manual flags to route the Linked List to the correct sorting algorithm (limit_five, simple, medium, or complex).

6.  Sorting & Cleanup: The chosen algorithm outputs the correct operations (ra, pb, etc.) to stdout. Once sorted, control returns to the error checker where the string arrays and Linked List are safely freed.

## 4. Algorithm used

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

## 5. Technical Details & Mathematics

To build a highly optimized sorter, several computer science concepts were utilized.

## Space Complexity
Space Complexity measures how much extra RAM (memory) a program demands as the input gets bigger.

- **Our Rating:** $O(n)$(Linear Space).

- **Explanation:** For every integer the user inputs, the program uses malloc to create exactly one Linked List node. If 10,000 numbers are entered, exactly 10,000 nodes are created. Memory grows in a perfectly straight line relative to the input. We avoid allocating massive invisible arrays behind the scenes, ensuring the memory footprint stays exceptionally light.

## Time Complexity (Big O Notation) & Upper-Bounds
- **Time Complexity** measures how severely an algorithm's speed degrades as the workload approaches infinity. We drop constant multipliers (like $\frac{1}{2}$ ) because, at infinite scale, the mathematical shape of the curve matters more than tiny speed boosts. 

- **Upper-bound** refers to the absolute worst-case scenario (e.g., sorting a completely reversed list).

- **The Simple Algorithm: $O(n^2)$ (Quadratic Time)**
   
   - Meaning: Every number must be compared against every other number. Good for small stacks, catastrophic for large ones.
   
- **The Medium Algorithm (Bucket Sort): $O(n \sqrt{n})$**
   - Meaning: Numbers are grouped into buckets and pushed sequentially.
   
- **The Complex Algorithm (LSD Radix Sort): $O(nlogn)$**
   - Meaning: Instead of comparing numbers to each other, the algorithm sorts them strictly by their binary bits, crushing a massive list in just a few efficient rounds.
   
- **The Mathematics of the Bucket Sort (--medium)**
   - **Why divide the buckets by 2?** 
   
   When calculating the total number of buckets needed, dividing the calculated amount by 2 effectively doubles the capacity of each bucket. In real-world performance, this creates the perfect mathematical balance, making the program physically execute fewer instructions. (Note: Big O notation ignores this $\frac{1}{2}$ multiplier, but the hardware execution heavily benefits from it).
   
   - **Why use - 1 in the ceiling formula?**
    
    To figure out the size of the buckets without using <math.h> floats, we use the integer ceiling formula: (size + bucket_count - 1) / bucket_count. The - 1 is critical; if the total size is a perfect multiple of the bucket count, forgetting the - 1 would cause the math to spill over and create an empty, completely useless extra bucket at the end, wasting operations.
    
- **The Mathematics of Custom Square Roots & Precision Handling**

   Because the 42 standard forbids the use of <math.h>, we cannot use the standard sqrt() or floating-point rounding functions to calculate our bucket thresholds. Instead, we built a custom integer-based math engine:

   - **The root * root condition:** To find the square root of a number, we use a loop that incrementally guesses the root. By multiplying the guess by itself (root * root) and checking if it is less than or equal to our target, we avoid writing highly complex custom division algorithms.
   
   - **Why use root--?** 
   
      If the loop increments just past the exact mathematical square root (overshooting the target boundary), the root-- operation acts as a safety correction. It steps the value back by exactly one to ensure we return the largest safe integer limit.
   
   - **The * 10000 and + 0.5 rounding trick:** When manipulating float limits (like disorder ratios), standard C integer casting physically destroys the decimal, always rounding down (e.g., 0.99 becomes 0).
   
      - Multiplying by 10000 acts as a Fixed-Point arithmetic trick, safely capturing exactly 4 decimal places of precision and turning them into integers.
      
      - Adding 0.5 before casting is the universal computer science trick for accurate rounding. If the true value is 4.6, adding 0.5 makes it 5.1 (truncates to 5, effectively rounding up). If the value is 4.2, adding 0.5 makes it 4.7 (truncates to 4, effectively rounding down).
      
## Integer Overflow Protection (The 3000000000 Trap)
A major edge case in push_swap is handling extreme inputs like "9999999999999999".
If you feed that into a standard int calculation, the bits overflow past 2147483647 (INT_MAX) and silently wrap around into a completely valid, normal-looking negative number. The program would sort it without ever realizing it was an error.

To protect the parser, a custom ft_atol (ASCII to Long) function calculates the numbers using an extended memory block. The exact moment the math exceeds the boundaries of a standard 32-bit integer, it immediately aborts the calculation and returns 3000000000. This massive number acts as an error signal completely outside the bounds of a legal int, allowing helper_nodecreator to immediately catch the trap, trigger the Error\n message, and safely free the memory.

## The Mathematics of LSD Radix Sort (--complex)

The --complex algorithm uses a Least Significant Digit (LSD) Base-2 Radix Sort. Here is how it operates without using standard math operators:

   - The Binary Conveyor Belt (>> 1): Instead of dividing numbers using the CPU's Arithmetic Logic Unit (ALU)—which is slow—we use bitwise right shifts. Shifting a binary sequence right by 1 drops the last bit off the cliff, effectively dividing the number by 2 instantly at the hardware level.
   
   - The Magic Scanner (& 1): This bitwise mask acts like a sniper scope. It blinds the computer to everything except the far-right bit of the shifted number, allowing us to ask one simple question: "Is this bit a 0 or a 1?"
   
   - The "Flip-Flop" Mechanic: By starting at the weakest bit (LSD) and looping toward the strongest bit, we evaluate the stack round by round.
   
      - If the scanner sees a 0, the node is pushed to Stack B (pb).

      - If it sees a 1, it stays in Stack A (ra).

      - Because computer memory automatically pads smaller numbers with invisible leading 0s (up to 32 bits), smaller numbers effortlessly sink into Stack B during the final rounds. When they are pushed back (pa), the First-In-Last-Out nature of stacks perfectly layers the small numbers on top of the big numbers.

# 6. Performance

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
| 500 | `--adaptive` | <min> | <max> | <avg> | <amount> |

Subject targets: 100 numbers: `< 2000` pass, `< 1500` good, `< 700` excellent.
500 numbers: `< 12000` pass, `< 8000` good, `< 5500` excellent.

The default (adaptive) mode stays below the pass limit for both sizes. Random
inputs have a disorder close to 0.5, so the adaptive mode uses the medium or the
complex strategy on them. `--simple` is only used by the default mode on nearly
sorted inputs, so its 500-number result does not affect the default benchmark.

# 7. Resources

- Subject: *push_swap* (42 curriculum), version 1.2
- Push swap visualizer: https://push-swap42-visualizer.vercel.app
- A. Yigit Ogun, *Push Swap: A journey to find most efficient sorting
  algorithm*, a walkthrough of the project and of the "Turk" cheapest-move
  approach: https://medium.com/@ayogun/push-swap-c1f5d2d41e97
- C Programming Bitwise Operators (GeeksforGeeks).

- Radix Sort Algorithm Theory (Brilliant.org).

- Valgrind Memory Debugging Documentation.

## 8. Use of AI

- Reviewing our code against the subject and checking edge cases.

- Writing test scripts: sorting verification with the checker, operation counts
  and benchmarks over random inputs, memory-leak checks.

- Helping to fix compile errors (unused parameter, unused static declaration).

- Helping to improve the readability and the language of this README.

- Algorithm Concept Breakdown: AI was used to break down the highly technical mathematics of LSD Radix Sort and bitwise operators (>> and &) into digestible, visual analogies (like conveyor belts and light switches).

- Computer Science Theory: Engaged for in-depth Q&A regarding Big O notation, Space/Time Complexity curves, bucket ceiling math formulas, the hardware mechanics of the ALU vs. bitwise shifting, identifying integer overflow limits (ft_atol), and understanding custom integer square root/precision rounding mathematics (* 10000, + 0.5).

No code was blindly copied. AI was leveraged purely to understand the why and how of the underlying mechanics.
We reviewed and tested everything produced with AI and we can explain it.

# 9. Contributions

- **cchien-s**: complex algorithm, input validation, disorder metric, input parsing,norminette.

- **wli-ting**: simple algorithm, medium algorithm, benchmark mode, norminette, README.