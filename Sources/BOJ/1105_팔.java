import java.io.*;
import java.util.StringTokenizer;

class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    String L = st.nextToken();
    String R = st.nextToken();

    int ans = 0;
    // L과 R의 길이가 다르면 ans = 0
    if (L.length() == R.length()) {
      int len = L.length();
      // 제일 큰 자릿수부터 L과 R의 해당 자릿수가 둘 다 8인지 비교한다.
      // 두 값이 서로 다르다면 탐색을 종료한다.
      for (int i = 0; i < len && L.charAt(i) == R.charAt(i); i++)
        if (L.charAt(i) == '8')
          ++ans;
    }
    System.out.println(ans);
  }
}
