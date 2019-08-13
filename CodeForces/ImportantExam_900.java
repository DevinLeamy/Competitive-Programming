import java.util.*;
import java.io.*;

public class ImportantExam_900 {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer line = new StringTokenizer(in.readLine());
        int N = Integer.parseInt(line.nextToken()), M = Integer.parseInt(line.nextToken());
        int score = 0;
        String[][] tests = new String[N][M];
        for (int i = 0; i < N; i++){
            String[] result = in.readLine().split("");
            tests[i] = result;
        }
        int[] chose = new int[M];
        for (int j = 0; j < M; j++){
            int[] scores = new int[5];
            for (int i = 0; i < N; i++){
                String answer = tests[i][j];
                if (answer.equals("A")){
                    scores[0]++;
                } else if (answer.equals("B")){
                    scores[1]++;
                } else if (answer.equals("C")){
                    scores[2]++;
                } else if (answer.equals("D")){
                    scores[3]++;
                } else if (answer.equals("E")){
                    scores[4]++;
                }
            }
            Arrays.sort(scores);
            chose[j] = scores[4];
        }
        StringTokenizer nextLine = new StringTokenizer(in.readLine());
        for (int i = 0; i < M; i++){
            score += (Integer.parseInt(nextLine.nextToken()) * chose[i]);
        }
        System.out.println(score);
    }
}
