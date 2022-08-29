import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    // N이 3일 때의 별 찍기 모양
    static final char[][] triangle = new char[][]{
        {' ',' ','*',' ',' '},
        {' ','*',' ','*',' '},
        {'*','*','*','*','*'}
    };
    static char[][] ans;
  
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      
        int N = Integer.parseInt(br.readLine());
      
        ans = new char[N][N * 2 - 1];
        for (char[] row : ans)
            Arrays.fill(row, ' ');  // 빈 공간은 공백문자(' ')로 채운다.
      
        divideAndConquer(0, 0, N);  // 0행 0열부터 N개의 줄에 별을 찍는다.
        for (char[] row : ans)
            System.out.println(row);
    }

    static void divideAndConquer(int r, int c, int length) {
        // 길이가 3인 경우, r행 c열을 좌상단으로 하여 3개 줄에 별들을 찍는다.
        if (length == 3) {
            for (int i = 0; i < 3; i++)
                System.arraycopy(triangle[i], 0, ans[r + i], c, triangle[i].length);
            return;
        }
        divideAndConquer(r, c + length / 2, length / 2);          // length개 줄의 삼각형의 위쪽 절반 삼각형을 나누어 구한다.
        divideAndConquer(r + length / 2, c, length / 2);          // length개 줄의 삼각형의 아래쪽 절반의 왼쪽 삼각형을 구한다.
        divideAndConquer(r + length / 2, c + length, length / 2); // length개 줄의 삼각형의 아래쪽 절반의 오른쪽 삼각형을 구한다.
    }
}
