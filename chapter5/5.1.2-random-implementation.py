# Describe an implementation of RANDOM(a, b) that only makes calls to RANDOM(0, 1).
# What is the expected running time of your procedure, as a function of a and b?

from random import randint

def base_rand():
    return randint(0, 1)

def rand(a, b):
    def iter(rang, direction):
        if len(rang) == 1:
            return rang[0]

        mid = len(rang) / 2

        if direction == 0:
            return iter(xrange(rang[0], rang[mid]), base_rand())
        else:
            return iter(xrange(rang[mid], rang[-1] + 1), base_rand())

    return iter(xrange(a, b + 1), base_rand())

# The running time of this algorithm is Theta(lg(b - a))