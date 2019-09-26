import java.util.*;
import java.io.*;


public class Problem1D {
    private static String shift(String original, int index, int shift)
    {
        int newIndex = ALPHABET.indexOf(original.charAt(index)) - shift;
        if (newIndex < 0)
        {
            return String.valueOf(ALPHABET.charAt(26 - Math.abs(newIndex)));
        }
        return String.valueOf(ALPHABET.charAt(newIndex));
    }
    private static String ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String ciphered = in.readLine();
        String word = in.readLine();
        String key = word + ciphered;
        StringBuilder output = new StringBuilder();
        int indexOfString = 0;
        for (int i = 0; i < ciphered.length(); i++)
        {
            if (i < word.length())
            {
                int index = ALPHABET.indexOf(String.valueOf(word.charAt(i)));
                output.append(shift(ciphered, i, index));
            } else {
                int index = ALPHABET.indexOf(String.valueOf(output.toString().charAt(indexOfString)));
                output.append(shift(ciphered, i, index));
                indexOfString++;
            }
        }
        System.out.println(output.toString());


    }
}
