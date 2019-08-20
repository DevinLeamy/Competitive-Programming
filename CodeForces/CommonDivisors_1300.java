import java.util.*;
import java.io.*;

public class CommonDivisors_1300 {
    private static long getDivisors(long num)
    {
        long top = (long) Math.sqrt(num);
        List<Long> divisors = new ArrayList<>();
        for (long i = 1; i <= top; i++)
        {
            if (num % i == 0)
            {
                divisors.add(i);
                if (num / i != i)
                {
                    divisors.add(num/i);
                }
            }

        }
        return divisors.size();
    }
    private static long gcd(long a, long b)
    {
        while (b > 0)
        {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    private static long solve(int N, long[] nums){
        if (N == 1)
        {
            return getDivisors(nums[0]);
        }
        long gcd = gcd(nums[0], nums[1]);
        for (int i = 2; i < N; i++)
        {
            gcd = gcd(gcd, nums[i]);
        }
        return getDivisors(gcd);
    }
    public static void main(String[] args) throws IOException {
        int N = nextInt();
        long[] nums = nextLongArray();
        System.out.println(solve(N, nums));
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
    private static String[] nextStringArray() throws IOException
    {
        return in.readLine().split(" ");
    }
    private static long[] nextLongArray() throws IOException
    {
        return Arrays.stream(nextStringArray()).mapToLong(Long::parseLong).toArray();
    }
}
