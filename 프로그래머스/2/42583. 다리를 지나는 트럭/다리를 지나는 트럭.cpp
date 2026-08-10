#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

struct T {
    int idx;
    int w;
    int time;
};

deque<T> dq; // 트럭 무게, 다리 진입 시간
int curW;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int time = 0;
    int n = truck_weights.size();
    int i = 0;
    
    while (time++) {
        // 나오는 트럭 확인
        if (!dq.empty() && time - dq.front().time >= bridge_length) {
            curW -= dq.front().w;
            // cout << time << ' ' << dq.front().idx << '\n';
            if (dq.front().idx == n - 1) {
                return time;
            }
            dq.pop_front();       
        }
        
        // 트럭 들어갈 수 있는지
        if (i < n && truck_weights[i] + curW <= weight) {
            // cout << time << ' ' << i << '\n';
            curW += truck_weights[i];
            dq.push_back({i, truck_weights[i], time});
            i++;
        }
        
    }
    
}