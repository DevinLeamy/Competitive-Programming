import java.util.*;
import java.io.*;


public class NewsDistribution_1400
{
    public static class DisjointSet
    {
    int[] rank, parent;
    int n;

    public DisjointSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this.n = n;
        makeSet();
    }

    void makeSet()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union(int x, int y)
    {
        int xRoot = find(x), yRoot = find(y);

        if (xRoot == yRoot)
        {
            return;
        }

        if (rank[xRoot] < rank[yRoot])
        {
            parent[xRoot] = yRoot;
        } else if (rank[yRoot] < rank[xRoot])
        {
            parent[yRoot] = xRoot;
        }
        else {
            parent[yRoot] = xRoot;
            rank[xRoot] = rank[xRoot] + 1;
        }
    }
    }
    public static void main(String[] args) throws IOException
    {
        DisjointSet disjointSet;
        int N, M;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer line = new StringTokenizer(in.readLine());
        N = Integer.parseInt(line.nextToken());
        M = Integer.parseInt(line.nextToken());
        disjointSet = new DisjointSet(N);
        for (int i = 0; i < M; i++)
        {
            line = new StringTokenizer(in.readLine());
            int k = Integer.parseInt(line.nextToken());
            if (k > 0)
            {
                int hold = Integer.parseInt(line.nextToken()) - 1;
                for (int j = 0; j < k - 1; j++)
                {
                    int next = Integer.parseInt(line.nextToken()) - 1;
                    disjointSet.union(next, hold);
                    hold = next;
                }
            }
        }

        long[] sizeOfSets = new long[N];
        for (int i = 0; i < N; i++)
        {
            sizeOfSets[disjointSet.find(i)]++;
        }
        StringBuilder output = new StringBuilder();
        for (int i = 0; i < N; i++)
        {
            output.append(sizeOfSets[disjointSet.find(i)]);
            output.append(" ");
        }
        System.out.println(output.toString());
    }
}
