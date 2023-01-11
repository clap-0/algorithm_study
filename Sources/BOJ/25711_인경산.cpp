#include <iostream>
#include <cmath>
using namespace std;

int x[200000];
double psum[200001], psum_inverse[200001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, Q;
  cin >> N >> Q;
  for (int i = 0; i < N; i++)
    cin >> x[i];
  
  int prevY, currY;
  cin >> prevY;
  for (int i = 1; i < N; i++) {
    cin >> currY;
    double dist = sqrt(pow(x[i] - x[i - 1], 2) + pow(currY - prevY, 2));
    if (prevY < currY) {  // 현재 산장의 높이가 이전 산장의 높이보다 높은 경우
      psum[i + 1] = psum[i] + dist * 3;
      psum_inverse[i + 1] = psum_inverse[i] + dist;
    }
    else if (prevY == currY) {  // 현재 산장과 이전 산장의 높이가 같은 경우
      psum[i + 1] = psum[i] + dist * 2;
      psum_inverse[i + 1] = psum_inverse[i] + dist * 2;
    }
    else {  // 현재 산장의 높이가 이전 산장의 높이보다 낮은 경우
      psum[i + 1] = psum[i] + dist;
      psum_inverse[i + 1] = psum_inverse[i] + dist * 3;
    }
    prevY = currY;
  }

  while (Q--) {
    int i, j;
    cin >> i >> j;
    cout << (i < j ? psum[j] - psum[i] : psum_inverse[i] - psum_inverse[j]) << '\n';
  }
}
