import java.util.*;
import java.io.*;

public class ParallelUniverses {
    public static void main(String[] args) throws IOException
    {
        int n, k, m, t;
        n = nextInt(); k = nextInt(); m = nextInt(); t = nextInt();

        for (int i = 0; i < t; i++)
        {
            int num = nextInt();
            if (num == 1)
            {
                int pos = nextInt();
                if (pos <= k)
                {
                    k++;
                }
                n++;
                System.out.println(n + " " + k);
            } else {
                int pos = nextInt();
                if (pos < k)
                {
                    k -= pos;
                    n -= pos;
                } else {
                    n = pos;
                }
                System.out.println(n + " " + k);
            }
        }
    }

    //Template
    private static StringTokenizer line = new StringTokenizer("");
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

    private static int nextInt() throws IOException
    { return Integer.parseInt(nextString()); }

    private static String nextString() throws IOException
    { if (line.hasMoreTokens())
        { return line.nextToken(); } else {
            line = new StringTokenizer(in.readLine());
            return line.nextToken(); } }
}
