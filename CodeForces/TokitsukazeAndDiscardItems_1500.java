import java.util.*;
import java.io.*;

public class TokitsukazeAndDiscardItems_1500 {
    public static void main(String[] args) throws IOException {
        long N = nextLong(); long M = nextLong(); long K = nextLong();
        long count = 0, removed = 0, R = 0, page = 0, num, cPage;

        for (int i = 0; i < M; i++)
        {
            num = nextLong();
            num -= R;
            cPage = num/K + ((num % K != 0)? 1: 0);
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
}
