import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.regex.Pattern;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader((System.in)));
        int N = Integer.parseInt(br.readLine());
        String regex = "(01|100+1+)+";
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            String source = br.readLine();
            sb.append(Pattern.matches(regex, source) ? "YES\n" : "NO\n");
        }
        System.out.println(sb);
    }
}
