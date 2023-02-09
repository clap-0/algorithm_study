#include <iostream>
#include <vector>
using namespace std;

string name[20];
vector<pair<int,int> > nasty;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int tc = 0;
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;

    nasty.clear();

    for (int i = 0; i < n; i++) {
      cin >> name[i];
      for (int j = 1; j < n; j++) {
        char msg;
        cin >> msg;
        if (msg == 'N')
          nasty.push_back({(i + n - j) % n, i});
      }
    }

    cout << "Group " << ++tc <<'\n';
    if (nasty.empty()) {
      cout << "Nobody was nasty\n";
    }
    else {
      for (pair<int,int> &p : nasty)
        cout << name[p.first] << " was nasty about " << name[p.second] << '\n';
    }
    cout << '\n';
  }
}
