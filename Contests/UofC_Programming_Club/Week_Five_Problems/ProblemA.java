import java.util.*;
import java.io.*;

public class ProblemA {
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer line;
        int rhyme = in.readLine().split(" ").length;
        int N = Integer.parseInt(in.readLine());
        boolean[] chosen = new boolean[N];
        ArrayList<Integer> teamOne = new ArrayList<>();
        ArrayList<Integer> teamTwo = new ArrayList<>();
        int current = 0;
        int currentTeam = 0;
        while (teamOne.size() + teamTwo.size() < N)
        {
            int count = 0;
            while (count != rhyme)
            {
                if (!chosen[current])
                {
                    count++;
                    if (count == rhyme)
                    {
                        chosen[current] = true;
                        if (currentTeam == 0) {
                            teamOne.add(current);
                            currentTeam++;
                        } else {
                            teamTwo.add(current);
                            currentTeam--;
                        }
                        break;
                    }
                }
                current++;
                current %= N;
            }
        }
        String[] members = new String[N];
        for (int i = 0; i < N; i++)
        {
            members[i] = in.readLine();
        }
        System.out.println(teamOne.size());
        for (int num : teamOne)
        {
            System.out.println(members[num]);
        }
        System.out.println(teamTwo.size());
        for (int num : teamTwo)
        {
            System.out.println(members[num]);
        }
    }
}