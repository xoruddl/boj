#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct P {
    int num;
    int start;
    int work;

    bool operator > (const P& o) const {
        if (work != o.work) return work > o.work;
        if (start != o.start) return start > o.start;
        return num > o.num;
    }
};

priority_queue<P, vector<P>, greater<P>> pq;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int t = 0;
    int i = 0;
    int n = jobs.size();
    
    sort(jobs.begin(), jobs.end());
    
    bool isWorking = false;
    int endTime = 0;
    P p;
    
    while (1) {
        
        if (pq.empty() && i >= n) {
            // 남은 작업이 없으면 
            break;
        }

        // 특정 시간에 작업 추가
        while (i < n && t >= jobs[i][0]) {
            pq.push({i, jobs[i][0], jobs[i][1]});
            i += 1;
        }
        
        // 각 시간에서 작업을 할 수 있으면
        if (!pq.empty()) {
            p = pq.top();
            pq.pop();
            // 특정 시간에 처리해야할 작업이 있고 시작 시간이 됐을 때
            t += p.work; // 작업 완료 시간으로 이동
            
            answer += t - p.start;
            // cout << answer << '\n';
        } else {
            t = jobs[i][0];
        }
    }
    
    answer = answer / n;
    return answer;
}