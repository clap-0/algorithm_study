import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
    static int[] histogram = new int[100000];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            // N이 0인 경우, 종료
            if (N == 0)
                break;
            for (int i = 0; i < N; i++)
                histogram[i] = Integer.parseInt(st.nextToken());

            // 히스토그램에서 가장 큰 직사각형을 구해 출력
            System.out.println(getLargestArea(0, N - 1));
        }
    }

    static long getLargestArea(int from, int to) {
        // 주어진 범위의 크기가 1인 경우, 해당 위치의 높이를 반환
        if (from == to)
            return histogram[from];

        int mid = (from + to) / 2;
        // 주어진 범위의 왼쪽 절반과 오른쪽 절반에서 가장 큰 직사각형의 크기를 구하여
        // 더 큰 넓이를 ret에 저장한다.
        long ret = Math.max(getLargestArea(from, mid), getLargestArea(mid + 1, to));

        // 범위의 가운데(mid)를 포함하는 가장 큰 직사각형의 크기를 구한다.
        int left = mid, right = mid;
        long height = histogram[mid];
        ret = Math.max(ret, height);  // 너비가 1이므로 넓이 = height
        // mid의 좌우측의 높이 중 더 높은 값을 선택해 넓이를 구한다.
        while (from < left && right < to) {
            if (histogram[left - 1] < histogram[right + 1])
                height = Math.min(height, histogram[++right]);
            else
                height = Math.min(height, histogram[--left]);
            ret = Math.max(ret, (right - left + 1) * height);
        }
        // 왼쪽 구간을 끝까지 구하지 못한 경우 마저 탐색한다.
        for (int i = left - 1; i >= from; i--)
            ret = Math.max(ret, (right - i + 1) * (height = Math.min(height, histogram[i])));
        // 오른쪽 구간을 끝까지 구하지 못한 경우 마저 탐색한다.
        for (int i = right + 1; i <= to; i++)
            ret = Math.max(ret, (i - left + 1) * (height = Math.min(height, histogram[i])));

        return ret;
    }
}
