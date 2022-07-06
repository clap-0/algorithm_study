#include <iostream>
using namespace std;

int n;
// oppositeSide[i][j] = i번 주사위의 숫자 j의 맞은편에 있는 숫자
int oppositeSide[10000][7];

// 밑면의 숫자가 baseSide인 dice번째 주사위부터 n번 주사위까지 쌓을 때
// 옆면의 숫자들의 합을 반환한다.
int getMaxSideNumbers(int dice, int baseSide)
{
  // n개의 주사위를 다 쌓은 경우 0 반환
  if(dice == n)
    return 0;
  // upperSide = dice번 주사위의 윗면 숫자
  int upperSide = oppositeSide[dice][baseSide];
  // ret = dice번 주사위의 옆면에 있는 가장 큰 수
  int ret = (baseSide != 6 && upperSide != 6 ? 6 : (baseSide != 5 && upperSide != 5 ? 5 : 4));
  return ret + getMaxSideNumbers(dice + 1, upperSide);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
  {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    oppositeSide[i][a] = f; oppositeSide[i][f] = a;
    oppositeSide[i][b] = d; oppositeSide[i][d] = b;
    oppositeSide[i][c] = e; oppositeSide[i][e] = c;
  }

  int ans = 0;
  for(int i = 1; i <= 6; i++)
    ans = max(ans, getMaxSideNumbers(0, i));

  cout << ans << '\n';
}
