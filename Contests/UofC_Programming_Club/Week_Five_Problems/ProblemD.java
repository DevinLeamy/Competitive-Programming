import java.util.*;
import java.io.*;

public class ProblemD {
    private static int getYield(String message, String code)
    {
        int countM = 0;
        try {
            for (int i = 0; i < message.length(); i++)
            {
                if (message.substring(i, i + code.length()).equals(code))
                {
                    countM++;
                    i += code.length()-1;
                }
            }
        } catch (StringIndexOutOfBoundsException e) {}
        return ((countM * code.length()) - countM) - code.length();
    }
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String message = in.readLine();
        String currentCode;
        int bestYield = 0;
        if (message.length() > 2)
        {
            for (int i = 0; i < message.length() - 1; i++)
            {
                for (int j = i + 1; j < message.length(); j++)
                {
                    currentCode = message.substring(i, j);
                    int yield = getYield(message, currentCode);
                    if (yield > bestYield)
                    {
                        bestYield = yield;
                    }
                }
            }
            System.out.println((message.length() - bestYield));
        } else {
            System.out.println(message.length());
        }
    }
}
