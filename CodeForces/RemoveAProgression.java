import java.util.*;
import java.io.*;

public class RemoveAProgression {
    public static void main(String[] args) throws IOException
    {
        int Q = nextInt();
        for (int i = 0; i < Q; i++)
        {
            int N = nextInt();
            int X = nextInt();
            System.out.println(X * 2);
        }
    }

    //Template
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
        } else
            {
            line = new StringTokenizer(in.readLine());
            return line.nextToken();
        }
    }
}

