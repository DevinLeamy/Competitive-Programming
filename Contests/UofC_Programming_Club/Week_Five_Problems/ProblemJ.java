import java.util.*;
import java.io.*;

public class ProblemJ {
    private static void setAndAdd(int currentMarker, boolean[][] isBinary, int[][] travel, int row, int col, ArrayList<int[]> newCurrent, boolean binary)
    {
        if (row >= isBinary.length || row < 0 || col >= isBinary[0].length || col < 0)
        {
            return;
        }
        if (binary) {
            if (isBinary[row][col] && travel[row][col] == 0)
            {
                travel[row][col] = currentMarker;
                newCurrent.add(new int[] {row, col});
            }
        } else {
            if (!isBinary[row][col] && travel[row][col] == 0)
            {
                travel[row][col] = currentMarker;
                newCurrent.add(new int[] {row, col});
            }
        }
    }
    private static void travel(int rowS, int colS, int rowF, int colF, boolean[][] isBinary, int[][] travelMap, int[] currentMarker, boolean binary)
    {
        int index = (binary)? 0 : 1;
        if (travelMap[rowS][colS] == 0 && travelMap[rowF][colF] == 0)
        {
            travelMap[rowS][colS] = currentMarker[index];
            ArrayList<int[]> current = new ArrayList<>();
            current.add(new int[] {rowS, colS});
            while (current.size() > 0)
            {
                ArrayList<int[]> newCurrent = new ArrayList<>();
                for (int[] place : current)
                {
                    setAndAdd(currentMarker[index], isBinary, travelMap, place[0]+1, place[1], newCurrent, binary);
                    setAndAdd(currentMarker[index], isBinary, travelMap, place[0], place[1]+1, newCurrent, binary);
                    setAndAdd(currentMarker[index], isBinary, travelMap, place[0]-1, place[1], newCurrent, binary);
                    setAndAdd(currentMarker[index], isBinary, travelMap, place[0], place[1]-1, newCurrent, binary);
                }
                current = new ArrayList<>(newCurrent);
            }
            currentMarker[index]++;
        }
        if (travelMap[rowS][colS] == travelMap[rowF][colF])
        {
            System.out.println((binary)? "binary" : "decimal");
        } else {
            System.out.println("neither");
        }
    }
    private static void canTravel(int rowS, int colS, int rowF, int colF, boolean[][] isBinary, int[][] binaryTravel, int[][] decimalTravel, int[] currentMarker)
    {
        if (isBinary[rowS][colS])
        {
            travel(rowS, colS, rowF, colF, isBinary, binaryTravel, currentMarker, true);
        } else {
            travel(rowS, colS, rowF, colF, isBinary, decimalTravel, currentMarker, false);
        }
    }
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer line;
        line = new StringTokenizer(in.readLine());
        int R = Integer.parseInt(line.nextToken());
        int C = Integer.parseInt(line.nextToken());
        boolean[][] isBinary = new boolean[R][C];
        int[][] binaryTravel = new int[R][C];
        int[][] decimalTravel = new int[R][C];

        for (int i = 0; i < R; i++)
        {
            String[] row = in.readLine().split("");
            for (int j = 0; j < C; j++)
            {
                isBinary[i][j] = row[j].equals("0");
            }
        }
        int N = Integer.parseInt(in.readLine());
        int[] currentMarker = {1, 1};
        for (int i = 0; i < N; i++)
        {
            line = new StringTokenizer(in.readLine());
            int rowS = Integer.parseInt(line.nextToken()) - 1;
            int colS = Integer.parseInt(line.nextToken()) - 1;
            int rowF = Integer.parseInt(line.nextToken()) - 1;
            int colF = Integer.parseInt(line.nextToken()) - 1;
            canTravel(rowS, colS, rowF, colF, isBinary, binaryTravel, decimalTravel, currentMarker);
        }
    }
}