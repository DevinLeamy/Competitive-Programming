import java.util.*;
import java.io.*;

public class EmailFromPolycarp {
    private static boolean canBeTyped(String goal, String got){
        String Z = String.valueOf(goal.charAt(0));
        if (got.length() < goal.length())
        {
            return false;
        }
        int overflow = got.length() - goal.length();
        int I = 0;
        for (int i = 0; i < goal.length(); i++){
            String character = String.valueOf(goal.charAt(i));
            String characterY = String.valueOf(got.charAt(I));
            if (character.equals(characterY)){
                I++;
                Z = character;
                continue;
            }
            if (i == 0){
                return false;
            }
            while (characterY.equals(Z)){
                I++;
                if (I == got.length()){
                    break;
                }
                characterY = String.valueOf(got.charAt(I));
                overflow--;
            }
            if (overflow < 0){
                return false;
            }
            if (!characterY.equals(character)){
                return false;
            }
            Z = character;
            I++;
        }
        String current;
        while (I < got.length()){
            current = String.valueOf(got.charAt(I));
            if (!current.equals(Z)){
                return false;
            }
            I++;
        }
        return true;
    }
    public static void main(String[] args) throws IOException {
        int N = nextInt();
        for (int i = 0; i < N; i++){
            String goal = nextString();
            String got = nextString();
            System.out.println(
                    canBeTyped(goal, got)? "YES": "NO"
            );
        }
    }
    private static StringTokenizer line = new StringTokenizer("");
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    private static int nextInt() throws IOException
    {
        return Integer.parseInt(nextString());
    }
    private static long nextLong() throws IOException
    {
        return Long.parseLong(nextString());
    }
    private static String nextString() throws IOException
    {
        if (line.hasMoreTokens())
        {
            return line.nextToken();
        } else {
            line = new StringTokenizer(in.readLine());
            return line.nextToken();
        }
    }
    private static String[] nextStringArray() throws IOException
    {
        return in.readLine().split(" ");
    }
    private static int[] nextIntArray() throws IOException
    {
        return Arrays.stream(nextStringArray()).mapToInt(Integer::parseInt).toArray();
    }
    private static long[] nextLongArray() throws IOException
    {
        return Arrays.stream(nextStringArray()).mapToLong(Long::parseLong).toArray();
    }
}
