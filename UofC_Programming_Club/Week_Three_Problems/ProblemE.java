import java.io.*;
import java.util.*;

public class ProblemE {
    private static int setValue(int[] good, int[] cycle, int currentIndex, int S)
    {
        int movesLeft = S;
        while (movesLeft > 0)
        {
            currentIndex++;
            currentIndex = currentIndex % cycle.length;
            if (cycle[currentIndex] != -1)
            {
                movesLeft--;
            }
        }
        good[currentIndex] = S;
        cycle[currentIndex] = -1;
        int current = currentIndex;
        while (cycle[currentIndex] == -1)
        {
            currentIndex++;
            currentIndex = currentIndex % cycle.length;
            if (current == currentIndex)
            {
                break;
            }
        }
        return currentIndex;

    }
    //Size S -> go one after current, decrease size then go three after current decrease size then go 5 after current
    private static int[] getShuffle(int S)
    {
        int[] shuffle = new int[S];
        int[] cycle = new int[S];
        int currentS = 1;
        int currentIndex = 0;
        for (int i = 0; i < S; i++)
        {
            currentIndex = setValue(shuffle, cycle, currentIndex, currentS);
            currentS++;
        }
        return shuffle;
    }
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        for (int i = 0; i < N; i++)
        {
            int S = Integer.parseInt(in.readLine());
            int[] shuffle = getShuffle(S);
            StringBuilder output = new StringBuilder();
            for (int num : shuffle)
            {
                output.append(num).append(" ");
            }
            System.out.println(output.toString().strip());
        }
    }
}
