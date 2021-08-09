#include <iostream>
#include <cstring>
using namespace std;
int arr[5000];
int cache[5000][5000];
//DP를 사용해 [left,right] 범위에 있는 수열이 팰린드롬이 되기 위해
//끼워넣어야 할 수의 최소개수를 구한다
int countInsert(int left, int right){
  //기저사례 : 수열을 전부 확인한 경우
  if(right<=left) return 0;
  //메모이제이션
  int& ret=cache[left][right];
  if(ret!=-1) return ret;
  //수열의 양 끝이 서로 같으면 양 끝을 지우고,
  //서로 다르다면 양 끝의 두 수 중 어느 수를 끼워넣을지 정한다
  if(arr[left]==arr[right]) return ret=countInsert(left+1, right-1);
  return ret=1+min(countInsert(left+1, right), countInsert(left, right-1));
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  for(int i=0; i<N; i++) cin >> arr[i];
  memset(cache, -1, sizeof(cache));
  cout << countInsert(0, N-1) << '\n';
}
