import java.util.*;
import java.io.*;

public class BadSequences_1200 {
    public static void main(String[] args) throws IOException
    {
        int N = nextInt();
        String line = nextString();
        int left = 0;
        boolean works = true;
        for (int i = 0; i < N; i++)
        {
            if (line.charAt(i) == '(')
            {
                left++;
            } else {
                left--;
            }
            if (left == -2)
            {
                works = false;
                break;
            }
        }
        if (left != 0)
        {
            works = false;
        }
        System.out.println( (works && N % 2 == 0)? "Yes" : "No" );
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
