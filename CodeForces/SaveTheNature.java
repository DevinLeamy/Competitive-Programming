import java.util.*;
import java.io.*;

public class SaveTheNature {
    private static void quickSort(long[] list, int left, int right)
    {
        if (left < right)
        {
            int pivot = partition(list, left, right);
            quickSort(list, left, pivot-1);
            quickSort(list, pivot+1, right);
        }
    }
    private static int partition(long[] list, int left, int right)
    {
        long pivotElement = list[left];
        int leftBound = left;
        long temp;

        while (left < right)
        {
            while (list[left] <= pivotElement && left < right)
            {
                left++;
            }
            while (list[right] > pivotElement)
            {
                right--;
            }
            if (left < right)
            {
                temp = list[left];
                list[left] = list[right];
                list[right] = temp;
            }
        }
        list[leftBound] = list[right];
        list[right] = pivotElement;
        return right;
    }
    private static long gcd(long a, long b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    private static long lcm(long a, long b)
    {
        return (a*b)/gcd(a, b);
    }
    private static boolean isEnough(int count, int A, int B, long[] tickets, int X, int Y, long LCM, long K)
    {
        try
        {
            int numLCM = (int) (count / LCM);
            int numA = (count / A) - numLCM;
            int numB = (count / B) - numLCM;
            long total = 0;
            int current = tickets.length - 1;
            for (int i = 0; i < numLCM; i++)
            {
                total += ((X + Y) * tickets[current])/100;
                current--;
            }
            if (X >= Y)
            {
                for (int i = 0; i < numA; i++)
                {
                    total += ((X) * tickets[current])/100;
                    current--;
                }
                for (int i = 0; i < numB; i++)
                {
                    total += ((Y * tickets[current]))/100;
                    current--;
                }
            } else {
                for (int i = 0; i < numB; i++)
                {
                    total += ((Y * tickets[current]))/100;
                    current--;
                }
                for (int i = 0; i < numA; i++)
                {
                    total += ((X) * tickets[current])/100;
                    current--;
                }
            }
            return (total >= K);
        } catch (ArrayIndexOutOfBoundsException e)
        {
            return false;
        }
    }
    private static int binarySearch(int l, int r, int A, int B, int X, int Y, long K, long[] tickets, long LCM)
    {
        int mid = (l + r)/2;
        if (r - l > 1)
        {
            if (isEnough(mid, A, B, tickets, X, Y, LCM, K)) {
                return binarySearch(l, mid, A, B, X, Y, K, tickets, LCM);
            } else {
                return binarySearch(mid, r, A, B, X, Y, K, tickets, LCM);
            }
        } else {
            if (r > tickets.length)
            {
                return -1;
            }
            return r;
        }
    }
    public static void main(String[] args) throws IOException {
        int Q = nextInt();
        for (int i = 0; i < Q; i++)
        {
            int N = nextInt();
            long[] tickets = new long[N];
            for (int j = 0; j < N; j++)
            {
                tickets[j] = nextLong();
            }
            int X = nextInt();
            int A = nextInt();
            int Y = nextInt();
            int B = nextInt();
            long LCM = lcm(A, B);
            long K = nextLong();
            quickSort(tickets, 0, tickets.length-1);
            System.out.println(binarySearch(0, N+1, A, B, X, Y, K, tickets, LCM));
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