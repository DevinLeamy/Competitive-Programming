import java.util.*;
import java.io.*;


public class Problem1B {
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int winner = -1;
        int max = -1;
        for (int i = 0; i < 5; i++)
        {
            StringTokenizer line = new StringTokenizer(in.readLine());
            int sum = 0;
            for (int j = 0; j < 4; j++)
            {
                sum += Integer.parseInt(line.nextToken());
            }
            if (sum > max)
            {
                max = sum;
                winner = i+1;
            }
        }
        System.out.println(winner + " " + max);
    }
}
