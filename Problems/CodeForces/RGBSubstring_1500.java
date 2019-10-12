import java.util.*;
import java.io.*;

public class RGBSubstring_1500 {
    private static void solve(int K, String N)
    {
        String rgb = "RGB";
        int min = K;
        for (int i = 0; i < N.length() - K + 1; i++)
        {
            for (int index = 0; index < 3; index++) {
                int hold = index;
                int changes = 0;
                for (int j = i; j < K + i; j++) {
                    if (changes > min) {break;}
                    if (N.charAt(j) != rgb.charAt(index)) {
                        changes++;
                    }
                    index++;
                    index = index % 3;
                }
                index = hold;
                if (changes < min) {
                    min = changes;
                }
            }
        }
        System.out.println(min);
    }
    public static void main(String[] args) throws IOException {
        int Q = nextInt();
        for (int i = 0; i < Q; i++){
            int L = nextInt(); int K = nextInt();
            String N = nextString();
            solve(K, N);
        }
    }
    private static StringTokenizer line = new StringTokenizer("");
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    private static int nextInt() throws IOException
    {
        return Integer.parseInt(nextString());
    }
    private static String nextString() throws IOException
    {
        if (line.hasMoreTokens())
        {
            return line.nextToken();
        } else {
            line = new StringTokenizer(in.readLine());
            return line.nextToken();
        }
    }
}
