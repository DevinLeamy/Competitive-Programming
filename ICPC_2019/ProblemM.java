//Works

import java.util.*;
import java.io.*;


public class ProblemM {
    private static double calculateHypothenus(double base, double height)
    {
        double a = base * base;
        double b = height * height;
        return Math.sqrt(a + b);
    }
    private static double getLengthOfCord(double p, double pole1, double pole2, double r, double w)
    {
        return calculateHypothenus(p, pole1-r) + calculateHypothenus(w-p, pole2 - r);
    }
    private static double getMax(double left, double right, double precision, double p1, double p2, double r, double w)
    {
        if (Math.abs(right - left) < precision)
        {
            return (left + right)/2;
        }
        double m1 = (2*left + right)/3;
        double m2 = (left + 2*right)/3;
        if (getLengthOfCord(m1, p1, p2, r, w) > getLengthOfCord(m2, p1, p2, r, w))
        {
            return getMax(m1, right, precision, p1, p2, r, w);
        } else {
            return getMax(left, m2, precision, p1, p2, r, w);
        }
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine()), w, g, h, r;
        StringTokenizer line;
        for (int i = 0; i < N; i++)
        {
            line = new StringTokenizer(in.readLine());
            w = Integer.parseInt(line.nextToken());
            g = Integer.parseInt(line.nextToken());
            h = Integer.parseInt(line.nextToken());
            r = Integer.parseInt(line.nextToken());
            StringBuilder output = new StringBuilder();
            if (g == h)
            {
                output.append(w).append(" ");
            } else {
                output.append(calculateHypothenus(w, Math.abs(g - h))).append(" ");
            }
            double start = 0.0000001;
            double end = w-0.00000001;
            output.append(getLengthOfCord(getMax(start, end, start, h, g, r, w), h, g, r, w)).append(" ");
            System.out.println(output.toString().strip());
        }
    }
}
