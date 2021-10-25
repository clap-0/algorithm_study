#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
// sort()의 비교함수
bool compare(pair<string,int> a, pair<string,int> b){
  // 1. 자주 나오는 단어일수록 앞에 배치한다.
  if(a.second!=b.second) return a.second>b.second;
  // 2. 해당 단어의 길이가 길수록 앞에 배치한다.
  if(a.first.length()!=b.first.length()) return a.first.length()>b.first.length();
  // 3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다
  return a.first<b.first;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, M;
  unordered_map<string, int> freqMap;
  cin >> N >> M;
  // 단어들을 입력받아 각 단어의 빈도수를 구한다
  for(int i=0; i<N; i++){
    string word;
    cin >> word;
    if(word.length()>=M) freqMap[word]++;
  }
  // 정렬을 하기 위해 map<string,int>에서 vector<string,int>로 변환해 저장한다
  vector<pair<string,int> > wordLists(freqMap.begin(), freqMap.end());
  sort(wordLists.begin(), wordLists.end(), compare);
  for(auto word : wordLists) cout << word.first << '\n';
}
