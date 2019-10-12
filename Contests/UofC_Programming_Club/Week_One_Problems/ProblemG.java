import java.util.*;
import java.io.*;


public class ProblemG {
    static class DisjointSet
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
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer line = new StringTokenizer(in.readLine());
        int N = Integer.parseInt(line.nextToken());
        int M = Integer.parseInt(line.nextToken());
        int[] wants = new int[N];
        for (int i = 0; i < N; i++)
        {
            wants[i] = Integer.parseInt(in.readLine());
        }
        DisjointSet clicks = new DisjointSet(N);
        for (int i = 0; i < M; i++)
        {
            line = new StringTokenizer(in.readLine());
            int f1 = Integer.parseInt(line.nextToken());
            int f2 = Integer.parseInt(line.nextToken());
            if (clicks.findSet(f1) != clicks.findSet(f2))
            {
                clicks.union(f1, f2);
            }
        }
        int[] costs = new int[N];
        for (int i = 0; i < N; i++)
        {
            int set = clicks.findSet(i);
            costs[set] += wants[i];
        }
        boolean good = true;
        for (int i = 0; i < N; i++)
        {
            if (costs[i] != 0)
            {
                good = false;
                break;
            }
        }
        if (good)
        {
            System.out.println("POSSIBLE");
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }
}
