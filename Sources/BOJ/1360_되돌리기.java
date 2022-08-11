import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      
        int N = Integer.parseInt(br.readLine());
        int[] time = new int[N + 1];  // i번째 명령을 내린 시간 저장
        String[] text = new String[N + 1];  // i번째 명령을 수행했을 때의 텍스트 저장
      
        text[0] = "";
        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            if (st.nextToken().equals("type")) {
                text[i] = text[i - 1] + st.nextToken(); // 이전 명령에서의 텍스트에 새로 입력받은 문자를 추가한다.
                time[i] = Integer.parseInt(st.nextToken());
            } else {
                int t = Integer.parseInt(st.nextToken());
                time[i] = Integer.parseInt(st.nextToken());
                t = time[i] - t - 1;  // t번째 명령을 수행했을 때로 되돌린다.
                text[i] = "";
                int lo = 0, hi = i - 1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (time[mid] <= t) {
                        lo = mid + 1;
                        text[i] = text[mid];
                    } else
                        hi = mid - 1;
                }
            }
        }
        System.out.println(text[N]);
    }
}
