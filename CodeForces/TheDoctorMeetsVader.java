import java.util.*;
import java.io.*;

public class TheDoctorMeetsVader {
    public static void main(String[] args) throws IOException {
        StringBuilder output = new StringBuilder();
        int S = nextInt(); int B = nextInt();
        StringTokenizer A = new StringTokenizer(in.readLine());
        HashMap<Integer, Long> sums = new HashMap<>();
        TreeSet<Integer> defense = new TreeSet<>();

        for (int i = 0; i < B; i++)
        {
            int D = nextInt(); int G = nextInt();
            defense.add(D);
            if (sums.containsKey(D))
            {
                sums.replace(D, sums.get(D) + G);
                continue;
            }
            sums.put(D, (long) G);
        }

        Iterator<Integer> hold = defense.iterator();
        long sum = sums.get(hold.next());

        while (hold.hasNext())
        {
            int key = hold.next();
            sum = sums.get(key) + sum;
            sums.replace(key, sum);
        }

        while (A.hasMoreTokens())
        {
            try
            {
                long value = sums.get(defense.floor(Integer.parseInt(A.nextToken())));
                output.append(value);
                output.append(" ");
            } catch (NullPointerException npe) {
                output.append(0);
                output.append(" ");
            }
        }

        System.out.println(output.toString());
    }
    private static StringTokenizer line = new StringTokenizer("");
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    private static int nextInt() throws IOException
    {
        return Integer.parseInt(nextString());
    }
    private static long nextLong() throws IOException
    {
        return Long.parseLong(nextString());
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
