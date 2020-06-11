import java.util.*;
import java.io.*;

public class CandyBox_1400 {
    public static void main(String[] args) throws IOException {
        int Q = nextInt();
        for (int i = 0; i < Q; i++)
        {
            int N = nextInt();
            int[] count = new int[N + 1];
            int S = 0;
            for (int j = 0; j < N; j++)
            {
                int C = nextInt();
                count[C]++;
            }
            Arrays.sort(count);
            int next = count[N];
            for (int j = N; j >= 0; j--)
            {
                if (next <= 0)
                {
                    break;
                }
                int V = count[j];
                if (V >= next)
                {
                    S += next;
                    next--;
                } else {
                    next = V;
                    S += next;
                    next--;
                }

            }
            System.out.println(S);
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
    private static void print(String value)
    {
        System.out.println(value);
    }
}
