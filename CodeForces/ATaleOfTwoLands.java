import java.util.*;
import java.io.*;

public class ATaleOfTwoLands {
    private static void quickSort(long[] list, long left, long right)
    {
        if (left < right)
        {
            long pivot = partition(list, left, right);
            quickSort(list, left, pivot-1);
            quickSort(list, pivot+1, right);
        }
    }
    private static long partition(long[] list, long left, long right)
    {
        long pivotElement = list[(int) left];
        long leftBound = left, rightBound = right;
        long temp;

        while (left < right)
        {
            while (list[(int)left] <= pivotElement && left < right)
            {
                left++;
            }
            while (list[(int)right] > pivotElement)
            {
                right--;
            }
            if (left < right)
            {
                temp = list[(int) left];
                list[(int)left] = list[(int)right];
                list[(int)right] = temp;
            }
        }
        list[(int)leftBound] = list[(int)right];
        list[(int)right] = pivotElement;
        return right;
    }

    private static int binarySearch(long arr[], int l, int r, long x)
    {
        if (r >= l)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
            {
                while (arr[mid] == x && mid < arr.length)
                {
                    mid++;
                }
                return mid - 1;
            }
            if (arr[mid] > x)
            {
                return binarySearch(arr, l, mid - 1, x);
            }
            return binarySearch(arr, mid + 1, r, x);
        }
        return -1;
    }
    public static void main(String[] args) throws IOException {
        int N = nextInt();
        long E;
        long[] values = new long[N+1];
        TreeSet<Long> nums = new TreeSet<>();

        for (int i = 0; i < N; i++)
        {
            E = Math.abs(nextLong());
            values[i] = E;
            nums.add(E);
        }
        quickSort(values, 0, N-1);
        long total = 0;
        for (int i = 0; i < N-1; i++)
        {
            total += binarySearch(values, i, N-1, nums.floor(values[i]*2)) - i;
        }
        System.out.println(total);
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