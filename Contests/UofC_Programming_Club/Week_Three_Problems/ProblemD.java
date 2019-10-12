import java.io.*;
import java.util.*;

public class ProblemD {
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        long sum = 0;
        for (int i = 0; i < N; i++)
        {
            String string = in.readLine();
            int pow = Integer.parseInt(String.valueOf(string.charAt(string.length()-1)));
            long res = (long) Math.pow(Integer.parseInt(string.substring(0, string.length()-1)), pow);
            sum += res;
        }
        System.out.println(sum);
    }
}
