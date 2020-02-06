import java.io.*;
import java.util.*;

public class ProblemB {
    public static void main(String[] args) throws IOException {
        BufferedReader in =  new BufferedReader(new InputStreamReader(System.in));
        String s = in.readLine();
        String p = in.readLine();
        if (s.equals(p)) {
            System.out.println("Yes");
            return;
        }

        for (int i = 0; i <= 9; i++) {
            String c = i + "";
            if ((c + p).equals(s) || (p + c).equals(s)) {
                System.out.println("Yes");
                return;
            }
        }

        String caseR = "";
        for (int i = 0; i < p.length(); i++) {
            char c = p.charAt(i);
            if ((c + "").toUpperCase().equals(c + "")) {
                caseR += (c + "").toLowerCase();
            } else {
                caseR += (c + "").toUpperCase();
            }
        }
        if (caseR.equals(s)) {
            System.out.println("Yes");
            return;
        }

        System.out.println("No");
    }
}
