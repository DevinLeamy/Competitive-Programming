import java.io.*;

public class FromStoT {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int Q = Integer.parseInt(in.readLine());
        for (int i = 0; i < Q; i++){
            StringBuilder S = new StringBuilder(in.readLine());
            String T = in.readLine();
            StringBuilder P = new StringBuilder(in.readLine());
            int canTake = T.length() - S.length();
            int index = 0;
            if (S.toString().equals(T)){
                System.out.println("YES");
            } else if (canTake < 0){
                System.out.println("NO");
            } else {
                boolean isGood = true;
                for (int j = 0; j < T.length(); j++) {
                    String character = String.valueOf(T.charAt(j));
                    try {
                        if (String.valueOf(S.toString().charAt(index)).equals(character)) {
                            index++;
                            continue;
                        }
                    } catch (StringIndexOutOfBoundsException sioobe) { }
                    if (P.toString().contains(character) && canTake > 0) {
                        P = new StringBuilder(P.toString().replaceFirst(character, ""));
                        canTake--;
                        continue;
                    }
                    System.out.println("NO");
                    isGood = false;
                    break;
                }
                if (isGood) {
                    System.out.println("YES");
                }
            }
        }
    }
}
