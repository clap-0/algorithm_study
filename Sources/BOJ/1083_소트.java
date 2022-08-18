import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(br.readLine());

        for (int i = 0; i < N && S > 0; i++) {
            int maxValue = arr[i], maxIndex = i;
            for (int j = i + 1; j < N && j - i <= S; j++)
                if (maxValue < arr[j]) {
                    maxValue = arr[j];
                    maxIndex = j;
                }
            System.arraycopy(arr, i, arr, i + 1, maxIndex - i);
            arr[i] = maxValue;
            S -= maxIndex - i;
        }

        for (int i = 0; i < N; i++)
            System.out.printf(arr[i] + " ");
    }
}
