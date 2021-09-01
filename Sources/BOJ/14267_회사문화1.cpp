#include <iostream>
#include <vector>
using namespace std;
vector<int> inferior[100001];
int praise[100001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  //i가 누구의 직속부하인지 입력받는다
  for (int i = 1; i <= n; i++){
    int k;
    cin >> k;
    if (k != -1) inferior[k].push_back(i);
  }
  //각 직원이 얼만큼 칭찬 받았는지 입력받는다
  while (m--){
    int v, w;
    cin >> v >> w;
    praise[v]+=w;
  }
  //i번째 직원이 받은 칭찬수치를 입력하고, i의 직속부하에게 같은 수치의 칭찬을 더한다
  for (int i = 1; i <= n; i++){
    cout << praise[i] << ' ';
    for(int next : inferior[i]) praise[next]+=praise[i];
  }
}
