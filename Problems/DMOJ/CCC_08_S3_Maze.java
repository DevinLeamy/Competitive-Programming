import java.util.*;
import java.io.*;

public class CCC_08_S3_Maze {
    private static boolean isValid(int row, int col, char[][] maze, int rows, int cols, boolean[][] visited) {
        if (row >= rows || row < 0 || col >= cols || col < 0 || maze[row][col] == '*' || visited[row][col]) {
            return false;
        }
        return true;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        char[][] maze;
        int t = Integer.parseInt(in.readLine());
        for (int i = 0; i < t; i++) {
            int r = Integer.parseInt(in.readLine());
            int c = Integer.parseInt(in.readLine());
            maze = new char[r][c];
            for (int j = 0; j < r; j++) {
                String line = in.readLine();
                for (int z = 0; z < c; z++){
                    maze[j][z] = line.charAt(z);
                }
            }
            boolean[][] visited = new boolean[r][c];
            Queue<int[]> queue = new LinkedList<>();
            queue.add(new int[] {0, 0, 1});
            int ans = -1;
            while (queue.size() > 0) {
                int[] values = queue.remove();
                int row = values[0];
                int col = values[1];
                int moves = values[2];
                if (visited[row][col]) {continue;}
                visited[row][col] = true;
                if (row == r-1 && col== c-1) {
                    ans = moves;
                    break;
                }
                if (maze[row][col] == '|' || maze[row][col] == '+') {
                    if (isValid(row+1, col, maze, r, c, visited)) {
                        queue.add(new int[] {row+1, col, moves+1});
                    }
                    if (isValid(row-1, col, maze, r, c, visited)) {
                        queue.add(new int[] {row-1, col, moves+1});
                    }
                }
                if (maze[row][col] == '-' || maze[row][col] == '+') {
                    if (isValid(row, col+1, maze, r, c, visited)) {
                        queue.add(new int[] {row, col+1, moves+1});
                    }
                    if (isValid(row, col-1, maze, r, c, visited)) {
                        queue.add(new int[] {row, col-1, moves+1});
                    }
                }
            }
            System.out.println(ans);
        }
    }
}