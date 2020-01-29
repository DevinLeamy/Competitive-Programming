class DisjointSet
{
    int[] depth, parent;
    int N;

    public DisjointSet(int N)
    {
        depth = new int[N];
        parent = new int[N];
        this.N = N;
        makeSet();
    }

    void makeSet()
    {
        for (int i = 0; i < N; i++)
        {
            parent[i] = i;
        }
    }

    int findSet(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = findSet(parent[x]);
        }
        return parent[x];
    }

    void union(int x, int y)
    {
        int xRep = findSet(x), yRep = findSet(y);

        if (xRep == yRep)
        {
            return;
        }

        if (depth[xRep] < depth[yRep])
        {
            parent[xRep] = yRep;
        } else if (depth[yRep] < depth[xRep])
        {
            parent[yRep] = xRep;
        } else {
            parent[yRep] = xRep;
            depth[xRep] = depth[xRep] + 1;
        }
    }
}
