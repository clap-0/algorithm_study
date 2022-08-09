import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int K = Integer.parseInt(br.readLine());
        ++K;  // 계산하기 편하도록 K에 1을 더한다.
        StringBuilder stringBuilder = new StringBuilder();
        while (K > 1) {
            // 문자열에 맨 앞에 K가 짝수이면 4를, 홀수이면 7을 넣는다.
            if (K % 2 == 0) stringBuilder.insert(0, 4);
            else stringBuilder.insert(0, 7);
            K /= 2;
        }
        System.out.println(stringBuilder);
    }
}
