import java.util.*;
import java.io.*;


public class Problem1A {
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        for (int i = 0; i < N; i++)
        {
            String line = in.readLine();
                try {
                    String start = line.substring(0, 10);
                    if (start.equals("Simon says"))
                    {
                        String output = line.substring(11).strip();
                        System.out.println(output);
                    }
                } catch (Exception e)
                {

                }

        }
    }
}
