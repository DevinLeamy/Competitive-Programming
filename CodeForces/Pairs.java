import java.util.*;
import java.io.*;

public class Pairs {
    private static boolean tryValue(int num, boolean[] fit, int[][] pairs, int M)
    {
        for (int i = 0; i < M; i++)
        {
            if (!fit[i])
            {
                if (pairs[i][0] != num && pairs[i][1] != num)
                {
                    return false;
                }
            }
        }
        return true;
    }
    private static boolean solve(int num, boolean[] fit, int[][] pairs, int M)
    {
        int B = -1;
        int C = -1;
        fit[0] = true;
        for (int i = 1; i < M; i++)
        {
            if (pairs[i][0] == num || pairs[i][1] == num)
            {
                fit[i] = true;
            } else {
                if (B == -1)
                {
                    B = pairs[i][0];
                }
                if (C == -1)
                {
                    C = pairs[i][1];
                }
            }
        }
        boolean works = tryValue(B, fit, pairs, M);
        if (works)
        {
            return true;
        } else {
            return tryValue(C, fit, pairs, M);
        }
    }
    public static void main(String[] args) throws IOException
    {
        int U = nextInt(); int M = nextInt();
        int[][] pairs = new int[M][2];
        if (M == 2)
        {
            System.out.println("YES");
        } else {
            for (int i = 0; i < M; i++)
            {
                pairs[i][0] = nextInt();
                pairs[i][1] = nextInt();
            }
            int A = pairs[0][0];
            int B = pairs[0][1];
            boolean works;

            works = solve(A, new boolean[M], pairs, M);
            if (works)
            {
                System.out.println("YES");
            } else {
                works = solve(B, new boolean[M], pairs, M);
                if (works)
                {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        }

    }

    //Template
    private static StringTokenizer line = new StringTokenizer("");
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    private static int nextInt() throws IOException
    {
        return Integer.parseInt(nextString());
    }
    private static long nextLong() throws IOException
    {
        return Long.parseLong(nextString());
    }
    private static String nextString() throws IOException
    {
        if (line.hasMoreTokens())
        {
            return line.nextToken();
        } else {
            line = new StringTokenizer(in.readLine());
            return line.nextToken();
        }
    }
    private static String[] nextStringArray() throws IOException
    {
        return in.readLine().split(" ");
    }
    private static int[] nextIntArray() throws IOException
    {
        return Arrays.stream(nextStringArray()).mapToInt(Integer::parseInt).toArray();
    }
}
