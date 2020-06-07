import java.io.*;
import java.util.*;

public class DIYWoodenLadder_1000 {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for (int i = 0; i < T; i++){
            int N = Integer.parseInt(in.readLine());
            List<Integer> planks = new ArrayList<>();
            StringTokenizer line = new StringTokenizer(in.readLine());
            for (int j = 0; j < N; j++){
                int plank = Integer.parseInt(line.nextToken());
                if (plank >= 1) {
                    planks.add(plank);
                }
            }
            Collections.sort(planks);
            int maxK =  planks.size() - 2;
            int longest = Integer.min(planks.get(planks.size() - 1), planks.get(planks.size() - 2));
            if (longest > (maxK + 1)){
                System.out.println(maxK);
            } else {
                System.out.println(longest - 1);
            }

        }
    }
}
