import java.io.*;
import java.util.*;

public class ProblemF {
    private static final double EACHTILE = ((60d * Math.PI)/28d)/15d;
    private static final String ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1\'";
    private static double getTime(String A)
    {
        String CL = String.valueOf(A.charAt(0));
        double T = A.length();
        for (int i = 1; i < A.length(); i++)
        {
            String N = String.valueOf(A.charAt(i));
            if (N.equals(" "))
            {
                N = "1";
            }
            int D1 = Math.abs(ALPHABET.indexOf(CL)- ALPHABET.indexOf(N));
            if (D1 <= 14)
            {
                T += D1 * EACHTILE;
            } else {
                T += (28-D1) * EACHTILE;
            }
            CL = N;
        }
        return T;
    }
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        for (int i = 0; i < N; i++)
        {
            String A = in.readLine();
            System.out.println(getTime(A));
        }
    }
}
