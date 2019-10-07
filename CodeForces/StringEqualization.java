import java.util.*;
import java.io.*;

public class StringEqualization {
    private static String solve(String OG, String P)
    {
        if (OG.length() != P.length())
        {
            return "NO";
        }
        for (int i = 0; i < OG.length(); i++)
        {
            if (P.contains(String.valueOf(OG.charAt(i))))
            {
                return "YES";
            }
        }
        return "NO";
    }
    public static void main(String[] args) throws IOException {
        int N = nextInt();
        for (int i = 0; i < N; i++)
        {
            String OG = nextString();
            String P = nextString();
            System.out.println(solve(OG, P));

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