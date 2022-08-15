import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        String T = br.readLine();
        System.out.println(canMakeTtoS(new StringBuilder(T), S) ? "1" : "0");
    }

    // T를 S로 바꿀 수 있으면 true, 아니면 false 반환
    static boolean canMakeTtoS(StringBuilder T, final String S) {
        // T의 길이가 S의 길이와 같아졌다면 T와 S가 같은지 확인한다.
        if (S.length() == T.length())
            return T.toString().equals(S);

        boolean ret = false;
        // T의 마지막 문자가 'A'면 마지막 문자를 지우고 재귀호출한다.
        if (T.charAt(T.length() - 1) == 'A') {
            ret |= canMakeTtoS(T.deleteCharAt(T.length() - 1), S);
            T.append('A');
        }
        // T의 첫 번째 문자가 'B'면 첫 번째 문자를 지우고, 문자열을 뒤집은 다음 재귀호출한다.
        if (T.charAt(0) == 'B') {
            ret |= canMakeTtoS(T.deleteCharAt(0).reverse(), S);
            T.append('B').reverse();
        }
        return ret;
    }
}
