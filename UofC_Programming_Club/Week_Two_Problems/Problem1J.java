import java.util.*;
import java.io.*;

public class Problem1J {
    private static final String VOWELS = "AEIOUYaeiouy";
    private static final String ALPHABET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    private static boolean isATrueVowel(String word, int index)
    {
        String character = String.valueOf(word.charAt(index));
        switch (character)
        {
            case "u":
            case "U": {
                return ifU(word, index);
            }
            case "Y":
            case "y": {
                return ifY(word, index);
            }
            case "E":
            case "e": {
                return ifE(word, index);
            }
            default: {
                return true;
            }
        }
    }
    private static boolean ifU(String word, int index)
    {
        try {
            if (word.charAt(index - 1) == 'q' || word.charAt(index - 1) == 'Q') {
                return false;
            }
        } catch (StringIndexOutOfBoundsException e) {}
        return true;
    }
    private static boolean ifY(String word, int index)
    {
        try {
            if (VOWELS.contains(String.valueOf(word.charAt(index+1))))
            {
                return false;
            }
        } catch (StringIndexOutOfBoundsException e){}
        return true;
    }
    private static int countConstants(int start, int end, String word)
    {
        int count = 0;
        boolean containsQU = false;
        for (int i = start; i < end; i++)
        {
            if (isSingleConstant(word.substring(i, i+2)))
            {
                count++;
                containsQU = true;
                break;
            } else if (VOWELS.contains(String.valueOf(word.charAt(i))))
            {
                if (!isATrueVowel(word, i))
                {
                    count++;
                }
            } else {
                count++;
            }
        }
        if (start-1 >= 0 && isSingleConstant(word.substring(start-1, start+1)) && containsQU)
        {
            count++;
        } else if (start-1 >= 0 && VOWELS.contains(String.valueOf(word.charAt(start-1))) && containsQU)
        {
            if (!isATrueVowel(word, start-1))
            {
                count++;
            }
        } else if (start-1 >= 0 && containsQU){
            count++;
        }
        return count;
    }
    private static boolean isSingleConstant(String substring)
    {
        if (substring.charAt(0) == 'Q' || substring.charAt(0) == 'q')
        {
            if (substring.charAt(1) == 'u' || substring.charAt(1) == 'U')
            {
                return true;
            }
        }
        return false;
    }
    private static boolean ifE(String word, int index)
    {
        try {
            if (index == word.length() - 1)
            {
                if ((word.charAt(index - 1) == 'L' || word.charAt(index-1) == 'l' ))
                {
                    if (VOWELS.contains(String.valueOf(word.charAt(index-2))))
                    {
                        if (!isATrueVowel(word, index - 2))
                        {
                            return true;
                        }
                        return false;
                    }
                    return true;
                }
                return false;
            }
        } catch (StringIndexOutOfBoundsException e)
        {
            return false;
        }
        try {
            if ((word.charAt(index +1) == 'S' || word.charAt(index+1) == 's') && word.length() == index+2)
            {
                int count = countConstants(index-2, index, word);
                return (count == 2);
            }
        } catch (StringIndexOutOfBoundsException e) {}
        return true;
    }
    private static int getSyllableCount(String word, boolean[] isAVowel)
    {
        int count = 1;
        boolean containsConstant = false;
        boolean containsVowel = false;
        for (int i = 0; i < word.length(); i++)
        {
            if (isAVowel[i] && containsConstant && containsVowel)
            {
                count++;
                containsConstant = false;
            } else if (!isAVowel[i])
            {
                containsConstant = true;
            } else if (isAVowel[i])
            {
                containsVowel = true;
                containsConstant = false;
            }
        }
        return count;
    }
    private static int getSyllables(String word)
    {
        String character;
        while (word.length() > 0 && !ALPHABET.contains(String.valueOf(word.charAt(word.length() - 1))))
        {
            word = word.substring(0, word.length()-1);
        }
        boolean[] isAVowel = new boolean[word.length()];
        for (int i = 0; i < word.length(); i++)
        {
            character = String.valueOf(word.charAt(i));
            if (VOWELS.contains(character))
            {
                if (isATrueVowel(word, i))
                {
                    isAVowel[i] = true;
                }
            }
        }
        return getSyllableCount(word, isAVowel);
    }
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line = in.readLine();
        String[] words = line.split(" ");
        int[] syllableCount = new int[3];
        String[] haiku = new String[3];
        Arrays.fill(haiku, "");
        int total;
        int current = 0;
        for (String word : words)
        {
            total = getSyllables(word);
            if (current == 0)
            {
                syllableCount[0] += total;
                haiku[0] += word + " ";
                if (syllableCount[0] > 5)
                {
                    break;
                } else if (syllableCount[0] == 5)
                {
                    current++;
                }
            } else if (current == 1)
            {
                syllableCount[1] += total;
                haiku[1] += word + " ";
                if (syllableCount[1] > 7)
                {
                    break;
                } else if (syllableCount[1] == 7)
                {
                    current++;
                }
            } else {
                syllableCount[2] += total;
                haiku[2] += word + " ";
                if (syllableCount[2] > 5)
                {
                    break;
                }
            }
        }
        if (syllableCount[0] == 5 && syllableCount[1] == 7 && syllableCount[2] == 5)
        {
            for (String phrase : haiku)
            {
                System.out.println(phrase.strip());
            }
        } else {
            System.out.println(line);
        }
    }
}
