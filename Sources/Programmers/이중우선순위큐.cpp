#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    answer = {0, 0};
    for(string oper : operations) {
        // 명령 I가 내려온다면 최대힙과 최소힙 둘 다 숫자를 삽입한다
        if(oper[0] == 'I') {
            int num = stoi(oper.substr(2));
            maxHeap.push(num);
            minHeap.push(num);
        }
        // 명령 D가 내려온 경우
        else {
            if(oper[2] == '1') {
                // 비어있는 큐를 삭제해야 하는 경우 무시한다
                if(!maxHeap.empty()) {
                    maxHeap.pop();
                }
            }
            else {
                if(!minHeap.empty()) {
                    minHeap.pop();
                }
            }
            
            // 최소힙의 최솟값이 최대힙의 최댓값보다 큰 경우 모순이므로 최대힙과 최소힙을 비워준다
            if(!maxHeap.empty() && !minHeap.empty() && maxHeap.top() < minHeap.top()) {
                maxHeap = {};
                minHeap = {};
            }
        }
    }
    
    // 두 힙중 하나라도 비어있는 경우 [0,0] 반환
    if(maxHeap.empty() || minHeap.empty()) {
        return answer;
    }
  
    answer = {maxHeap.top(), minHeap.top()};
    return answer;
}
