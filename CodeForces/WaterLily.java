import java.io.*;

public class WaterLily {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String[] input = in.readLine().split(" ");
        Double H = Double.parseDouble(input[0]);
        Double L = Double.parseDouble(input[1]);
        Double output = ((H * H) - (L * L)) / (-1 * 2 * H);
        System.out.println(output);
    }
}
