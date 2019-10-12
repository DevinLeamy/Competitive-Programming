import java.util.*;
import java.io.*;

public class RopeWalkers_900{
    public static void main(String[] args) throws IOException {
        int[] walkers = {nextInt(), nextInt(), nextInt()};
        int D = nextInt();
        Arrays.sort(walkers);
        int output = 0;
        for (int i = 0; i < 2; i++){
            int d1 = walkers[i];
            int d2 = walkers[i + 1];
            if (d2 - d1 < D){
                output += (D - (d2 - d1));
            }
        }
        System.out.println(output);
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
