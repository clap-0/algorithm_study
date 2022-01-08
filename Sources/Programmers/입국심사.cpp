#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long lo = 0, hi = (long long)*max_element(times.begin(), times.end()) * n;
    while(lo <= hi) {
        long long mid = (lo + hi) / 2;
        long long sum = 0;
        for(int time : times) { 
            sum += mid / time;
        }
        
        if(sum < n) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
            answer = mid;
        }
    }
    return answer;
}
