import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int D = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        // 오븐의 최상단이 1이고, 피자에 오븐이 모두 들어가지 않으면 0을 출력해야 하므로
        // 편의를 위해 오븐의 지름을 1번 인덱스부터 저장하고 0번 인덱스에는 주어지는 입력보다 큰 값을 넣는다.
        int[] ovensDiameter = new int[D + 1];
        ovensDiameter[0] = (int)1e9;
        // 상단의 오븐 지름보다 큰 피자 반죽은 어차피 현재 깊이에 들어오지 못하므로
        // 상단의 오븐 지름과 현재 오븐 지름 중 더 작은 쪽을 현재 지름으로 하여도 문제 될 게 없다.
        for (int i = 1; i <= D; i++)
            ovensDiameter[i] = Math.min(ovensDiameter[i - 1], Integer.parseInt(st.nextToken()));

        st = new StringTokenizer(br.readLine());
        int lastPos = D + 1;  // 마지막 피자 반죽의 위치
        for (int i = 0; i < N; i++) {
            int doughDiameter = Integer.parseInt(st.nextToken());
            // 배열 ovensDiameter가 내림차순으로 정렬되어 있으므로
            // 이분 탐색을 이용하여 [0, lastPos) 범위에서 doughDiameter보다 크거나 같은 가장 왼쪽에 있는 오븐의 깊이를 구한다.
            int lo = 0, hi = lastPos - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (ovensDiameter[mid] < doughDiameter)
                    hi = mid - 1;
                else {
                    lo = mid + 1;
                    lastPos = mid;
                }
            }
        }

        System.out.println(lastPos);
    }
}
