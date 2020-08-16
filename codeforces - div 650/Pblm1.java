import java.util.Scanner;

public class Pblm1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        while (t > 0) {
            --t;
            String s = scan.next();
            String res = "";
            res += s.charAt(0);
            res += s.charAt(1);
            for (int i = 3; i < s.length(); i += 2) {
                res += s.charAt(i);
            }
            System.out.println(res);
        }
    }
}