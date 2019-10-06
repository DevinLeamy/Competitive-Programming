//Works

import java.util.*;
import java.io.*;


public class ProblemJ {
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException
    {
        long N = Long.parseLong(in.readLine());
        StringTokenizer line = new StringTokenizer(in.readLine());
        double[] values = new double[(int)N];
        double maxAv = 0;
        double[] currentAvg = new double[2];
        for (int i = 0; i < N; i++)
        {
            double value = Double.parseDouble(line.nextToken());
            currentAvg[0] += value;
            currentAvg[1] += 1;
            maxAv = Double.max(maxAv, currentAvg[0]/currentAvg[1]);
            values[i] = value;
        }
        currentAvg = new double[2];
        for (long i = N-1; i >= 0; i--)
        {
            double value = values[(int)i];
            currentAvg[0] += value;
            currentAvg[1] += 1;
            maxAv = Double.max(maxAv, currentAvg[0]/currentAvg[1]);
        }
        System.out.println(maxAv);

    }
}
