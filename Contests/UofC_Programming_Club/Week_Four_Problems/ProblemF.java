import java.util.*;
import java.io.*;

public class ProblemF {

    public static void main(String[] args)  throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for (int i = 0; i < T; i++)
        {
            StringTokenizer line = new StringTokenizer(in.readLine());
            long l = Long.parseLong(line.nextToken());
            long n = Long.parseLong(line.nextToken());
            long earliest = Long.MIN_VALUE;
            long latest = Long.MIN_VALUE;
            if (n == 0)
            {
                continue;
            }
            line = new StringTokenizer(in.readLine());
            for (int j = 0; j < n; j++)
            {
                try {
                    long pos = Long.parseLong(line.nextToken());
                    earliest = Long.max(earliest, Long.min(l - pos, pos));
                    latest = Long.max(latest, Long.max(l - pos, pos));
                } catch (NoSuchElementException e)
                {
                    line = new StringTokenizer(in.readLine());
                    j--;
                }
            }
            System.out.println(earliest + " " + latest);
        }
    }
}
