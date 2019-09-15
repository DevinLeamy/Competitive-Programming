import java.util.*;
import java.io.*;

public class LostNumbers {
    public static StringBuilder output = new StringBuilder();
    private static boolean contains(int[] list, int value)
    {
        for (int num : list)
        {
            if (num == value)
            {
                return true;
            }
        }
        return false;
    }
    private static void getCommonFactor(int[] values, int lastResult, int newResult, boolean isFirst, boolean[] isTaken, boolean isLast)
    {
        for (int i = 0; i < values.length; i++)
        {
            if (!isTaken[i])
            {
                if (lastResult % values[i] == 0 && newResult % values[i] == 0)
                {
                    if (contains(values, lastResult / values[i]) && contains(values, newResult / values[i]))
                    {
                        if (isFirst)
                        {
                            output.append(lastResult / values[i]).append(" ");
                            for (int j = 0; j < 6; j++)
                            {
                                if (values[j] == lastResult/values[i])
                                {
                                    isTaken[j] = true;
                                }
                            }
                        }
                        output.append(values[i]).append(" ");
                        isTaken[i] = true;
                        if (isLast)
                        {
                            output.append(newResult / values[i]).append(" ");
                            for (int j = 0; j < 6; j++)
                            {
                                if (values[j] == newResult/values[i])
                                {
                                    isTaken[j] = true;
                                }
                            }
                        }
                        return;
                    }
                }
            }
        }
    }
    public static void main(String[] args) throws IOException
    {
        output.append("! ");
        int[] values = {4, 16, 15, 8, 23, 42};
        boolean[] isTaken = new boolean[6];

        int lastResult = -1;
        boolean isFirst = true;
        boolean isLast = false;
        for (int i = 1; i < 5; i++)
        {
            if (i == 4)
            {
                isLast = true;
            }
            System.out.println("? " + i + " " + (i+1));
            System.out.flush();
            int newResult = nextInt();
            if (lastResult == -1)
            {
                lastResult = newResult;
            } else {
                getCommonFactor(values, lastResult, newResult, isFirst, isTaken, isLast);
                isFirst = false;
                lastResult = newResult;
            }
        }
        for (int i = 0; i < 6; i++)
        {
            if (!isTaken[i])
            {
                output.append(values[i]).append(" ");
                break;
            }
        }
        System.out.println(output.toString());
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
