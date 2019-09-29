import java.util.*;
import java.io.*;

public class Problem1I {
    private static final String ALPHABET = "abcdefghijklmnopqrstuvwxyz";
    private static Set<String> findSyllable(ArrayList< ArrayList<String> > sortedS, String word)
    {
        ArrayList<String> syllables = new ArrayList<>(sortedS.get(ALPHABET.indexOf(word.charAt(0))));
        Set<String> output = new HashSet<>();
        for (String syllable : syllables)
        {
            if (syllable.equals(word))
            {
                output.add("");
            }
        }

        for (int i = 1; i < word.length(); i++)
        {
            char character = word.charAt(i);
            if (syllables.size() == 0)
            {
                break;
            }
            ArrayList<String> remove = new ArrayList<>();
            for (String syllable : syllables)
            {
                try {
                    if (syllable.charAt(i) != character) {
                        remove.add(syllable);
                    }
                } catch (StringIndexOutOfBoundsException e)
                {
                    remove.add(syllable);
                    output.add(word.substring(syllable.length()));
                }
            }
            syllables.removeAll(remove);
        }
        return output;
    }
    private static Set<Integer> getPossibleCounts(ArrayList<Integer>[] counter)
    {
        Set<Integer> output = new HashSet<>(counter[0]);
        for (int i = 1; i < counter.length; i++)
        {
            Set<Integer> add = new HashSet<>();
            for (int value : counter[i])
            {
                for (int current : output)
                {
                    add.add(current + value);
                }
            }
            output = new HashSet<>(add);
        }
        return output;
    }
    private static String solve(String[][] haiku, ArrayList< ArrayList<String> > sortedSyllables)
    {
        String[] line;
        for (int i = 0; i < 3; i++)
        {
            line = haiku[i];
            ArrayList<Integer>[] counter = new ArrayList[line.length];
            for (int j = 0; j < line.length; j++)
            {
                counter[j] = new ArrayList<>();
                String word = line[j];
                int countWord = 1;
                ArrayList<String> variations = new ArrayList<>();
                variations.add(word);
                while (variations.size() > 0)
                {
                    Set<String> add = new HashSet<>();
                    for (String substring : variations)
                    {
                        Set<String> yield = findSyllable(sortedSyllables, substring);
                        for (String newSubstring : yield)
                        {
                            if (newSubstring.length() == 0)
                            {
                                counter[j].add(countWord);
                            } else if (!newSubstring.equals(substring))
                            {
                                add.add(newSubstring);
                            }
                        }
                    }
                    countWord++;
                    variations = new ArrayList<>(add);
                }
            }
            boolean good = false;
            Set<Integer> possibleCounts = getPossibleCounts(counter);
            for (int value : possibleCounts)
            {
                if (((i == 0 || i == 2) && value == 5) || (i == 1 && value == 7))
                {
                    good = true;
                    break;
                }
            }
            if (!good)
            {
                return "come back next year";
            }
        }
        return "haiku";
    }
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int S = Integer.parseInt(in.readLine());
        ArrayList< ArrayList<String>> sortedSyllables = new ArrayList<>();
        String syllable;
        for (int i = 0; i < 26; i++)
        {
            sortedSyllables.add(new ArrayList<>());
        }
        for (int i = 0; i < S; i++)
        {
            syllable = in.readLine();
            sortedSyllables.get(ALPHABET.indexOf(syllable.charAt(0))).add(syllable);
        }
        String[][] haiku = {in.readLine().split(" "), in.readLine().split(" "), in.readLine().split(" ")};
        System.out.println(solve(haiku, sortedSyllables));
    }
}
