//Works

import java.util.*;
import java.io.*;


public class ProblemD {
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        int current = 1;
        boolean good = true;
        for (int i = 0; i < N; i++)
        {
            int num = Integer.parseInt(in.readLine());
            for (int j = current; j < num; j++)
            {
                System.out.println(j);
                good = false;
            }
            current = num+1;
        }
        if (good)
        {
           System.out.println("good job");
        }
    }
}
