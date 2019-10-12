import java.util.*;
import java.io.*;

public class NearestInterestingNumber_900 {
    private static int sum(int N)
    {
        String[] values = String.valueOf(N).split("");
        int sum = 0;
        for (int i = 0; i < values.length; i++)
        {
            sum += Integer.parseInt(values[i]);
        }
        return sum;
    }
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(nextString());
        while (sum(N) % 4 != 0)
        {
            N++;
        }
        System.out.println(N);
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
