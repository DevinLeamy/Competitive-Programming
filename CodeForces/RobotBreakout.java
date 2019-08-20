import java.util.*;
import java.io.*;

public class RobotBreakout {
    public static void main(String[] args) throws IOException {
        int T = nextInt();
        for (int i = 0; i < T; i++)
        {
            int N = nextInt();
            int[] works = {-100000, 100000, 100000, -100000}; //left, up, right, down
            boolean good = true;
            for (int j = 0; j < N; j++)
            {
                int x = nextInt(); int y = nextInt();
                int[] range = works.clone();
                int left = nextInt(); int up = nextInt(); int right = nextInt(); int down = nextInt();
                if (left == 0)
                {
                    range[0] = Integer.max(range[0], x);
                }
                if (up == 0)
                {
                    range[1] = Integer.min(range[1], y);
                }
                if (right == 0)
                {
                    range[2] = Integer.min(range[2], x);
                }
                if (down == 0)
                {
                    range[3] = Integer.max(range[3], y);
                }
                works = range.clone();
                if (works[2] < works[0] || works[1] < works[3])
                {
                    good = false;
                }
            }
            if (good)
            {
                System.out.println(1 + " " + works[2] + " " + works[1]);
                continue;
            }
            System.out.println(0);
        }
    }
    private static StringTokenizer line = new StringTokenizer("");
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    private static int nextInt() throws IOException
    {
        return Integer.parseInt(nextString());
    }
    private static String nextString() throws IOException
    {
        if (line.hasMoreTokens())
        {
            return line.nextToken();
        } else {
            line = new StringTokenizer(in.readLine());
            return line.nextToken();
        }
    }
}
