import java.util.*;
import java.io.*;

public class PlusFromPicture_1300 {
    public static void main(String[] args) throws IOException
    {
        int H = nextInt();
        int W = nextInt();
        String[][] picture = new String[H][W];
        int[] first = {-1, -1};
        for (int i = 0; i < H; i++)
        {
            String line = nextString();
            for (int j = 0; j < W; j++)
            {
                String value = String.valueOf(line.charAt(j));
                if (value.equals("*"))
                {
                    if (first[0] == -1)
                    {
                        first[0] = i;
                        first[1] = j;
                    }
                }
                picture[i][j] = value;
            }
        }
        boolean[][] visited = new boolean[H][W];
        int lineDownLen = 0;
        int width = 1;
        boolean good = true;
        boolean foundCenter = false;
        if (first[0] == -1 || first[1] == 0 || first[1] == H-1)
        {
            System.out.println("NO");
        } else {
            for (int i = first[0]; i < H; i++)
            {
                if (picture[i][first[1]].equals("*"))
                {
                    visited[i][first[1]] = true;
                    lineDownLen += 1;
                    if (!foundCenter && picture[i][first[1]+1].equals("*") && picture[i][first[1]+1].equals("*"))
                    {
                        if (i == H-1)
                        {
                            good = false;
                        }
                        try {
                            if (!picture[i+1][first[1]].equals("*"))
                            {
                                good = false;
                            }
                        } catch (ArrayIndexOutOfBoundsException aioobe){}
                        foundCenter = true;
                        for (int w = first[1] + 1; w < W; w++)
                        {
                            if (picture[i][w].equals("*"))
                            {
                                visited[i][w] = true;
                                width++;
                            } else {
                                break;
                            }
                        }
                        for (int w = first[1] - 1; w >= 0; w--)
                        {
                            if (picture[i][w].equals("*"))
                            {
                                visited[i][w] = true;
                                width++;
                            } else {
                                break;
                            }
                        }
                    }
                } else {
                    break;
                }
            }
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    if (!visited[i][j])
                    {
                        if (picture[i][j].equals("*"))
                        {
                            good = false;
                        }
                    }
                }
            }
            if (good && foundCenter)
            {
                System.out.println("YES");
            } else {
                System.out.println("NO");
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
