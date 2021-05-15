#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX=100000;

vector<vector<int> > adj; //인접리스트
int discovered[MAX], sccId[MAX]; //각 정점의 방문순서와 각 정점이 속한 SCC번호 저장
bool finished[MAX]; //해당 정점이 SCC로 묶였는지 여부
int counter, sccCnt;
stack<int> stk;

//타잔의 SCC분리 알고리즘
int tarjanSCC(int here){
  int ret = discovered[here] = ++counter;
  stk.push(here);
  for(int there : adj[here]){
    if(!discovered[there]) ret=min(ret, tarjanSCC(there));
    else if(!finished[there]) ret=min(ret, discovered[there]);
  }
  if(ret==discovered[here]){
    while(1){
      int tmp = stk.top(); stk.pop();
      sccId[tmp] = sccCnt;
      finished[tmp] = true;
      if(tmp==here) break;
    }
    ++sccCnt;
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int tc;
  cin >> tc;
  while(tc--){
    int n, m;
    cin >> n >> m;
    adj.clear(); adj.resize(n);
    fill(discovered, discovered+n, 0);
    fill(finished, finished+n, 0);
    sccCnt=counter=0;
    for(int i=0; i<m; i++){
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
    }
    
    for(int i=0; i<n; i++)
      if(!discovered[i]) tarjanSCC(i);
    
    int beginSection, secCnt=0; //indegree가 하나도 없는 SCC의 번호와 개수
    vector<bool> hasIndegree(sccCnt, false); //각 SCC로 들어오는 간선의 존재여부
    for(int i=0; i<n; i++)
      for(int j : adj[i])
        if(sccId[i]!=sccId[j]) hasIndegree[sccId[j]]=true;
    for(int i=0; i<sccCnt; i++)
      if(!hasIndegree[i]){ //들어오는 간선이 하나도 없는 SCC가 시작구역이다
        beginSection = i;
        secCnt++;
      }
    
    //들어오는 간선이 하나도 없는 SCC가 두 개 이상일 경우
    //해당 조건을 만족하는 한 SCC에서 다른 SCC로 가는 간선도 없다는 의미이므로
    //모든 구역에 도달가능하다는 시작구역의 전제에 어긋남
    if(secCnt==1){
      for(int i=0; i<n; i++)
        if(sccId[i]==beginSection) cout << i << '\n';
    }
    else cout << "Confused" << '\n';
    cout <<'\n';
  }
}
