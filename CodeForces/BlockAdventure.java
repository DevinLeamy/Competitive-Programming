import java.util.*;
import java.io.*;

public class BlockAdventure {
    public static void main(String[] args) throws IOException {
        int T = nextInt();
        for (int i = 0 ; i < T; i++)
        {
            boolean good = true;
            int N = nextInt(); int M = nextInt(); int K = nextInt();
            int[] array = nextIntArray();
            int current = array[0];
            for (int j = 1; j < N; j++)
            {
                int next = array[j];
                int add = (K - next + current);
                M += (add > current)? current: add;
                if (M < 0)
                {
                    good = false;
                    break;
                }
                current = next;
            }
            System.out.println(
                    (good)? "YES": "NO"
            );
        }
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
