import java.util.*;
import java.io.*;

public class DistinctCharacterQueries {
    private static String ALPHABET = "abcdefghijklmnopqrstuvwxyz";
    private static int[] build(int treeIndex, int start, int end, int[][] tree, String[] string1)
    {
        if (start == end) //Leaf node
        {
            tree[treeIndex][ALPHABET.indexOf(string1[end])]++;
            return tree[treeIndex];
        } else {
            int mid = (start + end)/2;
            int[] left = build(treeIndex * 2, start, mid, tree, string1);
            int[] right = build(2*treeIndex + 1, mid+1, end, tree, string1);
            for (int i = 0; i < 26; i++)
            {
                tree[treeIndex][i] = left[i] + right[i];
            }
            return tree[treeIndex];
        }
    }

    private static void update(int treeIndex, int start, int end, int index, int[][] tree, int oldIndex, int newIndex)
    {
        if (start == end)
        {
            tree[treeIndex][oldIndex]--;
            tree[treeIndex][newIndex]++;
        } else {
            tree[treeIndex][oldIndex]--;
            tree[treeIndex][newIndex]++;
            int mid = (start + end)/2;
            if (start <= index && index <= mid)
            {
                update(2*treeIndex, start, mid, index, tree, oldIndex, newIndex);
            } else {
                update(2*treeIndex + 1, mid+1, end, index, tree,  oldIndex, newIndex);
            }
        }
    }

    private static int unique(int[] substring)
    {
        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (substring[i] > 0)
            {
                count++;
            }
        }
        return count;
    }
    private static int[] query(int treeIndex, int start, int end, int l, int r, int[][] tree)
    {
        if (r < start || end < l)
        {
            return new int[26];
        }
        if (l <= start && end <= r)
        {
            return tree[treeIndex];
        } else {
            int mid = (start + end)/2;
            int[] left = query(2*treeIndex, start, mid, l, r, tree);
            int[] right = query(2*treeIndex + 1, mid+1, end, l, r, tree);
            int[] root = new int[26];
            for (int i = 0; i < 26; i++)
            {
                root[i] += left[i] + right[i];
            }
            return root;
        }
    }

    public static void main(String[] args) throws IOException {
        String[] string1 = nextString().split("");
        int Q = nextInt();
        int[][] tree = new int[400000][26];
        build(1, 0, string1.length -1, tree, string1);
        for (int i = 0; i < Q; i++)
        {
            int command = nextInt();
            if (command == 1)
            {
                int index = nextInt() - 1;
                String newCharacter = nextString();
                int oldIndex = ALPHABET.indexOf(string1[index]);
                int newIndex = ALPHABET.indexOf(newCharacter);
                update(1, 0, string1.length - 1, index, tree, oldIndex, newIndex);
                string1[index] = newCharacter;
            } else {
                int L, R;
                L = nextInt()-1;
                R = nextInt()-1;
                System.out.println(unique(query(1, 0, string1.length-1, L, R, tree)));
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