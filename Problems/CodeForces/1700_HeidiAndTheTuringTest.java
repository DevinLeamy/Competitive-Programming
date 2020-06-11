import java.util.*;
import java.io.*;

public class HeidiAndTheTuringTest_1700 {
    public static void main(String[] args) throws IOException
    {
       int N = nextInt();
       int[] xCoords = new int[51];
       int[] yCoords = new int[51];
       int[][] coords = new int[51][2];
       for (int i = 0; i < ((4 * N) + 1); i++)
       {
           int X = nextInt();
           int Y = nextInt();
           xCoords[X]++;
           yCoords[Y]++;
           coords[i] = new int[] {X, Y};
       }
       int bottomX = -1;
       int topX = -1;
       int bottomY = -1;
       int topY = -1;
       for (int i = 0; i < 51; i++)
       {
           if (xCoords[i] > 1 && bottomX == -1)
           {
               bottomX = i;
           }
           if (yCoords[i] > 1 && bottomY == -1)
           {
               bottomY = i;
           }
           if (bottomX != -1)
           {
               if (xCoords[i] > 1)
               {
                   topX = i;
               }
           }
           if (bottomY != -1)
           {
               if (yCoords[i] > 1)
               {
                   topY = i;
               }
           }
       }
       for (int i = 0; i < 51; i++)
       {
           int X = coords[i][0];
           int Y = coords[i][1];
           if (X < topX && X > bottomX && Y != topY && Y != bottomY || Y < topY && Y > bottomY && X != bottomX && X != topX)
           {
               System.out.println(X + " " + Y);
               break;
           } else if (X > topX || X < bottomX || Y > topY || Y < bottomY)
           {
               System.out.println(X + " " + Y);
               break;
           }
       }

    }

    //Template
    private static StringTokenizer line = new StringTokenizer("");
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    private static int nextInt() throws IOException
    {
        return Integer.parseInt(nextString());
    }
    private static long nextLong() throws IOException
    {
        return Long.parseLong(nextString());
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
    private static String[] nextStringArray() throws IOException
    {
        return in.readLine().split(" ");
    }
    private static int[] nextIntArray() throws IOException
    {
        return Arrays.stream(nextStringArray()).mapToInt(Integer::parseInt).toArray();
    }
}
