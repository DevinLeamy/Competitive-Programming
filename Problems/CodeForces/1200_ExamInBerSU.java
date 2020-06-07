import java.util.*;
import java.io.*;

public class ExamInBerSU_1200 {
    private static void insert(int num, List<Integer> sortedArrayList)
    {
        int index = sortedArrayList.size() - 1;
        while (true)
        {
            try {
                if (sortedArrayList.get(index) <= num) {
                    sortedArrayList.add(index + 1, num);
                    break;
                }
                index--;
            } catch (IndexOutOfBoundsException ioobe)
            {
                sortedArrayList.add(0, num);
                break;
            }
        }
    }
    public static void main(String[] args) throws IOException
    {
        int N = nextInt(); int M = nextInt();
        int[] sum = new int[N];
        int first = nextInt();
        List<Integer> biggest = new ArrayList<>();
        sum[0] = first;
        biggest.add(first);
        int index;
        int num;
        int T;
        StringBuilder output = new StringBuilder();
        for (int i = 0; i < N; i++)
        {
            if (i == 0)
            {
                output.append(0);
                output.append(" ");
                continue;
            }
            T = nextInt();
            num = T + sum[i - 1];
            sum[i] = num;
            index = biggest.size() - 1;
            int counter = 0;
            while (num > M)
            {
                num -= biggest.get(index);
                index--;
                counter++;
            }
            output.append(counter);
            output.append(" ");
            insert(T, biggest);
        }
        System.out.println(output.toString());
    }
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
    private static long[] nextLongArray() throws IOException
    {
        return Arrays.stream(nextStringArray()).mapToLong(Long::parseLong).toArray();
    }
}
