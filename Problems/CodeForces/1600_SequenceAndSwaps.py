t = int(input())
for z in range(t):
    n, x = [int(num) for num in input().split()]
    vals = [int(val) for val in input().split()]
    vals_sorted = [val for val in vals]
    vals_sorted.append(x)
    vals_sorted.sort()
    ans = n
    found = False
    for i in range(1+n):
        cur = 0
        valid = True
        turns = 0
        add = False
        cutoff = x
        pos = [0 for i in range(501)]
        for j in range(n):
            if cur == i:
                cur += 1
            if (vals_sorted[cur] != vals[j]):
                pos[vals[j]] = cur
                if cur >= i:
                    pos[vals[j]] -= 1
            cur += 1
        cur = 0
        for j in range(n):
            if cur == i:
                if (vals_sorted[cur] == x):
                    add = True 
                cur += 1
            val = vals_sorted[cur]
            if val != vals[j]:
                turns += 1
                new_cutoff = vals[pos[vals[j]]]
                if (vals[j] <= cutoff or new_cutoff <= cutoff):
                    valid = False
                    break
                cutoff = new_cutoff 
            cur += 1

        if (valid):
            if add and turns > 0:
                turns += 1
            ans = min(ans, turns)
            found = True
    if found:
         print(ans)
    else:
        print(-1)
    
            





    
