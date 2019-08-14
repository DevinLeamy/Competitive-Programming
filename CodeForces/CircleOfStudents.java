import java.util.*;
import java.io.*;

public class CircleOfStudents {
    private static boolean canDance(int[] students, int N, int first){
        if (N == 1 || N == 2){
            return true;
        }
        int add = (students[first] + 1 == students[(first + 1) % N])? 1: -1;
        int index = (add == 1)? (first + 1)% N: (first - 1);
        if (index < 0){
            index = N-1;
        }
        int current = students[first];
        int counted = 1;
        while (counted < N ){
            int next = students[index % N];
            if (next != (current + 1)){
               return false;
            }
            current = next;
            counted++;
            index += add;
            if (index < 0){
                index = N-1;
            }
        }
        return true;
    }
    public static void main(String[] args) throws IOException {
        int Q = nextInt();
        for (int i = 0; i < Q; i++){
            int N = nextInt();
            int first = 0;
            StringTokenizer line = new StringTokenizer(in.readLine());
            int[] students = new int[N];
            for (int j = 0; j < N; j++){
                int num = Integer.parseInt(line.nextToken());
                if (num == 1){
                    first = j;
                }
                students[j] = num;
            }
            System.out.println(
                    canDance(students, N, first)? "YES": "NO"
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
