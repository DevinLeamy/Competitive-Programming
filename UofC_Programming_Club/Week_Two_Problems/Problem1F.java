import java.util.*;
import java.io.*;


public class Problem1F {
    private static int getCost(String want, String have)
    {
        int cost = 0;
        if (have.length() > want.length())
        {
            cost += have.length() - want.length();
            have = have.substring(0, want.length());
        }
        boolean good = true;
        for (int i = 0; i < want.length(); i++)
        {
            try {
                char character = have.charAt(i);
                if (good && want.charAt(i) != character) {
                    cost += 2;
                    good = false;
                } else if (!good) {
                    cost += 2;
                }
            } catch (StringIndexOutOfBoundsException sioobe)
            {
                cost++;
            }
        }
        return cost;
    }
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for (int i= 0; i < T; i++)
        {
            String want = in.readLine();
            String typed = in.readLine();
            String sug1 = in.readLine();
            String sug2 = in.readLine();
            String sug3 = in.readLine();
            String[] suggestions = {sug1, sug2, sug3, typed};
            int M = Integer.MAX_VALUE;
            for (String sug : suggestions)
            {
                if (!sug.equals(typed))
                {
                    M = Integer.min(M, getCost(want, sug)+1);
                } else{
                    M = Integer.min(M, getCost(want, sug));
                }
            }
            System.out.println(M);
        }
    }
}
