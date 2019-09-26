import java.util.*;
import java.io.*;


public class Problem1C {
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer line = new StringTokenizer(in.readLine());
        int R = Integer.parseInt(line.nextToken());
        int N = Integer.parseInt(line.nextToken());
        boolean[] isTaken = new boolean[R];
        for (int i = 0; i < N; i++)
        {
            isTaken[Integer.parseInt(in.readLine()) - 1] = true;
        }
        boolean found = false;
        for (int i = 0; i < R; i++)
        {
            if (!isTaken[i])
            {
                System.out.println(i+1);
                found = true;
                break;
            }
        }
        if (!found)
        {
            System.out.println("too late");
        }

    }
}
