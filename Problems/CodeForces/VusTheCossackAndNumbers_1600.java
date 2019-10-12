import java.util.*;
import java.io.*;

import java.util.*;
import java.io.*;

public class VusTheCossackAndNumbers_1600 {
    public static void main(String[] args) throws IOException {
        int N = nextInt();
        long TS = 0;
        double[] values = new double[N];
        for (int i = 0; i < N; i++)
        {
            double V = Double.parseDouble(nextString());
            values[i] = V;
            TS += (int) V;
        }
        for (double value: values)
        {
            if (value - (int) value == 0 || TS == 0)
            {
                System.out.println((int) value);
            } else {
                if (TS > 0) {
                    System.out.println((value >= 0) ? (int) value : ((int) value) - 1);
                    TS += (value >= 0)? 0 : -1;
                    continue;
                }
                System.out.println( (value >= 0)? ((int) value) + 1: (int) value );
                TS += (value >= 0)? 1 : 0;
            }
        }
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
}
