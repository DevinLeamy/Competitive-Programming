public class SegmentTree {
    private static void build(int node, int start, int end, int[] tree, int[] array)
    {
        if (start == end)
        {
            tree[node] = array[start];
        } else {
            int mid = (start + end)/2;
            build(2*node, start, mid, tree, array);
            build(2*node + 1, mid+1, end, tree, array);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
    private static void update(int node, int start, int end, int index, int value, int[] tree, int[] A)
    {
        if (start == end)
        {
            A[index] += value;
            A[node] += value;
        } else {
            int mid = (start + end)/2;
            if (start <= index && index <= mid)
            {
                update(2*node, start, mid, index, value, tree, A);
            } else {
                update(2*node+1, mid+1, end, index, value, tree, A);
            }
            tree[node] = tree[2*node] + tree[2*node + 1];
        }
    }
    private static int query(int node, int start, int end, int l, int r, int[] tree)
    {
        if (r < start || end < l)
        {
            return 0;
        }
        if (l <= start && end <= r)
        {
            return tree[node];
        }

        int mid = (start+end)/2;
        int p1 = query(2*node, start, mid, l, r, tree);
        int p2 = query(2*node+1, mid+1, end, l, r, tree);
        return (p1 + p2);
    }
}
