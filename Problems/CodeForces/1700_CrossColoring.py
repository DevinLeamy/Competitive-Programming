mod = 998244353

for _ in range(int(input())):
    # all cells are white initially (n x m)
    # (x, y) - color row x and col y with one of k colors 
    # task: determine # of unique colorings
    n, m, k, q = map(int, input().split()) 
    ops = [map(int, input().split()) for _ in range(q)]

    rows = dict() 
    cols = dict() 
    take = dict()

    for i, [row, col] in enumerate(ops):
        rows[row] = i 
        cols[col] = i

    row_min = min(rows.values())
    col_min = min(cols.values())

    if len(rows) < n:
        row_min = -1
    if len(cols) < m:
        col_min = -1

    for index in rows.values():
        if index >= col_min: 
            take[index] = 1 

    for index in cols.values():
        if index >= row_min:
            take[index] = 1 

    power = sum(take.values())
    ans = pow(k, power, mod) 

    print(ans)

