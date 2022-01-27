#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
pair<int,int> employees[100000];

typedef pair<pair<int,int>, int> triple;

struct compare {
  bool operator()(const triple a, const triple b) {
    // 선두의 사원들 중 근무일수가 더 높은 사람이 우선순위를 갖는다
    if(a.first.first != b.first.first) return a.first.first < b.first.first;
    // 근무일수가 같은 경우 화장실이 더 급한 사람이 우선순위를 갖는다
    else if(a.first.second != b.first.second) return a.first.second < b.first.second;
    // 화장실이 급한 정도가 같은 경우 줄번호가 더 낮은 사람이 우선순위를 갖는다
    else return a.second % M > b.second % M;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M >> K;
  for(int i=0; i<N; i++) cin >> employees[i].first >> employees[i].second;

  // pq에 M개의 줄의 선두인 사원들의 정보(근무일수, 화장실급함정도, 처음대기번호)를 저장한다
  priority_queue<triple, vector<triple>, compare> pq;
  for(int i=0; i<min(M,N); i++) pq.push({employees[i], i});

  int ans = 0;
  while(!pq.empty()) {
    int curr = pq.top().second;
    pq.pop();
    if(curr == K) break;
    // 화장실로 간 사람이 있던 줄의 다음 사람을 선두에 놓는다
    if(curr + M < N) pq.push({employees[curr + M], curr + M});
    ++ans;
  }
  cout << ans << '\n';
}
