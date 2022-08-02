#include <iostream>
#include <cmath>
using namespace std;

string colors[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int value[3];
  string color;
  for(int i = 0; i < 3; i++)
  {
    cin >> color;
    for(int j = 0; j < 10; j++)
      if(colors[j] == color)
      {
        value[i] = j;
        break;
      }
  }
  
  int ans = value[0] * 10LL + value[1];
  for(int i = 0; i < value[2]; i++)
    ans *= 10;

  cout << ans;
}
