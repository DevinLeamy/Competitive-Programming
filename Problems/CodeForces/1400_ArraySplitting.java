import java.util.*;
import java.io.*;

public class ArraySplitting_1400 {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer NK = new StringTokenizer(in.readLine());
        int N = Integer.parseInt(NK.nextToken()), K = Integer.parseInt(NK.nextToken());
        int[] array = new int[N];
        StringTokenizer line = new StringTokenizer(in.readLine());
        for (int i = 0; i < N; i++){
            int num = Integer.parseInt(line.nextToken());
            array[i] = num;
        }
        List<Integer> differences = new ArrayList<>();
        for (int i = 1; i < N; i++){
            differences.add(array[i - 1] - array[i]);
        }
        Collections.sort(differences);
        int current = array[N - 1] - array[0];
        for (int i = 0; i < K - 1; i++){
            current += differences.get(i);
        }
        System.out.println(current);
    }
}
