import java.util.*;
import java.io.*;

public class CatchOverFlow_1600 {
    public static void main(String[] args) throws IOException
    {
        int N = nextInt();
        ArrayList<Long> factorQueue = new ArrayList<>();
        factorQueue.add(1L);
        long value = 0;
        long maxValue = 4294967295L;
        boolean good = true;
        for (int i = 0; i < N; i++)
        {
            String string = nextString();
            if (string.equals("add"))
            {
                long addToValue = factorQueue.get(factorQueue.size() - 1);
                if (addToValue != -1)
                {
                    value += addToValue;
                    if (value > maxValue)
                    {
                        good = false;
                        break;
                    }
                } else {
                    good = false;
                    break;
                }
            } else if (string.equals("end"))
            {
                factorQueue.remove(factorQueue.size() - 1);
            } else {
                long addToStack = Long.parseLong(nextString());
                if (addToStack * factorQueue.get(factorQueue.size() - 1) > maxValue || factorQueue.get(factorQueue.size() - 1) == -1)
                {
                    factorQueue.add(-1L);
                } else {
                    factorQueue.add(addToStack * factorQueue.get(factorQueue.size() - 1));
                }
            }
        }
        if (good)
        {
            System.out.println(value);
        } else {
            System.out.println("OVERFLOW!!!");
        }
    }

    //Template
    private static StringTokenizer line = new StringTokenizer("");
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    private static int nextInt() throws IOException
    {
        return Integer.parseInt(nextString());
    }
    private static long nextLong() throws IOException
    {
        return Long.parseLong(nextString());
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
    private static String[] nextStringArray() throws IOException
    {
        return in.readLine().split(" ");
    }
    private static int[] nextIntArray() throws IOException
    {
        return Arrays.stream(nextStringArray()).mapToInt(Integer::parseInt).toArray();
    }
}
