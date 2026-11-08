#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int>> q;
int answer = 0;
vector<int> temp;

int solution(vector<int> priorities, int location) {
    
    // queue 에 {idx, priority} 넣기
    for (int i = 0; i < priorities.size(); i++) {
        q.push({i, priorities[i]});
    }
    
    temp = priorities;
    sort(temp.rbegin(), temp.rend());
    
    int idx = 0;
    
    while (1) {
        int popTarget = temp[idx];
        
        int loc = q.front().first;
        int pri = q.front().second;
        q.pop();
        
        if (popTarget > pri) {
            q.push({loc, pri});
        } else if (popTarget == pri) {
            answer++;
            if (loc == location) {
                break;
            }
            idx++;
        }
    }
    
    return answer;
}