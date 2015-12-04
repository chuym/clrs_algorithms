# Use Strassen's algorithm to compute the matrix product

# Regular recursive implementation. Runs in Theta(n^3)
def square_matrix_mult(A, B):
    n = len(A)
    if n == 1:
        return [ [ A[0][0] * B[0][0] ] ]
    else:
        (a_top_left, a_bottom_left, a_top_right, a_bottom_right) = part_matrix(A)
        (b_top_left, b_bottom_left, b_top_right, b_bottom_right) = part_matrix(B)

        c_top_left = apply_matrix(square_matrix_mult(a_top_left, b_top_left),
                                  square_matrix_mult(a_top_right, b_bottom_left),
                                  add)

        c_top_right = apply_matrix(square_matrix_mult(a_top_left, b_top_right),
                                   square_matrix_mult(a_top_right, b_bottom_right),
                                   add)

        c_bottom_left = apply_matrix(square_matrix_mult(a_bottom_left, b_top_left),
                                     square_matrix_mult(a_bottom_right, b_bottom_left),
                                     add)

        c_bottom_right = apply_matrix(square_matrix_mult(a_bottom_left, b_top_right),
                                      square_matrix_mult(a_bottom_right, b_bottom_right),
                                      add)

        return combine(c_top_left, c_bottom_left, c_top_right, c_bottom_right)

# Implementation with Strassen's Algorithm. Runs in Theta(n^lg7)
def square_matrix_mult_strassen(A, B):
    n = len(A)
    if n == 1:
        return [ [ A[0][0] * B[0][0] ] ]
    else:
        (a_top_left, a_bottom_left, a_top_right, a_bottom_right) = part_matrix(A)
        (b_top_left, b_bottom_left, b_top_right, b_bottom_right) = part_matrix(B)

        S_1 = apply_matrix(b_top_right, b_bottom_right, sub)
        S_2 = apply_matrix(a_top_left, a_top_right, add)
        S_3 = apply_matrix(a_bottom_left, a_bottom_right, add)
        S_4 = apply_matrix(b_bottom_left, b_top_left, sub)
        S_5 = apply_matrix(a_top_left, a_bottom_right, add)
        S_6 = apply_matrix(b_top_left, b_bottom_right, add)
        S_7 = apply_matrix(a_top_right, a_bottom_right, sub)
        S_8 = apply_matrix(b_bottom_left, b_bottom_right, add)
        S_9 = apply_matrix(a_top_left, a_bottom_left, sub)
        S_0 = apply_matrix(b_top_left, b_top_right, add)

        P_1 = square_matrix_mult_strassen(a_top_left, S_1)
        P_2 = square_matrix_mult_strassen(S_2, b_bottom_right)
        P_3 = square_matrix_mult_strassen(S_3, b_top_left)
        P_4 = square_matrix_mult_strassen(a_bottom_right, S_4)
        P_5 = square_matrix_mult_strassen(S_5, S_6)
        P_6 = square_matrix_mult_strassen(S_7, S_8)
        P_7 = square_matrix_mult_strassen(S_9, S_0)

        c_top_left = apply_matrix(apply_matrix(apply_matrix(P_5, P_4, add), P_2, sub), P_6, add)
        c_top_right = apply_matrix(P_1, P_2, add)
        c_bottom_left = apply_matrix(P_3, P_4, add)
        c_bottom_right = apply_matrix(apply_matrix(apply_matrix(P_5, P_1, add), P_3, sub), P_7, sub)
        
        return combine(c_top_left, c_bottom_left, c_top_right, c_bottom_right)

# Only works for matrices 2^n where n >= 1
def part_matrix(A):
    size = len(A)
    half = size / 2
    top_left = [ [ A[i][j] for j in xrange(half) ] for i in xrange(half) ]
    bottom_left = [ [ A[i][j] for j in xrange(half) ] for i in xrange(half, size) ]
    top_right = [ [ A[i][j] for j in xrange(half, size) ] for i in xrange(half) ]
    bottom_right = [ [ A[i][j] for j in xrange(half, size) ] for i in xrange(half, size) ]

    return (top_left, bottom_left, top_right, bottom_right)

# Only works for matrices 2^n where n >= 1
def apply_matrix(A, B, f):
    size = len(A)
    return [ [ f(A[i][j], B[i][j]) for j in xrange(size) ] for i in xrange(size) ]

def combine(top_left, bottom_left, top_right, bottom_right):
    return [ x + y for (x, y) in zip(top_left, top_right) ] + [ x + y for (x, y) in zip(bottom_left, bottom_right) ]

def add(a, b):
    return a + b

def sub(a, b):
    return a - b

# Use strassen algorithm to compute the matrix product x * y
x = [
    [1, 3],
    [7, 5]
]

y = [
    [6, 8],
    [4, 2]
]
print square_matrix_mult_strassen(x, y)
# 18 14
# 62 66 
