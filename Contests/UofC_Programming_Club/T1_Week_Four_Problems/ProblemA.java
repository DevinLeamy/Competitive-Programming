import java.util.*;
import java.io.*;

public class ProblemA {

    public static void main(String[] args)  throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<String> words = new ArrayList<>();
        StringTokenizer line = new StringTokenizer(in.readLine());
        int len = line.countTokens();
        boolean good = true;
        for (int i = 0; i < len; i++)
        {
            String word = line.nextToken();
            if (words.contains(word))
            {
                good = false;
                break;
            }
            words.add(word);
        }
        if (good)
        {
            System.out.println("yes");
        } else {
            System.out.println("no");
        }
    }
}
