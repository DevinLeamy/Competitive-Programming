import java.util.*;
import java.io.*;

public class ProblemE {

    public static void main(String[] args)  throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        long S, C, K;
        StringTokenizer line = new StringTokenizer(in.readLine());
        S = Long.parseLong(line.nextToken());
        C = Long.parseLong(line.nextToken());
        K = Long.parseLong(line.nextToken());
        line = new StringTokenizer(in.readLine());
        ArrayList<Long> socks = new ArrayList<>();
        for (int i = 0; i < S; i++)
        {
            long D = Long.parseLong(line.nextToken());
            socks.add(D);
        }
        Collections.sort(socks);
        long current = 0;
        int count = 0;
        while (current != socks.size())
        {
            long min = socks.get((int)current);
            long inMachine = 1;
            current++;
            while (inMachine < C && current != socks.size())
            {
                long s = socks.get((int)current);
                if (Math.abs(min - s) > K)
                {
                    break;
                }
                current++;
                inMachine++;
            }
            count++;
        }
        System.out.println(count);
    }
}
