import java.util.*;
import java.io.*;

public class ProblemC {
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer line;
        line = new StringTokenizer(in.readLine());
        ArrayList<Integer> heights = new ArrayList<>();
        int biggest = -1;
        for (int i = 0; i < 6; i++)
        {
            int num = Integer.parseInt(line.nextToken());
            biggest = Integer.max(biggest, num);
            heights.add(num);
        }
        int H1 = Integer.parseInt(line.nextToken());
        int H2 = Integer.parseInt(line.nextToken());
        ArrayList<Integer> oneTower = new ArrayList<>();
        oneTower.add(biggest);
        Collections.sort(heights);
        boolean towerOne = false;
        for (int i = 0; i < 5; i++)
        {
            for (int j = i+1; j < 5; j++)
            {
                if (heights.get(i) + heights.get(j) == H1- biggest && oneTower.size() != 3)
                {
                    oneTower.add(heights.get(i));
                    oneTower.add(heights.get(j));
                    towerOne = true;
                } else if (heights.get(i) + heights.get(j) == H2 - biggest && oneTower.size() != 3)
                {
                    oneTower.add(heights.get(i));
                    oneTower.add(heights.get(j));
                }
            }
        }
        Collections.sort(oneTower);
        Collections.reverse(oneTower);
        StringBuilder oneTowerOutput = new StringBuilder();
        for (int num : oneTower)
        {
            oneTowerOutput.append(num).append(" ");
        }
        StringBuilder towerTwo = new StringBuilder();
        Collections.reverse(heights);
        for (int num : heights)
        {
            if (!oneTower.contains(num))
            {
                towerTwo.append(num).append(" ");
            }
        }
        if (towerOne)
        {
            System.out.println(oneTowerOutput.toString().strip() + " " + towerTwo.toString().strip());
        } else {
            System.out.println(towerTwo.toString().strip() + " " + oneTowerOutput.toString().strip());
        }
    }
}