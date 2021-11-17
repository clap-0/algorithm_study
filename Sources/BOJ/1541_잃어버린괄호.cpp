#include <iostream>
#include <string>
using namespace std;

string formula;

//formula의 [start, end) 범위에 있는 모든 수를 더한 값을 반환한다
int sumRangeOf(int start, int end){
  int ret=0;
  // start == end일 때 18번줄에서 stoi(temp)가 0이 되도록 하기 위해 "0"으로 초기화 했다
  string temp="0";
  // [start, end)의 수들을 해당 범위에 있는 기호들을 무시하고 모두 더한다
  for(int i=start; i<end; i++){
    char c = formula[i];
    if('0'<=c && c<='9') temp += c;
    else{
      ret += stoi(temp);
      temp = "0";
    }
  }
  ret += stoi(temp);
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  getline(cin, formula);
  
  // minusIdx = formula 식에서 가장 왼쪽에 있는 '-'의 인덱스번호
  int formulaLen = formula.size(), minusIdx = formulaLen;
  for(int i=0; i<formulaLen; i++)
    if(formula[i] == '-'){
      minusIdx = i;
      break;
    }
  
  // 괄호를 적절히 쳐서 식의 값을 최소화하면 가장 왼쪽에 있는 '-'를 기준으로 좌우의 수들을 각각 모두 더한 값의 차이다
  // 예를 들어 O+O-O+O-O+O => O+O-(O+O)-(O+O) => (O+O)-(O+O+O+O)
  int ans = sumRangeOf(0, minusIdx) - sumRangeOf(minusIdx+1, formulaLen);
  cout << ans << '\n';
}
