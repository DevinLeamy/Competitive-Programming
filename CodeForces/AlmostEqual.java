import java.io.*;

public class AlmostEqual {
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(in.readLine());
        if (N == 1)
        {
            print("YES");
            print(1 + " " + 2);
        } else {
            StringBuilder output = new StringBuilder();
            int start = 1;
            for (int i = 0; i < (N * 2); i++)
            {
                output.append(start);
                output.append(" ");
                if (start == (N * 2) - 1){
                    start = 2;
                    continue;
                }
                if (i % 2 == 0)
                {
                    start+= 3;
                } else {
                    start += 1;
                }
            }
            if (start == (N * 2) + 1)
            {
                print("YES");
                print(output.toString());
            } else {
                print("NO");
            }
        }
    }
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    private static void print(String value)
    {
        System.out.println(value);
    }

}
