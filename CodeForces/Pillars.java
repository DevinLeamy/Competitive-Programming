import java.io.*;
import java.util.*;

public class Pillars {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        int[] pillars = new int[N];
        StringTokenizer line = new StringTokenizer(in.readLine());
        int[] maxI = new int[2];
        maxI[0] = Integer.MIN_VALUE;
        maxI[1] = 0;
        for (int i = 0; i < N; i++){
            int pillar = Integer.parseInt(line.nextToken());
            if (pillar > maxI[0]){
                    maxI[0] = pillar;
                    maxI[1] = i;
            }
            pillars[i] = pillar;
        }
        boolean good = true;
        int current = 0;
        int value = pillars[0];
        while (current != maxI[1]){
            try {
                if (pillars[current + 1] < value) {
                    good = false;
                    break;
                }
                current++;
                value = pillars[current];
            } catch (ArrayIndexOutOfBoundsException aioobe){
                break;
            }
        }
        while (current != pillars.length){
            try {
                if (pillars[current + 1] > value) {
                    good = false;
                    break;
                }
                current++;
                value = pillars[current];
            } catch (ArrayIndexOutOfBoundsException aioobe){
                break;
            }
        }
        System.out.println(
                (good)? "YES": "NO"
        );
    }
}
