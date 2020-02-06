import java.io.*;
import java.util.*;

public class ProblemE {
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        long N = Long.parseLong(in.readLine());
        StringBuilder output = new StringBuilder();
        Set<Long> values = new HashSet<>();
        long top = (long) Math.sqrt(N);
        for (long i = 1; i <= top; i++)
        {
            if (N % i == 0)
            {
                values.add(i-1);
                values.add((N/i)-1);
            }
        }
        ArrayList<Long> sortMe = new ArrayList<>(values);
        Collections.sort(sortMe);
        for (long num : sortMe)
        {
            output.append(num).append(" ");
        }
        System.out.println(output.toString().strip());
    }
}