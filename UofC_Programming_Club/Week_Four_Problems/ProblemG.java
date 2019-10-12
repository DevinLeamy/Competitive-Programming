import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class ProblemG {
    private static BigInteger factorial(int N)
    {
        BigInteger output = new BigInteger("1");
        for (int i = 1; i <= N; i++)
        {
            output = output.multiply(new BigInteger(String.valueOf(i)));
        }
        return output;
    }
    private static BigInteger getCount(String value)
    {
        HashMap<String, Integer> map = new HashMap<>();
        for (int i = 0; i < value.length(); i++)
        {
            String character = String.valueOf(value.charAt(i));
            if (map.containsKey(character))
            {
                map.replace(character,  map.get(character)+1);
            } else {
                map.put(character, 1);
            }
        }
        BigInteger output = factorial(value.length());
        BigInteger divide = new BigInteger("1");
        for (String key : map.keySet())
        {
            divide = divide.multiply(factorial(map.get(key)));
        }
        return output.divide(divide);
    }

    public static void main(String[] args)  throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        boolean foundText = false;
        while (true)
        {
            if (in.ready())
            {
                String A = in.readLine();
                System.out.println(getCount(A));
                foundText = true;
            } else {
                if (foundText)
                {
                    break;
                }
            }
        }
    }
}
