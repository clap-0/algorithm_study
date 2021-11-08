#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> P;

int solution(vector<vector<int>> jobs) {
    int answer = 0, N=jobs.size();
    // 요청부터 종료까지 걸리는 시간의 평균을 최소화하기 위해
    // 소요시간이 짧은 것부터 처리한다
    priority_queue<P, vector<P>, greater<P> > pq;
    // 요청시간에 대해 오름차순 정렬
    sort(jobs.begin(), jobs.end());
    int start=0, iter=0;
    for(int i=0; i<N; i++){
        // 현재 시각 start이전에 이미 요청된 작업들을
        // 소요시간에 대해 오름차순 정렬되도록 우선순위큐에 넣는다
        while(iter<N && jobs[iter][0]<=start){
            pq.push({jobs[iter][1], jobs[iter][0]});
            ++iter;
        }
        // 우선순위큐가 비어있다면 start이전에 요청된 작업이 없다는 의미이므로
        // 다음 작업의 요청시간으로 현재 시각을 바꾼다
        if(pq.empty() && iter<N){
            start = jobs[iter][0];
            pq.push({jobs[iter][1], jobs[iter][0]});
            ++iter;
        }
        P curr = pq.top();
        pq.pop();
        answer += (start += curr.first) - curr.second;
    }
    return answer/N;
}
