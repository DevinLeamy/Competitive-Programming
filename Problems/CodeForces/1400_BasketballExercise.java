import java.util.*;
import java.io.*;

public class BasketballExercise_1400 {
    private static long solve(long N, long[] L1, long[] L2){
        long[] LB = {0, 0};
        for (int i = 0; i < N; i++){
            long H1 = L1[i];
            long H2 = L2[i];
            long hold1 = LB[0];
            long hold2 = LB[1];
            LB[0] = Long.max(hold1, hold2 + H1);
            LB[1] = Long.max(hold2, hold1 + H2);
        }
        return Long.max(LB[0], LB[1]);
    }
    public static void main(String[] args) throws IOException {
        long N = nextLong();
        long[] L1 = nextLongArray();
        long[] L2 = nextLongArray();
        System.out.println(solve(N, L1, L2));
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
    private static String[] nextStringArray() throws IOException
    {
        return in.readLine().split(" ");
    }
    private static long[] nextLongArray() throws IOException
    {
        return Arrays.stream(nextStringArray()).mapToLong(Long::parseLong).toArray();
    }
}
