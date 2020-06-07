import java.util.*;
import java.io.*;

public class MaximumMedian_1400 {
    private static int binarySearch(int median, int[] array, int K){
        for (int i = array.length - 1; i > array.length / 2; i--){
            int num = array[i];
            if (num < median){
                K -= (median - num);
            }
            if (K < 0){
                return -1;
            }
        }
        return 0;
    }
    public static void main(String[] args) throws IOException {
        int N = nextInt(); int K = nextInt();
        int[] seq = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(seq);
        int CM = seq[N/2];
        if (N > 1){
            int bottom = 0;
            int top = K;
            int current = (bottom + top)/2;
            while (true)
            {
                int returnValue = binarySearch(current + CM, seq, K - current);
                if (returnValue == -1){
                    top = current - 1;
                    current = (top + bottom)/2;
                } else {
                    if (binarySearch(current + CM+1, seq,  K - current-1) == -1){
                        System.out.println(current + CM);
                        break;
                    } else {
                        bottom = current + 1;
                        current = (bottom + top)/2;
                    }
                }
            }
        } else {
            System.out.println(CM + K);
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
