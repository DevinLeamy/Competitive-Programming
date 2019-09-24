import java.util.*;
import java.io.*;


public class ProblemI {
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer line = new StringTokenizer(in.readLine());
        int A = Integer.parseInt(line.nextToken());
        int B = Integer.parseInt(line.nextToken());
        long T = Long.parseLong(line.nextToken());
        int a = Integer.parseInt(line.nextToken());
        int b = Integer.parseInt(line.nextToken());
        int C = Integer.parseInt(in.readLine());
        ArrayList<Double> acceptOffers = new ArrayList<>();
        ArrayList<Double> rejectOffers = new ArrayList<>();

        for (int i = 0; i < C; i++)
        {
            line = new StringTokenizer(in.readLine());
            long E1 = Long.max(Long.parseLong(line.nextToken()) - A, 0);
            long E2 = Long.max(Long.parseLong(line.nextToken()) - B, 0);
            if (E1 * a + E2 * b <= T)
            {
                double add = ((T - (E2 * b)) / (double)(a));
                acceptOffers.add((double)E1);
                rejectOffers.add(add);
            }
        }
        Collections.sort(acceptOffers);
        Collections.sort(rejectOffers);

        long max = 0;
        long currentX = 0;
        int indexA = 0;
        int indexB = 0;
        while (indexA < acceptOffers.size())
        {
            double offer = acceptOffers.get(indexA);
            double rejection = rejectOffers.get(indexB);
            if (offer <= rejection)
            {
                max++;
                currentX = Long.max(currentX, max);
                indexA++;
            } else
                {
                    max--;
                    indexB++;
                }
        }
        System.out.println(currentX);
    }
}
