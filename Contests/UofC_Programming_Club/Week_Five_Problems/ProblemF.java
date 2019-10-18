import java.io.*;
import java.util.*;

public class ProblemF {
    private static ArrayList<Long> primesFactor(long N)
    {
        ArrayList<Long> primes = new ArrayList<>();
        primes.add(2l);
        for (int i = 3; i <= N; i+=2)
        {
            boolean prime = true;
            for (long num : primes)
            {
                if (i % num == 0)
                {
                    prime = false;
                    break;
                }
            }
            if (prime)
            {
                primes.add((long)i);
            }
        }
        return primes;
    }
    private static boolean isPrime(ArrayList<Long> PF, long N)
    {
        for (long num : PF)
        {
            if (N % num == 0)
            {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        long N = Long.parseLong(in.readLine());
        long top = (long) Math.sqrt(N);
        int count = 0;
        while (N % 2 == 0)
        {
            N = N/2;
            count++;
        }
        for (long i = 3; i <= top; i += 2)
        {
            while (N % i == 0)
            {
                N = N/i;
                count++;
            }
        }
        if (N > 1)
        {
            count++;
        }
        System.out.println(count);
    }
}