import java.util.*;
import java.io.*;

public class ProblemJ {

    public static void main(String[] args)  throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line = in.readLine();
        long[] S = new long[2];
        long[] counts = new long[2];
        for (int i = 0; i < line.length(); i++)
        {
           char character = line.charAt(i);
           switch (character)
           {
               case '0':
                   S[0] += i - counts[0];
                   counts[0]++;
                   counts[1]++;
                   break;
               case '1':
                   S[1] += i - counts[1];
                   counts[1]++;
                   break;
           }
        }
        System.out.println((S[0] + S[1]));
    }
}
