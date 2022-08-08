import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
    static final int[] DX = {-1, 0, 1, 0}, DY = {0, -1, 0, 1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        // ArrayList 2차원 배열 선언
        ArrayList<Integer>[] viruses = new ArrayList[K];
        for (int i = 0; i < K; i++)
            viruses[i] = new ArrayList<>();

        int[][] testTube = new int[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                int virus = Integer.parseInt(st.nextToken());
                testTube[i][j] = virus;
                // 각 바이러스의 번호별로 위치를 저장한다.
                if (virus > 0)
                    viruses[virus - 1].add(i * N + j);
            }
        }

        // 번호가 작은 바이러스부터 큐에 넣어 항상 먼저 전염이 시작되도록 한다.
        Queue<Integer> Q = new LinkedList<>();
        for (int i = 0; i < K; i++)
            Q.addAll(viruses[i]);

        st = new StringTokenizer(br.readLine());
        int S = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());
        int Y = Integer.parseInt(st.nextToken());

        while (S-- > 0) {
            int qSize = Q.size();
            while (qSize-- > 0) {
                int x = Q.peek() / N, y = Q.peek() % N;
                Q.poll();
                for (int i = 0; i < 4; i++) {
                    int nx = x + DX[i], ny = y + DY[i];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    // 인접한 시험관 칸에 바이러스가 없다면 바이러스가 전염된다.
                    if(testTube[nx][ny] == 0) {
                        testTube[nx][ny] = testTube[x][y];
                        Q.add(nx * N + ny);
                    }
                }
            }
        }

        System.out.println(testTube[X - 1][Y - 1]);
    }
}
