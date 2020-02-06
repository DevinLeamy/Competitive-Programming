import java.util.*;
import java.io.*;


public class Problem1E {
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int[] start = new int[12];
        String[] days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        start[0] = 3;
        start[1] = 6;
        start[2] = 6;
        start[3] = 2;
        start[4] = 4;
        start[5] = 0;
        start[6] = 2;
        start[7] = 5;
        start[8] = 1;
        start[9] = 3;
        start[10] = 6;
        start[11] = 1;
        StringTokenizer line = new StringTokenizer(in.readLine());
        int day = Integer.parseInt(line.nextToken());
        int M = Integer.parseInt(line.nextToken());
        int currentDay = start[M-1];
        for (int i = 0; i < day; i++)
        {
            currentDay++;
            currentDay = currentDay % 7;
        }
        currentDay--;
        if (currentDay < 0)
        {
            System.out.println(days[6]);
        } else {
            System.out.println(days[currentDay]);
        }
    }
}
