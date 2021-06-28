#include <iostream>
using namespace std;
int N, known;
int antarcWords[50];
string basic = "acint", letters="bdefghjklmopqrsuvwxyz";
int countReadable(int prev, int K){
  if(K==0){
    int cnt=0;
    for(int i=0; i<N; i++)
      if(!(antarcWords[i] & ~known)) cnt++;
    return cnt;
  }
  int ret=0;
  for(int i=prev+1; i<21; i++){
    known ^= (1<<(letters[i]-'a'));
    ret=max(ret, countReadable(i, K-1));
    known ^= (1<<(letters[i]-'a'));
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int K;
  cin >> N >> K;
  for(int i=0; i<N; i++){
    string word;
    cin >> word;
    for(int j=0; j<word.size(); j++) antarcWords[i] |= (1<<(word[j]-'a'));
  }
  if(K>=5){
    for(int i=0; i<5; i++) known |= (1<<(basic[i]-'a'));
    cout << countReadable(-1, K-5) << '\n';
  }
  else puts("0");
}
