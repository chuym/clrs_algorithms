# The Role of Algorithms in Computing
## 1-1 Problems

### For each function `f(n)` and time `t` in the following table, determine the largest size `n` of a problem that can be solved in time `t`, assuming that the algorithm to solve the problem takes `f(n)` microseconds.

Considering that:

* 1 second = 1,000,000 microseconds
* 1 minute = 60,000,000 microseconds
* 1 hour = 3,600,000,000 microseconds
* 1 day = 86,400,000,000 microseconds
* 1 month = 2,592,000,000,000 microseconds
* 1 year = 31,536,000,000,000 microseconds
* 1 century = 3,153,600,000,000,000 microseconds

Then we have:

    |         | 1 second | 1 minute |  1 hour |     1 day |    1 month |      1 year |   1 century |
    |---------+----------+----------+---------+-----------+------------+-------------+-------------|
    | lgn     |    2^1e6 |    2^6e7 | 2 ^36e8 | 2^8.64e10 | 2^2.592e12 | 2^3.1536e13 | 2^3.1536e18 |
    | sqrt(n) |     1e12 |     6e14 |   36e16 |   8.64e20 |   2.592e24 |   3.1536e26 |   3.1536e36 |
    | n       |      1e6 |      6e7 |    36e8 |   8.64e10 |   2.592e12 |   3.1536e13 |   3.1536e18 |
    | nlgn    |    62746 |  2801417 |  1.33e8 |    2.75e9 |    7.19e10 |     7.98e11 |     6.86e13 |
    | n^2     |     1000 |     7745 |   60000 |    293938 |    1609968 |     5615692 |   5.61567e7 |
    | n^3     |      100 |      391 |    1532 |      4420 |      13736 |       31593 |      146645 |
    | 2^n     |       19 |       25 |      31 |        36 |         41 |          44 |          51 |
    | n!      |        9 |       11 |      12 |        13 |         15 |          16 |          17 |
