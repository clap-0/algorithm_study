#include <iostream>
#include <vector>
using namespace std;

bool adj[52][52];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  char proposition[10];
  cin >> N;
  // cin.getline()은 '\n'을 포함한 그 이전의 문자열을 buffer에서 가져오므로
  // 다음 N번의 cin.getline()이전에 input buffer를 flushing 한다.
  cin.getline(proposition, sizeof(proposition));
  for (int i = 0; i < N; i++)
  {
    cin.getline(proposition, sizeof(proposition));  // 명제 한 줄 전체를 input 받음
    int front = (isupper(proposition[0]) ? proposition[0] - 'A' : proposition[0] - 'a' + 26);
    int rear = (isupper(proposition[5]) ? proposition[5] - 'A' : proposition[5] - 'a' + 26);
    adj[front][rear] = true;
  }

  // 플로이드 알고리즘
  for (int k = 0; k < 52; k++)
    for (int i = 0; i < 52; i++)
    {
      if (!adj[i][k])
        continue;
      for (int j = 0; j < 52; j++)
        adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
    }

  vector<pair<char,char> > ans;
  for (int i = 0; i < 52; i++)
    for (int j = 0; j < 52; j++)
      if (adj[i][j] && i != j)
      {
        char front = (i < 26) ? i + 'A' : i - 26 + 'a';
        char rear = (j < 26) ? j + 'A' : j - 26 + 'a';
        ans.push_back({front, rear});
      }

  cout << ans.size() << '\n';
  for (auto &p : ans)
    cout << p.first << " => " << p.second << '\n';
}
