import java.io.*;
import java.util.*;

public class ProblemB {
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        int count = 0;
        StringTokenizer line = new StringTokenizer(in.readLine());
        for (int i = 0; i < N; i++)
        {
            int V = Integer.parseInt(line.nextToken());
            if (V < 0)
            {
                count += Math.abs(V);
            }
        }
        System.out.println(count);
    }
}
