import java.util.*;
import java.io.*;

public class ProblemB {

    public static void main(String[] args)  throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        int min = Integer.MAX_VALUE;
        int[] days = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int currentBest = -1;
        for (int i = 0; i < N-2; i++)
        {
            int maxOfDay = Integer.max(days[i], days[i+2]);
            if (min > maxOfDay)
            {
                currentBest = i+1;
                min = maxOfDay;
            }
        }
        System.out.println(currentBest + " " + min);

    }
}
