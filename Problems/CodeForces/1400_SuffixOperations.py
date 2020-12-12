t = int(input())

def cost(vals):
    cur = 0
    cost = 0
    for i in range(1, len(vals)):
        val = vals[i] + cur
        diff = vals[i] - vals[i-1]
        cost += abs(diff)
        cur += diff
    cut = max(abs(vals[1] - vals[0]), abs(vals[-1] - vals[-2]))
    for i in range(1, len(vals) - 1):
        best = abs(vals[i] - vals[i-1]) + abs(vals[i+1] - vals[i]) - abs(vals[i+1] - vals[i-1])
        cut = max(cut, best)           
    return cost - cut

for z in range(t):
    n = int(input())
    vals = [int(val) for val in input().strip().split()]
    print(cost(vals))
     


