#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> stk;
    int iter = 0, N = number.length();
    
    while(k > 0){
        // 1. 가장 왼쪽의 a < b를 만족하는 a를 지운다 (417725에서 1)
        // 2. 1의 조건을 만족하는 수가 없는 경우 마지막 수를 지운다 (775에서 5)
        if((!stk.empty() && stk.top() < number[iter]) || iter == N){
            stk.pop();
            --k;
        }
        else {
            stk.push(number[iter++]);
        }
    }
    
    while(!stk.empty()){
        answer = stk.top() + answer;
        stk.pop();
    }
    for(int i=iter; i<N; i++){
        answer += number[i];
    }
    
    return answer;
}
