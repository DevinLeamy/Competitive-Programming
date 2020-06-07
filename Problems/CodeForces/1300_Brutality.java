import java.util.*;
import java.io.*;

public class Brutality_1300 {
    public static void main(String[] args) throws IOException
    {
        int N = nextInt(); int K = nextInt();
        long[] A = Arrays.stream(nextStringArray()).mapToLong(Long::parseLong).toArray();
        String seq = nextString();
        seq += "-";
        char currentLetter = '-';
        List<Long> inMax = new ArrayList<>();
        long max = 0;
        for (int i = 0; i < seq.length(); i++)
        {
            char character = seq.charAt(i);
            if (character != currentLetter)
            {
                if (inMax.size() > K)
                {
                    Collections.sort(inMax);
                    for (int j = inMax.size() - 1; j >= (inMax.size() - K); j--)
                    {
                        max += inMax.get(j);
                    }
                } else {
                    for (long num : inMax)
                    {
                        max += num;
                    }
                }
                if (character == '-')
                {
                    break;
                }
                inMax = new ArrayList<>();
                long num = A[i];
                inMax.add(num);
                currentLetter = character;
            } else {
                inMax.add(A[i]);
            }
        }
        System.out.println(max);
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
