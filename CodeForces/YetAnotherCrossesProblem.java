import java.util.*;
import java.io.*;

public class YetAnotherCrossesProblem {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int Q = Integer.parseInt(in.readLine());
        for (int i = 0; i < Q; i++){
            StringTokenizer NM = new StringTokenizer(in.readLine());
            int N = Integer.parseInt(NM.nextToken()), M = Integer.parseInt(NM.nextToken());
            int[] cols = new int[M];
            int[] rows = new int[N];
            String[][] grid = new String[N][M];
            for (int j = 0; j < N; j++){
                String[] line = in.readLine().split("");
                grid[j] = line;
                for (int z = 0; z < line.length; z++){
                    if (line[z].equals("*")){
                        rows[j] += 1;
                        cols[z] += 1;
                    }
                }
            }
            int currentB = 0;
            for (int j = 0; j < M; j++){
                int col = cols[j];
                for (int z = 0; z < N; z++){
                    int row = rows[z];
                    if (grid[z][j].equals(".")){
                        row++;
                    }
                    if (currentB < (row + col)){
                        currentB = row + col;
                    }
                }
            }
            int min = (N + M) - currentB;
            System.out.println(min);
        }
    }
}
