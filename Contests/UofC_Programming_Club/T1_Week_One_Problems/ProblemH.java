import java.util.*;
import java.io.*;


public class ProblemH {
    private static void computeMatch(int[][] wonLost, String[] match)
    {
        int player1 = Integer.parseInt(match[0]) - 1;
        int player2 = Integer.parseInt(match[2]) - 1;
        String move1 = match[1];
        String move2 = match[3];
        if (!move1.equals(move2))
        {
            if (move1.equals("rock"))
            {
                if (move2.equals("scissors"))
                {
                    wonLost[player1][0]++;
                    wonLost[player2][1]++;
                } else {
                    wonLost[player1][1]++;
                    wonLost[player2][0]++;
                }
            } else if (move1.equals("paper"))
            {
                if (move2.equals("rock"))
                {
                    wonLost[player1][0]++;
                    wonLost[player2][1]++;
                } else {
                    wonLost[player1][1]++;
                    wonLost[player2][0]++;
                }
            } else {
                if (move2.equals("paper"))
                {
                    wonLost[player1][0]++;
                    wonLost[player2][1]++;
                } else {
                    wonLost[player1][1]++;
                    wonLost[player2][0]++;
                }
            }
        }
    }
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        while (true)
        {
            StringTokenizer line = new StringTokenizer(in.readLine());
            int N = Integer.parseInt(line.nextToken());
            if (N == 0)
            {
                break;
            }
            int M = Integer.parseInt(line.nextToken());
            int[][] wonLost = new int[N][2];
            String[] match;
            int numberOfMatchs = ((N * M)*(N - 1))/2;
            for (int i = 0; i < numberOfMatchs; i++)
            {
                match = in.readLine().split(" ");
                computeMatch(wonLost, match);
            }
            for (int i = 0; i < N; i++)
            {
                double totalGames = (wonLost[i][0] + wonLost[i][1]);
                if (totalGames > 0)
                {
                    double decimal = wonLost[i][0]/totalGames;
                    System.out.println(String.format("%.3f", decimal));
                } else
                {
                    System.out.println("-");
                }
            }
            System.out.println();
        }
    }
}
