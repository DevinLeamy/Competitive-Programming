import java.io.*;
import java.util.*;

public class ProblemC {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer line = new StringTokenizer(in.readLine());
        int N = Integer.parseInt(line.nextToken()); 
        int R = Integer.parseInt(line.nextToken()); 
        int eachRoom = N/R;
        int M = Integer.parseInt(in.readLine()); 
        line = new StringTokenizer(in.readLine());
        int[] teams = new int[M];
        for (int i = 0; i < M; i++)
        {
            teams[i] = Integer.parseInt(line.nextToken());
        }
        Arrays.sort(teams);
        boolean works = true;
        int current = M-1;
        int left = 0;
        int count = 0;
        while (works)
        {
            int sum = teams[current];
            current--;
            while (sum < R)
            {
                try {
                    if (teams[current] + sum <= R) {
                        sum += teams[current];
                        current--;
                    } else {
                        sum += teams[left];
                        left++;
                    }
                } catch (ArrayIndexOutOfBoundsException e) {
                    works = false;
                    break;
                }
            }
            if (sum > R)
            {
                works = false;
            } else if (sum == R)
            {
                count++;
            }
            if (current < left)
            {
                break;
            }
        }
        System.out.println(
                (works && count == eachRoom)? "Yes" : "No"
        );
    }
}
