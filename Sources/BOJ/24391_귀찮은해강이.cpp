import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.util.StringTokenizer;

public class Main {
    private static int[] uf = new int[100001];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
      
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            merge(u, v);
        }
      
        int ans = 0;
        st = new StringTokenizer(br.readLine());
        int prev = Integer.parseInt(st.nextToken());
        while (st.hasMoreTokens())
        {
            // 이전강의와 현재강의가 연결되어있지 않으면 ans를 증가시킨다.
            int curr = Integer.parseInt(st.nextToken());
            if (find(prev) != find(curr))
                ++ans;
            prev = curr;
        }
        System.out.println(ans);
    }

    // 유니온파인드 알고리즘
    public static int find(int n)
    {
        if(uf[n] == 0)
            return n;
        return uf[n] = find(uf[n]);
    }
    public static void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if(u == v)
            return;
        uf[v] = u;
    }
}
