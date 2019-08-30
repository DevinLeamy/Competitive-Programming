import java.util.*;
import java.io.*;

public class MakeProductEqualOne {
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        int currentP = 1;
        long cost = 0;
        StringTokenizer line = new StringTokenizer(in.readLine());
        boolean hasZero = false;
        for (int i = 0; i < N; i++)
        {
            int num = Integer.parseInt(line.nextToken());
            if (num == 0)
            {
                cost++;
                hasZero = true;
            } else if (num <= -1)
            {
                cost += (Math.abs(num + 1));
                currentP *= -1;
            } else {
                cost += (num - 1);
            }
        }
        if (currentP < 0 && !hasZero)
        {
            cost += 2;
        }
        System.out.println(cost);
    }
}
