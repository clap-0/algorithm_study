#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int D, H, W;
  cin >> D >> H >> W;

  double x = sqrt(D * D) / sqrt(H * H + W * W);
  cout << (int)(H * x) << ' ' << (int)(W * x) << '\n';
}
