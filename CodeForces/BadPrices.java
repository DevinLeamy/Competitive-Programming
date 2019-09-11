import java.util.*;
import java.io.*;

public class BadPrices {
    public static void main(String[] args) throws IOException
    {
        int T = nextInt();
        for (int i = 0; i < T; i++)
        {
            int N = nextInt();
            int[] B = Arrays.stream(nextStringArray()).mapToInt(Integer::parseInt).toArray();
            int count = 0;
            int currentSmallest = Integer.MAX_VALUE;
            for (int j = N-1; j >= 0; j--)
            {
                int E = B[j];
                currentSmallest = Integer.min(E, currentSmallest);
                if (E > currentSmallest)
                {
                    count++;
                }
            }
            System.out.println(count);
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
