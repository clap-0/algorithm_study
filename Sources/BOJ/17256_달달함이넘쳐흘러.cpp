#include <iostream>
using namespace std;
struct Cake {
  int x, y, z;
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  Cake a, c;
  cin >> a.x >> a.y >> a.z >> c.x >> c.y >> c.z;
  cout << c.x-a.z << " " << c.y/a.y << " " << c.z-a.x << '\n';
}
