import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int n = sc.nextInt();
      
        // public String repeat​(int count);
        // since java 11
        System.out.println(str.repeat(n));
    }
}
