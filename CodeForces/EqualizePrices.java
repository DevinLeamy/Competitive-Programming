//Not on git, have not written my solution

import java.util.*;
import java.io.*;

public class EqualizePrices {
    private static int getMax(int S, int B, int K)
    {
        if (B - S > (2 * K))
        {
            return -1;
        }
        int add = K;
        while (B - (S + add) > K)
        {
            add--;
        }
        return S+add;
    }
    public static void main(String[] args) throws IOException {
        int Q = Integer.parseInt(nextString());
        for (int i = 0; i < Q; i++)
        {
            int N = Integer.parseInt(nextString()); int K = Integer.parseInt(nextString());
            StringTokenizer V = new StringTokenizer(in.readLine());
            int S = Integer.MAX_VALUE;
            int B = Integer.MIN_VALUE;
            for (int j = 0; j < N; j++)
            {
                int num = Integer.parseInt(V.nextToken());
                if (num > B)
                {
                    B = num;
                }
                if (num < S)
                {
                    S = num;
                }
            }
            System.out.println(getMax(S, B, K));
        }
    }
    private static StringTokenizer line = new StringTokenizer("");
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
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
}
