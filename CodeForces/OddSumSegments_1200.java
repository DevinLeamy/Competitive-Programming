import java.util.*;
import java.io.*;

public class OddSumSegments_1200 {
    public static void main(String[] args) throws IOException {
        int Q = nextInt();
        for (int i = 0; i < Q; i++)
        {
            int N = nextInt();
            int K = nextInt();
            long sum = 0;
            boolean isOdd = false;
            StringBuilder output = new StringBuilder();
            for (int j = 0; j < N; j++)
            {
                int A = nextInt();
                sum = (sum + A) % 2;
                if (j == N - 1)
                {
                    K--;
                    output.append(N);
                    output.append(" ");
                    if (sum == 1)
                    {
                        isOdd = true;
                    }
                } else if (sum == 1 && K > 1)
                {
                    K--;
                    output.append(j + 1);
                    output.append(" ");
                    sum = 0;
                }
            }
            if (K == 0 && isOdd)
            {

                print("YES");
                print(output.toString());
            } else {
                print("NO");
            }
        }
    }
    private static StringTokenizer line = new StringTokenizer("");
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    private static int nextInt() throws IOException
    {
        return Integer.parseInt(nextString());
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
    private static void print(String value)
    {
        System.out.println(value);
    }
}
