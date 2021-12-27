#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<int> Q;
    
    Q.push(0);
    for(int num : numbers) {
        int qsize = Q.size();
        for(int i=0; i<qsize; i++) {
            int curr = Q.front();
            Q.pop();
            Q.push(curr + num);
            Q.push(curr - num);
        }
    }
    
    while(!Q.empty()) {
        if(Q.front() == target) answer++;
        Q.pop();
    }
    
    return answer;
}
