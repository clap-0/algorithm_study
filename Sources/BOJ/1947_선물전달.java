import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    static int[] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        if (N == 1)
            System.out.println(0);
        else {
            dp = new int[N + 1];
            dp[1] = 0;
            dp[2] = 1;
            // i명의 사람들이 각자 선물을 나누는 경우의 수(dp[i])는
            // 자신을 제외한 다른 사람들에게 선물을 주는 경우의 수(i - 1) 곱하기
            // 처음 받은 사람이 처음 준 사람이 아닌 다른 사람에게 줄 때의 경우의 수(dp[i - 1])와
            // 처음 받은 사람이 처음 준 사람에게 줄 때의 경우의 수(dp[i - 2])의 합이다.
            // dp[i - 1]의 경우 처음 준 사람과 처음 받은 사람을 한 사람으로 간주하고 그려보면 편하다.
            for (int i = 3; i <= N; i++)
                dp[i] = (int)((long)(i - 1) * (dp[i - 1] + dp[i - 2]) % 1000000000);
            System.out.println(dp[N]);
        }
    }
}
