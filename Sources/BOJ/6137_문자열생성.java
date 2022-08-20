import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        char[] S = new char[N];
        for (int i = 0; i < N; i++)
            S[i] = br.readLine().charAt(0);

        int lo = 0, hi = N - 1;
        int cnt = 0;
        StringBuilder sb = new StringBuilder();
        while (lo <= hi) {
            // 문자열 S의 양 끝 문자가 다른 경우, 사전순으로 앞서는 문자를 sb에 넣는다.
            if (S[lo] != S[hi])
                sb.append(S[lo] < S[hi] ? S[lo++] : S[hi--]);
            else {
                int tmpLo = lo, tmpHi = hi;
                while (tmpLo < tmpHi && S[tmpLo] == S[tmpHi]) {
                    ++tmpLo; --tmpHi;
                }
                sb.append(S[tmpLo] < S[tmpHi] ? S[lo++] : S[hi--]);
            }
            // 80자마다 줄바꿈
            if (++cnt % 80 == 0)
                sb.append('\n');
        }
        System.out.println(sb);
    }
}
