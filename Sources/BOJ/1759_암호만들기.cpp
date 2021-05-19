#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const char vowels[5]={'a','e','i','o','u'};

vector<char> val; //암호로 사용했다는 알파벳 목록
vector<string> passwords; //가능성있는 암호목록
string candidate; //암호 후보
int candVowel; //암호 후보에 포함된 모음 수
int L, C;

void backtrack(int curr){
  if(candidate.size()==L){ //기저사례 : 후보글자수가 암호의 글자수만큼 되면 끝냄. 조건을 만족하면 목록에 추가
    if(candVowel>=1 && L-candVowel>=2) passwords.push_back(candidate);
    return;
  }
  if(curr==C) return; //기저사례 : 암호로 사용할만한 알파벳을 다 사용하면 끝냄
  
  bool isVowel=false; //목록중 curr번째 알파벳이 모음인지 확인
  for(char v : vowels)
    if(v==val[curr]) isVowel=true;
  
  //암호후보에 curr번째 알파벳을 넣고 시도
  candidate.push_back(val[curr]);
  if(isVowel) candVowel+=1;
  backtrack(curr+1);
  candidate.pop_back();
  if(isVowel) candVowel-=1;
  
  //암호후보에 curr번째 알파벳 포함시키지 않고 시도
  backtrack(curr+1);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> L >> C;
  for(int i=0; i<C; i++){
    char ch;
    cin >> ch;
    val.push_back(ch);
  }
  sort(val.begin(), val.end());
  backtrack(0);
  for(string word : passwords) cout << word << '\n';
}
