//Works

import java.io.*;
import java.util.*;

public class Problem1 {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        int[] parents = new int[N+1];
        StringTokenizer line = new StringTokenizer(in.readLine());
        parents[0] = -1;
        int current = 1;
        for (int i = 1; i <= N; i++)
        {
            int parent = Integer.parseInt(line.nextToken());
            if (parent == 0)
            {
                parents[i] = current;
                current++;
                continue;
            }
            parents[i] = parents[parent];
        }
        int M = Integer.parseInt(in.readLine());
        line = new StringTokenizer(in.readLine());
        Set<Integer> potential = new HashSet<>();
        for (int i = 0; i < M; i++)
        {
            int affected = Integer.parseInt(line.nextToken());
            potential.add(parents[affected]);
        }
        System.out.println(potential.size());
    }
}
