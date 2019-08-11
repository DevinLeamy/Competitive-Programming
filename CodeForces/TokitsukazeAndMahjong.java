import java.util.*;
import java.io.*;

public class TokitsukazeAndMahjong {
    private static int best = Integer.MAX_VALUE;
    private static void getBest(List<Integer> set){
        if (set.size() == 0){
            compair(3);
        } else if (set.size() == 1){
            compair(2);
        } else if (set.size() == 2){
            if (set.get(0) == set.get(1)){
                compair(1);
            } else if (set.get(1) - set.get(0) == 1 || set.get(1) - set.get(0) == 2){
                compair(1);
            } else {compair(2);}
        } else {
            if (set.get(0) == set.get(1) && set.get(1) == set.get(2)){
                compair(0);
            } else if (set.get(0) + 1 == set.get(1) && set.get(1) + 1 == set.get(2)){
                compair(0);
            } else if (set.get(0) == set.get(1) || set.get(2) == set.get(1)){
                compair(1);
            } else if (set.get(1) - set.get(0) == 1 || set.get(1) - set.get(0) == 2 || set.get(2) - set.get(1) == 1 || set.get(2) - set.get(1) == 2){
                compair(1);
            } else {compair(2);}

        }
    }
    private static void compair(int num){
        if (num < best){
            best = num;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer cards = new StringTokenizer(in.readLine());
        List<Integer> m = new ArrayList<>();
        List<Integer> p = new ArrayList<>();
        List<Integer> s = new ArrayList<>();
        for (int i = 0; i < 3; i++){
            String[] card = cards.nextToken().split("");
            String suit = card[1];
            switch (suit){
                case "m":
                    m.add(Integer.parseInt(card[0]));
                    break;
                case "p":
                    p.add(Integer.parseInt(card[0]));
                    break;
                case "s":
                    s.add(Integer.parseInt(card[0]));
                    break;
            }
        }
        Collections.sort(m);
        Collections.sort(p);
        Collections.sort(s);
        getBest(m);
        getBest(p);
        getBest(s);
        System.out.println(best);
    }
}
