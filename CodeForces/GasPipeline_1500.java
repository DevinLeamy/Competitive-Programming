import java.util.*;
import java.io.*;

public class GasPipeline_1500 {
    public static void main(String[] args) throws IOException {
        int Q = nextInt();
        for (int i = 0; i < Q; i++) {
            long N = nextLong(), A = nextLong(), B = nextLong();
            long totalCost = 0;
            String R = nextString();
            totalCost += N * A;
            totalCost += (N + 1) * B;
            boolean up1 = false;
            boolean up2 = false;
            long[] min = {totalCost, totalCost};
            for (int j = 0; j < N-1; j++)
            {
                int num = Integer.parseInt(String.valueOf(R.charAt(j)));
                if (num == 0)
                {
                    if (up1)
                    {
                        min[0] += A;
                        up1 = false;
                    }
                    if (up2)
                    {
                        min[1] += B;
                    }
                } else {
                    if (up1)
                    {
                        min[0] += B;
                    } else {
                        min[0] += A + B + B;
                        up1 = true;
                    }
                    if (up2)
                    {
                        min[1] += B;
                    } else {
                        min[1] += A + B + B;
                        up2 = true;
                    }
                }
                if (up1 && up2)
                {
                    min[0] = Long.min(min[0], min[1]);
                    min[1] = Long.min(min[0], min[1]);
                }
            }
            min[1] += A;
            if (up1)
            {
                min[0] += A;
            }
            System.out.println(Long.min(min[0], min[1]));
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
