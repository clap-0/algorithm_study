#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N, K;
//holes[i]=i번 나무에 있는 구멍들의 높이
vector<int> holes[100];
int cache[101][21];
//DP를 이용하여 현재 tree번째 나무의 height높이에 있는 구멍에 있을 때
//마지막 나무까지 안전하게 통과하기 위해 필요한 T기능의 수를 구한다
int countNeededTP(int tree, int height){
  //기저사례: 마지막 나무에 도착한 경우 0 반환
  if(tree+1==N) return 0;
  //메모이제이션
  int& ret=cache[tree+1][height];
  if(ret!=-1) return ret;
  ret=1000;
  //다음 나무에 있는 구멍 중에서 선택했을 때 T기능을 덜 쓰는 구멍을 선택한다
  //이때 O나 A,B,C기능들을 통해 갈 수 없는 곳인 경우 T를 사용해 가는 것도 고려한다
  for(int nextHole : holes[tree+1])
    ret=min(ret, countNeededTP(tree+1, nextHole)+!(nextHole==height||nextHole==height+1||nextHole==min(height*2,20)||nextHole==height-1));
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N >> K;
  for(int i=0; i<N; i++){
    int M;
    cin >> M;
    while(M--){
      int height;
      cin >> height;
      holes[i].push_back(height);
    }
  }
  memset(cache, -1, sizeof(cache));
  int minTP=countNeededTP(-1,1);
  cout << (minTP<=K ? minTP : -1) << '\n';
}
