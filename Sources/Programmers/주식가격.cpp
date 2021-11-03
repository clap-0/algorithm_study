#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int N = prices.size();
    vector<int> answer(N);
    stack<int> stk;
    for(int i=0; i<N; i++){
        while(!stk.empty() && prices[stk.top()]>prices[i]){
            int curr = stk.top();
            stk.pop();
            answer[curr] = i-curr;
        }
        stk.push(i);
    }
    while(!stk.empty()){
        int curr = stk.top();
        stk.pop();
        answer[curr] = N-curr-1;
    }
    return answer;
}
