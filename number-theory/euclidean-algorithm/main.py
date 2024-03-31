# Euclidean Algorithm visualized, Computational Number Theory, Nikolas Achatz
# 1/14/2021


# We know by division algorithm that a = q*b + r. We can use Euclideans algorithm to find the
# gcd of these two values a and b. 
#First we need to setup the same way as the division algorithm where a = q*b+r with 0 <= r < b.
# From here we go until the remainder is 0, the previous remainder is our gcd. To do this we replace
# a with b and b with r looping until we hit the desired remainder of 0.

import math

# Division algorithm to yield q and r. This is detailed and stepped through in my github repo for
# the division algorithm in C++

def divisionAlgo(a,b):
    a = int(a)
    b = int(b)

    if a >= b:
        q = 0
        r = a

        while r >= b:
            r = r - b
            q = q + 1
    else:
        q = 0
        r = a

    return [q,r]


# This is the euclidean algorithm for calculating our gcd.

def euclideanAlgo(a, b):

    # ensure data is in integer types
    a = int(a)
    b = int(b)

    # if a is less than b, just swap them
    if a < b:
        hold = a
        a = b
        b = hold

    # if a is 0, the gcd is just b, likewise if b is 0 the gcd is a
    if a == 0:
        return b
    elif b == 0:
        return a

    # This function returns q and r using the division algorithm.
    container = divisionAlgo(a,b)

    # Fills q and r
    q = container[0]
    r = container[1]
    prevR = r

    #if r is 0, we know the gcd is just b
    if r == 0:
        return b
    else:
        while(True):
            # Loop infinitely until we get a remainder of 0, then the previous remainder is the gcd
            a = b
            b = r
            container = divisionAlgo(a,b)
            q = container[0]
            r = container[1]
            if r == 0:
                return prevR
            else:
                prevR = r





a = input("Value of a: ")
b = input("Value of b: ")

gcd = euclideanAlgo(a,b)

print(gcd)