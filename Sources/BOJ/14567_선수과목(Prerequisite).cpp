#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, M;
  int indegrees[1000]={0}, completion[1000];
  vector<int> next[1000];
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int A, B;
    cin >> A >> B;
    next[A-1].push_back(B-1);
    indegrees[B-1]++;
  }
  //위상정렬 알고리즘
  queue<int> Q;
  //선수과목이 없는 과목부터 공부한다
  for(int i=0; i<N; i++)
    if(indegrees[i]==0){
      Q.push(i);
      completion[i]=1;
    }
  for(int i=0; i<N; i++){
    int pre = Q.front(); Q.pop();
    //이 과목 다음에 공부해야 할 과목의 선수과목을 모두 이수했으면
    //이 과목을 공부하고, 이수 학기를 최신화한다
    for(int subject : next[pre])
      if(--indegrees[subject]==0){
        Q.push(subject);
        completion[subject] = completion[pre]+1;
      }
  }
  for(int i=0; i<N; i++) cout << completion[i] << ' ';
}
