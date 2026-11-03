_This project has been created as part
of the 42 curriculum by wli-ting & cchien-s_

# push_swap
## Description
###### _push_swap_ sorts a lists of integers with only two stacks(`Stack A` and `Stack B`). Minimizing the amount of operations used by implementing different algorithms with a different levels of difficulty.

###### As the requirements, our binary should have embed _four strategies_(`Simple(O(n^2))`, `Medium(O(n√n)`), `Complex(O(n log n)`), `Adaptive`).


## Instructions
> __BUILD__
```
make
make clean
make fclean
make re
```
###### `make`       : _builds 'libft' & './push_swap'_
###### `make clean` : _removes 'object files'_
###### `make fclean`: _removes 'objects' and 'binary'_
###### `make re`    : _fclean + all_

> __RUN__
```
./push_swap [flags] int1 int2 int3 ...
```
>###### __FLAGS__

| Strategies  |          Flags          |   Time Complexity  | Technique |
| ------------|:-----------------------:|:------------------:|:---------:|
| Simple      | `--simple`              |        O(n^2)      |           |    
| Medium      | `--medium`              |        O(n√n)      |           |
| Complex     | `--complex`             |      O(n log n)    |           |
| Adaptive    | `--adaptive`_(default)_ | Based on `disorder`|           |

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
# Algorithms and Explanation
### Simple Algorithm
### Medium Algorithm
### Complex Algorithm
# Performance
| n  |          Strategy          |  Min  | Max |  Avg   | Amount|
| ------------|:-----------------------:|:------------------:|:---------:|:-------|:------|
| 100      | `--simple`              |        1411      |    1614       |    1512    |    30      |
| 100      | `--medium`              |        834      |      894     |    864    |     30     |
| 100     | `--complex`             |      1084    |    1084       |   1084      |    30      |
| 100   | `--adaptive` |  835|       1084    |    959       |    30      |
| 500      | `--simple`              |        31630      |    33768       |    32699    |      30     |
| 500      | `--medium`              |        8767      |    8996       |   8881     |     30     |
| 500     | `--complex`             |      6784    |       6784    |    6784     |     30     |