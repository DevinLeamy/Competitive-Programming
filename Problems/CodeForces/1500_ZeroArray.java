import java.util.*;
import java.io.*;

public class ZeroArray_1500 {
    public static void main(String[] args) throws IOException {
        int N = nextInt();
        long largest = -1;
        long sum = 0;
        for (int i = 0; i< N; i++){
            long num = nextInt();
            if (num > largest){
                largest = num;
            }
            sum += num;
        }
        System.out.println(
                (sum % 2 == 0 && largest <= (sum - largest))? "YES":"NO"
        );
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
