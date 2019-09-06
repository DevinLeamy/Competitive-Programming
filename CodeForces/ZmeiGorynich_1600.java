import java.util.*;
import java.io.*;

public class ZmeiGorynich_1600 {
    public static void main(String[] args) throws IOException
    {
        int T = nextInt();
        for (int i = 0; i < T; i++)
        {
            long N = nextLong(); long X = nextLong();
            long maxA = -1;
            long maxD = -1;
            for (int j = 0; j < N; j++)
            {
                long D = nextLong();
                long H = nextLong();
                if ((D - H) > maxD)
                {
                    maxD = (D - H);
                }
                if (D > maxA)
                {
                    maxA = D;
                }
            }
            X -= maxA;
            if (X > 0)
            {
                if (maxD <= 0)
                {
                    System.out.println(-1);
                } else {
                    System.out.println((X/maxD) + ((X % maxD == 0)? 1 : 2));
                }
            } else {
                System.out.println(1);
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
