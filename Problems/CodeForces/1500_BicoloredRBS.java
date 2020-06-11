import java.util.*;
import java.io.*;

public class BicoloredRBS_1500 {
    public static void main(String[] args) throws IOException
    {
        int N = nextInt();
        String seq = nextString();
        int R = 0;
        int B = 0;
        StringBuilder output = new StringBuilder();
        for (int i = 0; i < N; i++)
        {
            char character = seq.charAt(i);
            if (character == '(')
            {
                if (R <= B)
                {
                    R++;
                    output.append(1);
                    continue;
                }
                B++;
                output.append(0);
            } else {
                if (R >= B)
                {
                    R--;
                    output.append(1);
                    continue;
                }
                B--;
                output.append(0);
            }
        }
        System.out.println(output);
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
}
