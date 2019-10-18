import java.util.*;
import java.io.*;

public class ProblemB {
    private static final String ALPHABET = "abcdefghijklmnopqrstuvwxyz";
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer line;
        String A = in.readLine();
        char start = A.charAt(A.length()-1);
        int N = Integer.parseInt(in.readLine());
        int[] alphabet = new int[26];
        ArrayList<String> choices = new ArrayList<>();
        for (int i = 0; i < N; i++)
        {
            String name = in.readLine();
            if (name.charAt(0) == start)
            {
                choices.add(name);
            }
            alphabet[ALPHABET.indexOf(String.valueOf(name.charAt(0)))]++;
        }
        if (choices.size() == 0)
        {
            System.out.println("?");
        }else {
            boolean found = false;
            String good = "";
            for (String name : choices)
            {
                start = name.charAt(0);
                char end = name.charAt(name.length() - 1);
                int index = ALPHABET.indexOf(String.valueOf(start));
                alphabet[index]--;
                if (alphabet[ALPHABET.indexOf(String.valueOf(end))] == 0)
                {
                    found = true;
                    good = name;
                    break;
                }
                alphabet[index]++;
            }
            if (found)
            {
                System.out.println(good + "!");
            } else {
                System.out.println(choices.get(0));
            }
        }

    }
}
//Muk next player name!
//Can play name
//Can't play ?