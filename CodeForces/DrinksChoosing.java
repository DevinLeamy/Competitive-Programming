import java.util.*;
import java.io.*;

public class DrinksChoosing {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer NK = new StringTokenizer(in.readLine());
        int N = Integer.parseInt(NK.nextToken());
        int K = Integer.parseInt(NK.nextToken());
        int[] requests = new int[K + 1];
        for (int i = 0; i < N; i++){
            int desired = Integer.parseInt(in.readLine());
            requests[desired]++;
        }
        int sets = (N / 2) + N % 2;
        int happy = 0;
        for (int i = 1; i < requests.length; i++){
            while (requests[i] >= 2 && sets > 0){
                requests[i] -= 2;
                happy += 2;
                sets--;
            }
        }
        if (sets > 0){
            for (int request: requests){
                if (sets > 0) {
                    if (request > 0) {
                        sets--;
                        happy++;
                    }
                } else {
                    break;
                }
            }
        }
        System.out.println(happy);
    }
}
