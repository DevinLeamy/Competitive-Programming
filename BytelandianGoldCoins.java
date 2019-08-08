import java.io.*;
import java.util.*;



public class BytelandianGoldCoins {
    private static long[] checked = new long[10000000];
    private static long solve(long num){
        if (checked[(int) num] != -1){
            return checked[(int) num];
        }
        checked[(int) num] = Long.max(num, solve(num/2) + solve(num/3) + solve(num/4));
        return checked[(int) num];
    }
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        Arrays.fill(checked, -1);
        checked[0] = 0;
        checked[1] = 1;
        checked[2] = 2;
        checked[3] = 3;
        checked[4] = 4;
        checked[5] = 5;
        checked[6] = 6;
        for (int i = 0; i < T; i++){
            long N = Long.parseLong(in.readLine());
            System.out.println(solve(N));
        }
    }
}
