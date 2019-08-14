import java.util.*;
import java.io.*;

public class EqualRectangles {
    private static boolean solve(int N, int[] sticks){
        int created = 0;
        int topIndex = 0;
        int bottomIndex = N - 1;
        long A = sticks[0] * sticks[N - 1];
        while (created < N){
            int stickOne = sticks[topIndex];
            int stickTwo = sticks[bottomIndex];
            if (stickOne != sticks[topIndex + 1] || stickTwo != sticks[bottomIndex - 1]){
                return false;
            }
            long area = sticks[topIndex] * sticks[bottomIndex];
            if (area != A){
                return false;
            }
            created += 4;
            topIndex += 2;
            bottomIndex -= 2;

        }
        return created == N;
    }
    public static void main(String[] args) throws IOException {
        int Q = nextInt();
        for (int i = 0; i < Q; i++){
            int N = nextInt();
            int[] sticks = nextIntArray();
            Arrays.sort(sticks);
            System.out.println(
                    solve(N * 4, sticks)? "YES": "NO"
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
    private static long[] nextLongArray() throws IOException
    {
        return Arrays.stream(nextStringArray()).mapToLong(Long::parseLong).toArray();
    }
}
