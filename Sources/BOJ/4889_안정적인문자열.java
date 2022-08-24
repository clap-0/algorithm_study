import java.io.*;

class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    int tc = 0;
    while (true) {
      String str = br.readLine();
      if (str.charAt(0) == '-')
        break;
      int ans = 0;
      int open = 0; // 닫히지 않은 여는괄호('{')의 개수
      for (int i = 0; i < str.length(); i++) {
        char ch = str.charAt(i);
        if (ch == '{') {
          ++open;
        } else {
          if (open > 0)
            --open;
          else { // 닫을 여는괄호가 없을 경우, 닫는괄호를 여는괄호로 바꾼다.
            ++open;
            ++ans;
          }
        }
      }
      ans += open / 2; // 남아있는 여는괄호들 중 반을 닫는괄호로 바꾼다.
      sb.append(++tc).append(". ").append(ans).append('\n');
    }
    System.out.println(sb);
  }
}
