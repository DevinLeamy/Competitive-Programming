import java.util.*;
import java.io.*;

public class Candies_1400 {
    private static int getCandies(int num){
        return num/10;
    }
    private static void fill(int[] nums, int[] seq){
        nums[0] = seq[0];
        for (int i = 1; i < nums.length; i++){
            nums[i] = nums[i - 1] + seq[i];
        }
    }
    public static void main(String[] args) throws IOException {
        int N = nextInt();
        int[] seq = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] indexBySum = new int[N];
        fill(indexBySum, seq);
        int Q = nextInt();
        int sum;
        for (int i = 0; i < Q; i++){
            int S = nextInt();
            int E = nextInt();
            try {
                sum = indexBySum[E - 1] - indexBySum[S - 2];
            } catch (IndexOutOfBoundsException ioobe){
                sum = indexBySum[E - 1];
            }
            System.out.println(getCandies(sum));
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
}
