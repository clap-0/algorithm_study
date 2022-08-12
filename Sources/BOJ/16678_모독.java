import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] honors = new int[N + 1];
        honors[0] = 0;
        for (int i = 1; i <= N; i++)
            honors[i] = Integer.parseInt(br.readLine());
        Arrays.sort(honors);
        long ans = 0;
        for (int i = 1; i <= N; i++)
            if (honors[i - 1] < honors[i]) {
                ans += (honors[i] - honors[i - 1] - 1);
                honors[i] = honors[i - 1] + 1;
            }
        System.out.println(ans);
    }
}
