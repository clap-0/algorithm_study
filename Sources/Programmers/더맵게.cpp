#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());
    while(pq.top() < K){
        // 모든 음식의 스코빌지수를 K이상으로 만들 수 없는 경우 -1을 리턴
        if(pq.size()<2) return -1;
        int first, second;
        first = pq.top();
        pq.pop();
        second = pq.top();
        pq.pop();
        pq.push(first+second*2);
        ++answer;
    }
    return answer;
}
