import java.math.BigDecimal;
import java.math.MathContext;
import java.util.*;
import java.io.*;

public class Problem1H {
    private static BigDecimal PHI;
    private static BigDecimal phi;
    private static BigDecimal squr5;
    private static long calculateFib(int N)
    {
        BigDecimal PHID = new BigDecimal(PHI.toString());
        PHID = PHID.pow(N, new MathContext(30));
        BigDecimal phiD = new BigDecimal(phi.toString());
        phiD = phiD.pow(N, new MathContext(30));
        PHID = PHID.subtract(phiD);
        PHID = PHID.divide(squr5, new MathContext(30));
        return Long.parseLong(PHID.toBigInteger().toString());
    }
    private static void setPHI()
    {
        squr5 = new BigDecimal(5);
        squr5 = squr5.sqrt(new MathContext(30));
        PHI = new BigDecimal(1);
        PHI = PHI.add(squr5);
        PHI = PHI.divide(new BigDecimal("2"), new MathContext(30));
        phi = new BigDecimal(1);
        phi = phi.subtract(squr5);
        phi = phi.divide(new BigDecimal("2"), new MathContext(30));
    }
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer line = new StringTokenizer(in.readLine());
        int N = (int) Long.min(88, Long.parseLong(line.nextToken()));
        long K = Long.parseLong(line.nextToken());
        setPHI();
        while (K != 1)
        {
            long front = calculateFib(N - 2);
            if (K > front)
            {
                N--;
                K -= front;
            } else {
                N -= 2;
            }
        }
        if (N % 2 == 0)
        {
            System.out.println("A");
        } else {
            System.out.println("N");
        }
    }
}