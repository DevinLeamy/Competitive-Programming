import java.io.*;
import java.util.*;

public class ProblemC {
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> FBI = new ArrayList<>();
        for (int i = 0; i < 5; i++)
        {
            String B = in.readLine();
            for (int f = 0; f < B.length(); f++)
            {
                if (B.charAt(f) == 'F')
                {
                    try {
                        if (B.substring(f, f+3).equals("FBI"))
                        {
                            FBI.add(i+1);
                            break;
                        }
                    } catch (StringIndexOutOfBoundsException e)
                    {}
                }
            }
        }
        if (FBI.size() == 0)
        {
            System.out.println("HE GOT AWAY!");
        } else {
            StringBuilder output = new StringBuilder();
            for (int num : FBI)
            {
                output.append(num + " ");
            }
            System.out.println(output.toString().strip());
        }
    }
}
