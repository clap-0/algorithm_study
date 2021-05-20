#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool used[30];
vector<int> permutation;
bool isFound;
string seq;

void backtrack(int curr){
  //공백이 사라진 수열의 끝까지 확인한 경우
  if(curr>=seq.size()){
    int n=permutation.size();
    for(int i=1; i<=n; i++) //순열이 1부터 n까지의 수로 이루어졌는지 확인
      if(!used[i]) return;
    isFound=true;
    return;
  }
  //현위치에서 한자릿수만 원래 수열의 수라고 보고 시도
  int single = seq[curr]-'0';
  if(!used[single]){
    used[single]=true;
    permutation.push_back(single);
    backtrack(curr+1);
    if(isFound) return;
    used[single]=false;
    permutation.pop_back();
  }
  //현위치에서 두자릿수가 원래 수열의 수라고 보고 시도
  if(curr+1==seq.size()) return; //두자릿수를 만드는게 불가능한 경우
  int two = single*10+(seq[curr+1]-'0');
  if(!used[two]){
    used[two]=true;
    permutation.push_back(two);
    backtrack(curr+2);
    if(isFound) return;
    used[two]=false;
    permutation.pop_back();
  }
}

int main()
{
  cin >> seq;
  used[0]=true;
  backtrack(0);
  for(int num : permutation) cout << num << ' ';
}
