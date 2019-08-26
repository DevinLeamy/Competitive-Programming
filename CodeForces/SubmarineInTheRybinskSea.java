import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class SubmarineInTheRybinskSea {
    public static void main(String[] args) throws IOException
    {
        int N = nextInt();
        long sum = 0;
        long mod = 998244353;

        for (int i = 0; i < N; i++)
        {
            String num = nextString();
            StringBuilder newNum = new StringBuilder();
            for (int j = 0; j < num.length(); j++)
            {
                newNum.append(num.charAt(j));
                newNum.append(num.charAt(j));
            }
            BigInteger addme = new BigInteger(newNum.toString());
            addme = addme.mod(new BigInteger(String.valueOf(mod)));
            sum += Long.parseLong(addme.toString());
            sum %= mod;
        }
        sum *= N;
        sum %= mod;
        println(String.valueOf(sum));
    }

    //Template
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
    private static void println(String value)
    {
        System.out.println(value);
    }
}
