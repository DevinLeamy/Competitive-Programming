import java.io.*;

public class ProblemD {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        long N = Long.parseLong(in.readLine());
        long length = N*2 - 1;
        long current = 1;
        int add = 1;
        long remainder = 0;
        StringBuilder output = new StringBuilder();
        for (long i = 0; i < length; i++)
        {
            long temp = remainder;
            current += remainder;
            if (current >= 10)
            {
                remainder = current / 10;
                output.append(current % 10);
            } else {
                output.append(current);
                remainder = 0;
            }
            if (i == N-1)
            {
                add *= -1;
            }
            current -= temp;
            current += add;
        }
        System.out.println(output.reverse().toString());

    }
}
