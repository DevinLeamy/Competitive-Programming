import java.io.*;

public class ThanosSort {
    private static void fill(int[] big, int[] small, int s){
        for (int i = s; i < s + small.length; i++){
            small[i - s] = big[i];
        }
    }
    private static boolean sorted(int[] array){
        for (int i = 0; i < array.length - 1; i++){
            if (array[i + 1] < array[i]){
                return false;
            }
        }
        return true;
    }
    private static int solve(int[] array){
        if (sorted(array)){
            return array.length;
        }
        int[] first = new int[array.length/2];
        int[] second = new int[array.length/2];
        fill(array, first, 0);
        fill(array, second, second.length);
        return Integer.max(solve(first), solve(second));
    }
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        int[] array = new int[N];
        String[] line = in.readLine().split(" ");
        for (int i = 0; i < N; i++){
            array[i] = Integer.parseInt(line[i]);
        }
        System.out.println(solve(array));
    }
}
