#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b){
    if(b+a < a+b) return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNum;
    for(int n : numbers) strNum.push_back(to_string(n));
    sort(strNum.begin(), strNum.end(), compare);
    for(string str : strNum) answer += str;
    // strNum을 정렬했을 때 [0, 0, ... , 0] 인 경우 0이 된다
    if(answer[0]=='0') answer = "0";
    return answer;
}
