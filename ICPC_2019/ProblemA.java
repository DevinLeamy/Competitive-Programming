//Works

import java.util.*;
import java.io.*;


public class ProblemA {
    private static void getOutput(String command, ArrayList<Boolean> queue)
    {
        switch (command)
        {
            case "-" :
                queue.add(!queue.get(queue.size() - 1));
                queue.remove(queue.size() - 2);
                break;
            case "*" :
                if (queue.get(queue.size() -1) && queue.get(queue.size() - 2))
                {
                    queue.add(true);
                } else {
                   queue.add(false);
                }
                queue.remove(queue.size()-2);
                queue.remove(queue.size()-2);
                break;
            case "+" :
                if (queue.get(queue.size() -1) || queue.get(queue.size() - 2))
                {
                    queue.add(true);
                } else {
                    queue.add(false);
                }
                queue.remove(queue.size()-2);
                queue.remove(queue.size()-2);
                break;
        }
    }
    private static final String ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    public static void main(String[] args) throws IOException
    {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        StringTokenizer line = new StringTokenizer(in.readLine());
        boolean[] isTrue = new boolean[N];
        for (int i = 0; i < N; i++)
        {
            isTrue[i] = (!line.nextToken().equals("F"));
        }
        line = new StringTokenizer(in.readLine());
        int count = line.countTokens();
        ArrayList<Boolean> queue = new ArrayList<>();
        for (int i = 0; i < count; i++)
        {
            String character = line.nextToken();
            if (!ALPHABET.contains(String.valueOf(character)))
            {
                getOutput(character, queue);
            } else {
                queue.add(isTrue[ALPHABET.indexOf(character)]);
            }
        }
        if (queue.get(queue.size() - 1))
        {
            System.out.println("T");
        } else {
            System.out.println("F");
        }
    }
}
