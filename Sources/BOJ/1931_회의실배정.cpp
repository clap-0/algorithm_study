#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  pair<int,int> meeting[100000];
  cin >> N;
  for(int i=0; i<N; i++) cin >> meeting[i].second >> meeting[i].first;
  //할 수 있는 회의 중 가장 빨리 끝나는 회의부터 하는 게 항상 최적해가 나온다
  sort(meeting, meeting+N);
  //begin = 다음 회의를 시작할 수 있는 시간 (==이전회의가 끝난시간)
  int maxCnt=0, begin=0;
  for(int i=0; i<N; i++)
    if(begin<=meeting[i].second){
      maxCnt++;
      begin=meeting[i].first;
    }
  cout << maxCnt << '\n';
}
