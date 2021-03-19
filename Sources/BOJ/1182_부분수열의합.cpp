#include <iostream>
#include <vector>
using namespace std;
int n, s;
vector<int> seq(20);
int subseqCnt(int curr, int sum) //s와 값이 같은 부분수열의 합의 개수 반환
{
  if(curr==n) return 0;
  int ret=0, next=curr+1;
  if(sum + seq[curr] == s) ret++;
  ret += subseqCnt(next, sum)+subseqCnt(next, sum+seq[curr]); //curr을 부분수열의 포함하거나 안 했을 때 개수 반환
  return ret;
}
int main()
{
  cin >> n >> s;
  for(int i=0; i<n; i++) cin >> seq[i];
  cout << subseqCnt(0, 0) << endl;
  return 0;
}
