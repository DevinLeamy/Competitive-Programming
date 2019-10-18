import java.util.*;
import java.io.*;

public class ProblemI {
    private static class DisjointSet
    {
            int[] depth, parent, members;
            int N;

            public DisjointSet(int N)
            {
                depth = new int[N];
                parent = new int[N];
                this.N = N;
                members = new int[N];
                Arrays.fill(members, 1);
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
                int temp = members[xRep];
                members[xRep] += members[yRep];
                members[yRep] += temp;
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
        int T = Integer.parseInt(in.readLine());
        for (int i = 0; i < T; i++)
        {
            int N = Integer.parseInt(in.readLine());
            ArrayList<String[]> unions = new ArrayList<>();
//            DisjointSet groups = new DisjointSet();
            for (int j = 0; j < N; j++)
            {
                String union = in.readLine();
                unions.add(union.split(" "));
            }
            Set<String> names = new HashSet<>();
            for (String[] union : unions)
            {
                for (String name : union)
                {
                    names.add(name);
                }
            }
            HashMap<String, Integer> map = new HashMap<>();
            int current = 0;
            for (String name : names) {
                map.put(name, current);
                current++;
            }

            DisjointSet groups = new DisjointSet(names.size());
            for (String[] union : unions)
            {
                groups.union(map.get(union[0]), map.get(union[1]));
                int rep = groups.findSet(map.get(union[0]));
                System.out.println(groups.members[rep]);
            }

        }
    }
}