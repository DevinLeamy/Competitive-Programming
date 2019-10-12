import java.util.*;
import java.io.*;

public class CityDay_1000 {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer lineOne = new StringTokenizer(in.readLine());
        int D = Integer.parseInt(lineOne.nextToken());
        int X = Integer.parseInt(lineOne.nextToken());
        int Y = Integer.parseInt(lineOne.nextToken());
        int[] days = new int[D];
        StringTokenizer lineTwo = new StringTokenizer(in.readLine());
        for (int i = 0; i < D; i++){
            days[i] = Integer.parseInt(lineTwo.nextToken());
        }
        int current = days[0];
        int currentI = 0;
        while (true){
            boolean found = true;
            int min = currentI - X;
            int max = currentI + Y + 1;
            if (0 > min){
                min = 0;
            }
            if (max > D){
                max = D;
            }
            for (int i = min; i < max; i++) {
                int M = days[i];
                if (M < current && i != currentI) {
                    found = false;
                    current = M;
                    currentI = i;
                    break;
                }
            }
            if (found) {
                System.out.println(currentI + 1);
                break;
            }
        }
    }
}
