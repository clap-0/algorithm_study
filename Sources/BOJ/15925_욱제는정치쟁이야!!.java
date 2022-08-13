import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
    static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        arr = new int[N];
        String willUsed = st.nextToken();
      
        // 컴퓨터실 사용여부가 true면 0->1, 1->0으로 저장
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++)
                if(!willUsed.equals(st.nextToken()))
                    arr[i] |= (1 << j);
        }
      
        controlRow(N);
        controlColumn(N);
        controlRow(N);
        controlColumn(N);
        System.out.println(checkArr(N) ? "1" : "0");
    }

    // N개의 행에서 전원을 끌 수 있는 행들을 끈다.
    public static void controlRow(int N) {
        int half = N / 2;
        for (int i = 0; i < N; i++)
            if (Integer.bitCount(arr[i]) <= half)
                arr[i] = 0;
    }

    // N개의 열에서 전원을 끌 수 있는 열들을 끈다.
    public static void controlColumn(int N) {
        int half = N / 2;
        for (int i = 0; i < N; i++) {
            int bitCount = 0;
            for (int j = 0; j < N; j++)
                if ((arr[j] & (1 << i)) != 0)
                    ++bitCount;
            if (bitCount <= half) {
                for (int j = 0; j < N; j++)
                    if ((arr[j] & (1 << i)) != 0)
                        arr[j] ^= (1 << i);
            }
        }
    }

    // 모든 컴퓨터가 꺼져있는지 확인한다.
    public static boolean checkArr(int N) {
        for (int i = 0; i < N; i++)
            if (arr[i] != 0) return false;
        return true;
    }
}
