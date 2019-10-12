import java.util.*;
import java.io.*;

public class ProblemD {
    public static void main(String[] args)  throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer line = new StringTokenizer(in.readLine());
        if (line.countTokens() == 1)
        {
            System.out.println((long) Math.pow(2, Integer.parseInt(line.nextToken()) + 1) - 1);
        } else {
            int H = Integer.parseInt(line.nextToken());
            String[] path = line.nextToken().split("");
            long current = (long) Math.pow(2, H+1) -1;
            long currentLayer = 1;
            long index = 1;
            for (String dir: path)
            {
                switch (dir)
                {
                    case "L":
                        current -= index;
                        index = 2*index;
                        current -= (currentLayer * 2 - index);
                        break;
                    case "R":
                        current -= index;
                        index = 2*index - 1;
                        current -= (currentLayer * 2 - (index));
                        break;
                }
                currentLayer *= 2;
            }
            System.out.println(current);
        }
    }
}
