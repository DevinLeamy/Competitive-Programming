import java.util.*;
import java.io.*;

public class VusTheCossackAndNumbers_1600 {
    public static void main(String[] args) throws IOException {
        int N = nextInt();
        long TS = 0;
        double[] values = new double[N];
        for (int i = 0; i < N; i++)
        {
            double V = Double.parseDouble(nextString());
            values[i] = V;
            TS += (int) V;
        }
        for (double value: values)
        {
            if (value - (int) value == 0 || TS == 0)
            {
                System.out.println((int) value);
            } else {
                if (TS > 0)
                {
                    if (value >= 0)
                    {
                        System.out.println((int) value);
                    } else {
                        System.out.println(((int) value) - 1);
                        TS--;
                    }
                } else {
                    if (value >= 0) {
                        System.out.println(((int) value) + 1);
                        TS++;
                    } else {
                        System.out.println(((int) value));
                    }
                }
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
    private static void println(String value)
    {
        System.out.println(value);
    }
}
