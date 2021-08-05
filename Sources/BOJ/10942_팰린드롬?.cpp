#include <iostream>
#include <cstring>
using namespace std;
int arr[2001];
int cache[2001][2001];
//DP를 이용하여 start번째 수부터 end번째까지 수가 팰린드롬인지 반환한다
int isPalindrome(int start, int end){
  //기저사례 : 팰린드롬이 맞는 경우 1반환
  if(start>=end) return 1;
  //메모이제이션
  int& ret = cache[start][end];
  if(ret!=-1) return ret;
  //현재 범위의 양 끝 수가 서로 다른 경우 팰린드롬이 아니므로 0 반환
  if(arr[start]!=arr[end]) return ret=0;
  //범위의 양 끝을 제외하고 팰린드롬인지 확인한다
  return ret = isPalindrome(start+1, end-1);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, M;
  cin >> N;
  for(int i=1; i<=N; i++) cin >> arr[i];
  cin >> M;
  memset(cache, -1, sizeof(cache));
  while(M--){
    int S, E;
    cin >> S >> E;
    cout << isPalindrome(S, E) << '\n';
  }
}
