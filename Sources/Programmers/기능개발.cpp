#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int days=0, works=progresses.size();
    for(int i=0; i<works; i++){
        if(progresses[i]+days*speeds[i]<100){
            days=(99-progresses[i]+speeds[i])/speeds[i];
            answer.push_back(1);
        }
        else {
            answer.back()++;
        }
    }
    return answer;
}
