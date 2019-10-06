import java.util.*;
import java.io.*;


public class ProblemC {
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int P, D, d, a, b;
        StringTokenizer line = new StringTokenizer(in.readLine());
        P = Integer.parseInt(line.nextToken());
        D = Integer.parseInt(line.nextToken());
        long[][] totalVotes = new long[D][2];

        for (int i = 0; i < P; i++)
        {
            line = new StringTokenizer(in.readLine());
            d = Integer.parseInt(line.nextToken())-1;
            a = Integer.parseInt(line.nextToken());
            b = Integer.parseInt(line.nextToken());
            totalVotes[d][0] += a;
            totalVotes[d][1] += b;
        }
        long[] counter = new long[3];
        for (int i = 0; i < D; i++)
        {
            StringBuilder output = new StringBuilder();
            long[] votes = totalVotes[i];
            if (votes[0] > votes[1])
            {
                counter[0] += (votes[0] + votes[1]);
                output.append("A").append(" ");
                long wastedA = votes[0] - ((long) Math.floor((votes[0] + votes[1])/2) +1);
                counter[1] += wastedA;
                counter[2] += votes[1];
                output.append(wastedA).append(" ");
                output.append(votes[1]);
                System.out.println(output.toString().strip());
            } else {
                counter[0] += (votes[0] + votes[1]);
                output.append("B").append(" ");
                long wastedB = votes[1] - ((long) Math.floor((votes[0] + votes[1])/2) + 1);
                counter[1] += votes[0];
                counter[2] += wastedB;
                output.append(votes[0]).append(" ");
                output.append(wastedB);
                System.out.println(output.toString().strip());
            }
        }
        System.out.println((Math.abs(counter[1] - counter[2])/ (double)counter[0]));
    }
}
