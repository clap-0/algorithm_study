#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    queue<int> Q;
    for(int i=0; i<bridge_length-1; i++)
        Q.push(0);
    Q.push(truck_weights[0]);
    int iter=1, bridge_weight=truck_weights[0], trucks=truck_weights.size();
    while(bridge_weight!=0){
        bridge_weight -= Q.front();
        Q.pop();
        if(iter<trucks && bridge_weight+truck_weights[iter] <= weight){
            Q.push(truck_weights[iter]);
            bridge_weight += truck_weights[iter++];
        }
        else Q.push(0);
        ++answer;
    }
    return answer;
}
