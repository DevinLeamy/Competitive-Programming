//Works

import java.io.*;
import java.util.*;

public class ProblemB {
    private static void getDistances(int currentR, int currentC, int R, int C, int[] counter)
    {
        ArrayList<int[]> current = new ArrayList<>();
        current.add(new int[] {currentR, currentC});
        boolean[][] visited = new boolean[R][C];
        visited[currentR][currentC] = true;
        int marker = 1;
        while (current.size() > 0)
        {
            ArrayList<int[]> next = new ArrayList<>();
            for (int[] move : current)
            {
                try {
                    if (!visited[move[0]+1][move[1]])
                    {
                        next.add(new int[] {move[0]+1, move[1]});
                        counter[marker]++;
                        visited[move[0]+1][move[1]] = true;
                    }
                } catch (Exception e) {}
                try {
                    if (!visited[move[0]-1][move[1]])
                    {
                        next.add(new int[] {move[0]-1, move[1]});
                        counter[marker]++;
                        visited[move[0]-1][move[1]] = true;
                    }
                } catch (Exception e) {}
                try {
                    if (!visited[move[0]][move[1]+1])
                    {
                        next.add(new int[] {move[0], move[1]+1});
                        counter[marker]++;
                        visited[move[0]][move[1]+1] = true;
                    }
                } catch (Exception e) {}
                try {
                    if (!visited[move[0]][move[1]-1])
                    {
                        next.add(new int[] {move[0], move[1]-1});
                        counter[marker]++;
                        visited[move[0]][move[1]-1] = true;
                    }
                } catch (Exception e) {}
            }
            current = new ArrayList<>(next);
            marker++;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int depth = Integer.parseInt(in.readLine());
        StringTokenizer line = new StringTokenizer(in.readLine());
        int R = Integer.parseInt(line.nextToken());
        int C = Integer.parseInt(line.nextToken());
        line = new StringTokenizer(in.readLine());
        int[] counter = new int[R+C+1];
        int currentR = Integer.parseInt(line.nextToken())-1;
        int currentC = Integer.parseInt(line.nextToken()) -1;
        int count = 0;
        int T = Integer.parseInt(in.readLine());
        int E = depth + 2;
        int currentD = 0;
        getDistances(currentR, currentC, R, C, counter);
        int numInCurrentD = counter[currentD+1];
        while (T >= E)
        {
            if (numInCurrentD * E <= T)
            {
                T -= numInCurrentD * E;
                count += numInCurrentD;
                numInCurrentD = 0;
            } else {
                T -= E;
                numInCurrentD--;
                count++;
            }
            if (numInCurrentD == 0)
            {
                currentD++;
                numInCurrentD = counter[currentD+1];
                E = depth + (currentD+1)*2;
            }
        }
        System.out.println(count);
    }
}
