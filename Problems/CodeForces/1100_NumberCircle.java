import java.util.*;
import java.io.*;

public class NumberCircle_1100 {
    private static void check(long[] array){
        for (int i = 0; i < array.length; i++){
            long current = array[i];
            if (i == 0){
                if (current >= (array[array.length - 1] + array[1])){
                    System.out.println("NO");
                    return;
                }
            } else if (i == array.length - 1){
                if (current >= (array[i - 1] + array[0])){
                    System.out.println("NO");
                    return;
                }
            } else {
                if (current >= (array[i - 1] + array[i + 1])){
                    System.out.println("NO");
                    return;
                }
            }
        }
        StringBuilder output = new StringBuilder();
        for (long num: array){
            output.append(num);
            output.append(" ");
        }
        System.out.println("YES");
        System.out.println(output.toString());
    }
    public static void main(String[] args) throws IOException{
        long N = nextInt();
        List<Long> V = new ArrayList<>();
        for (int i = 0; i < N; i++){
            V.add(nextLong());
        }
        Collections.sort(V);
        long[] solution = new long[(int)N];
        solution[0] = V.get(V.size() - 1);
        solution[(int) N - 1] = V.get(V.size() - 2);
        int I = 1;
        for (int i = V.size() - 3; i >= 0; i--){
            solution[I] = V.get(i);
            I++;
        }
        check(solution);
    }
    private static StringTokenizer line = new StringTokenizer("");
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    private static int nextInt() throws IOException
    {
        return Integer.parseInt(getNext());
    }
    private static long nextLong() throws IOException
    {
        return Long.parseLong(getNext());
    }
    private static String getNext() throws IOException
    {
        if (line.hasMoreTokens())
        {
            return line.nextToken();
        } else {
            line = new StringTokenizer(in.readLine());
            return line.nextToken();
        }
    }
}

