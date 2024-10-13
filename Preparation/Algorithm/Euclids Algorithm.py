# Euclid's Algorithm Implemetation
# Finding the Biggest Identic Factor of Two Integers

# DECLARATION
# M = Integer: First Number
# N = Integer: Second Number
# r = Integer: Temporary Index

# ALGORITHM
M = int(input())
N = int(input())
r = 1 # Temporary
while r != 0:
    r = M % N
    M = N
    N = r

print(M)