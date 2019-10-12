import java.util.*;
import java.io.*;

public class SportMafia_1100 {
    private static long solve(long N, long K){
        long squareRoot = Math.round(Math.sqrt(9 + (-4 * -(2* (N + K)))));
        return N - ((-3 + squareRoot)/2);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer NK = new StringTokenizer(in.readLine());
        long N = Long.parseLong(NK.nextToken());
        long K = Long.parseLong(NK.nextToken());
        System.out.println(solve(N, K));
    }
}
