import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();

        // StringBuilder : public StringBuilder​(int capacity)
        StringBuilder b = new StringBuilder(a.length());

        // String에 forEach 불가능. Character Array로 변환한 다음에 해야 함
        for (char ch : a.toCharArray()) {
            // Character : public static boolean isUpperCase​(char ch)
            if (Character.isUpperCase(ch)) {
                // StringBuilder : public StringBuilder append​(char c)
                // Character : public static char toLowerCase​(char ch)
                b.append(Character.toLowerCase(ch));
            } else {
                b.append(Character.toUpperCase(ch));
            }
        }
        System.out.println(b);
    }
}
