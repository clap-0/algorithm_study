#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    // days : 이전 작업들의 배포될 때까지 걸리는 최대 일수
    int days=0, works=progresses.size();
    for(int i=0; i<works; i++){
        // i번째 작업이 days날이 지난 후에도 작업이 끝나지 않은 경우
        if(progresses[i]+days*speeds[i]<100){
            // days를 i번째 작업이 배포될 때까지 걸리는 일수로 바꾼다.
            // 이때 배포는 하루의 끝에만 되므로 (남은 작업진도)/(개발속도)의 올림을 구한다
            days=(99-progresses[i]+speeds[i])/speeds[i];
            answer.push_back(1);
        }
        // i번째 작업이 이미 끝난 경우 이전 작업과 함께 배포한다
        else {
            answer.back()++;
        }
    }
    return answer;
}
