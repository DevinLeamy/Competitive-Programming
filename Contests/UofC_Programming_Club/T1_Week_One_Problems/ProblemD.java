import java.io.*;
import java.util.*;

public class ProblemD {
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        int counter = 0;
        StringTokenizer line = new StringTokenizer(in.readLine());
        //  1 2 3 -> T1:1, T2:2, T3:3
        for (int i = 0; i < N; i++)
        {
            int T = Integer.parseInt(line.nextToken());
            if (T < 0)
            {
                counter++;
            }
        }
        System.out.println(counter);
    }
}
