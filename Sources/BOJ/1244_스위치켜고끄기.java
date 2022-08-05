import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int switchCnt = Integer.parseInt(br.readLine());
        int[] switches = new int[switchCnt + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        // 편의를 위해 1번 인덱스부터 저장
        for (int i = 1; i <= switchCnt; i++)
            switches[i] = Integer.parseInt(st.nextToken());

        int studentCnt = Integer.parseInt(br.readLine());
        for (int i = 0; i < studentCnt; i++) {
            st = new StringTokenizer(br.readLine());
            int gender = Integer.parseInt(st.nextToken());
            int number = Integer.parseInt(st.nextToken());
            // 남자인 경우 number의 배수들의 스위치 토글
            if (gender == 1)
                for (int j = number; j <= switchCnt; j += number)
                    switches[j] ^= 1;
            // 여자인 경우 number를 중심으로 대칭인 구간의 스위치 토글
            else {
                int diff = 0;
                while (1 <= number - diff && number + diff <= switchCnt && switches[number - diff] == switches[number + diff]) {
                    switches[number - diff] = switches[number + diff] ^= 1;
                    ++diff;
                }
            }
        }

        for (int i = 1; i <= switchCnt; i++) {
            System.out.print(switches[i] + " ");
            // 한 줄에 20개씩 출력
            if (i % 20 == 0)
                System.out.println();
        }
    }
}
