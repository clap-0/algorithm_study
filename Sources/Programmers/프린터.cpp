#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int> > Q;
    // 남은 문서중 가장 높은 중요도를 쉽게 구할 수 있게 우선순위큐 사용
    priority_queue<int> pq;
    for(int i=0; i<priorities.size(); i++){
        Q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    while(!Q.empty()){
        pair<int,int> curr=Q.front();
        Q.pop();
        // 큐의 가장 앞에 있는 문서의 중요도가 가장 높다면 바로 인쇄한다
        if(curr.first==pq.top()){
            answer++;
            pq.pop();
            if(curr.second==location) break;
        }
        else Q.push(curr);
    }
    return answer;
}
