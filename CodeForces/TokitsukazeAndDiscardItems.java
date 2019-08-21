import java.util.*;
import java.io.*;

public class TokitsukazeAndDiscardItems {
    public static void main(String[] args) throws IOException {
        long N = nextLong(); long M = nextLong(); long K = nextLong();
        long count = 0;
        long removed = 0;
        long R = 0;
        long page = 0;
        for (int i = 0; i < M; i++)
        {
            long num = nextLong();
            num -= R;
            long cPage = num/K + ((num % K != 0)? 1: 0);
            if (cPage > page)
            {
                num -= removed;
                page = num/K + ((num % K != 0)? 1: 0);
                R += removed;
                removed = 0;
                count++;
            }
            removed++;
        }
        System.out.println(count);
    }
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
