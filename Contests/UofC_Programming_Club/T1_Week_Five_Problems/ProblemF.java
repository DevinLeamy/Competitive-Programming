import java.io.*;
import java.util.*;

public class ProblemF {
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        long N = Long.parseLong(in.readLine());
        long top = (long) Math.sqrt(N);
        int count = 0;
        while (N % 2 == 0)
        {
            N = N/2;
            count++;
        }
        for (long i = 3; i <= top; i += 2)
        {
            while (N % i == 0)
            {
                N = N/i;
                count++;
            }
        }
        if (N > 1)
        {
            count++;
        }
        System.out.println(count);
    }
}
