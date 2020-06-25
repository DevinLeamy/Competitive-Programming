import math

t = int(input())
for i in range(t):
    n = int(input())
    n = n * 2
    print(math.cos(math.pi/n) / math.sin(math.pi/n))
