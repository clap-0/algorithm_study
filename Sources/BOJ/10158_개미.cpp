#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int w, h, p, q, t;
  cin >> w >> h >> p >> q >> t;

  int x, y;
  if(p + t < w) x = p + t;
  else {
    int tmp = (p + t - w) % (2*w);
    x = (tmp < w ? w - tmp : tmp - w);
  }
  
  if(q + t < h) y = q + t;
  else {
    int tmp = (q + t - h) % (2*h);
    y = (tmp < h ? h - tmp : tmp - h);
  }
  cout << x << ' ' << y << '\n';
}
