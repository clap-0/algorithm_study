#include <iostream>
#include <algorithm>
using namespace std;

int U[1000];
// x번째 수와 y번째 수의 합
int XY[499500];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> U[i];

  sort(U, U + N);

  /* U[x] + U[y] + U[z] == U[k]를 만족하는 U[k]를 찾아야 하므로
     U[x] + U[y] == U[k] - U[z]에 대하여 좌변과 우변을 따로 구한다 */
  
  // 모든 (U[x] + U[y])를 구한다
  int count = 0;
  for(int x = 0; x < N - 1; x++)
    for(int y = x; y < N - 1; y++)
      XY[count++] = U[x] + U[y];

  sort(XY, XY + count);

  // (U[k] - U[z]) 값들 중에 배열 XY내에 있는 값이 있으면
  // 해당 k에 대하여 U[x] + U[y] + U[z] == U[k]를 만족하는 U[k]가 존재한다
  for(int k = N - 1; k > 0; k--) 
    for(int z = k - 1; z >= 0; z--) 
      if(binary_search(XY, XY + count, U[k] - U[z])) {
        cout << U[k] << '\n';
        return 0;
      }
}
