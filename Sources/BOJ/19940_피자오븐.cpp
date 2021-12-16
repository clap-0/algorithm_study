#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    int N;
    int answer[5] = {0};
    cin >> N;

    int sixties = N/60, tens = (N%60)/10, ones = N%10;

    if(ones > 5){
      tens += 1;
      ones -= 10;
    }
    if(tens > 3){
      sixties += 1;
      tens -= 6;
    }
    if(tens < 0 && ones == 5){
      tens += 1;
      ones -= 10;
    }

    answer[0] = sixties;
    answer[2-(tens>=0)] = abs(tens);
    answer[4-(ones>=0)] = abs(ones);

    for(int ans : answer) cout << ans << ' ';
    cout << '\n';
  }
}
