import java.util.*;
import java.io.*;

public class ProblemC {

    public static void main(String[] args)  throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        int[] branch = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        ArrayList<ArrayList<Integer>> reachable = new ArrayList<>();
        for (int i= 0; i < 100; i++)
        {
            reachable.add(new ArrayList<>());
        }
        while (branch[0] != -1)
        {
            int firstBranch = branch[0]-1;
            for (int i = 1; i < branch.length; i++)
            {
                int num = branch[i];
                reachable.get(num-1).add(firstBranch);
            }
            branch = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }
        int current = N-1;
        StringBuilder output = new StringBuilder();
        output.append(N).append(" ");
        while (reachable.get(current).size() > 0)
        {
            current = reachable.get(current).get(0);
            output.append(current+1).append(" ");
        }
        System.out.println(output.toString().strip());


    }
}
