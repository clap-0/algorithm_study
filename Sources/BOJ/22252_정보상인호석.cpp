#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<string, priority_queue<int> > nameToPq;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int Q;
  long long ans = 0;
  cin >> Q;
  while(Q--) {
    int num, k;
    string name;
    cin >> num >> name >> k;
    if(num == 1) {
      for(int i=0; i<k; i++) {
        int C;
        cin >> C;
        nameToPq[name].push(C);
      }
    }
    else {
      while(k-- && !nameToPq[name].empty()) {
        ans += nameToPq[name].top();
        nameToPq[name].pop();
      }
    }
  }
  cout << ans << '\n';
}
