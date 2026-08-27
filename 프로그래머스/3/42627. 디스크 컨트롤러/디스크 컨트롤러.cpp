#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pr {
    int idx;
    int start;
    int work;
    
    bool operator < (const Pr & o) const {
        if (work != o.work) {
            return work > o.work;
        }
        if (start != o.start) {
            return start > o.start;
        }
        return idx > o.idx;
    }
};

priority_queue<Pr> pq;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size();
    int jobIdx = 0; // 작업에 들어간 idx
    bool isWorking = false;
    int endTime = 0; // 각 작업이 끝나는 시간
    
    sort(jobs.begin(), jobs.end());
    
    int t = 0;
    while (1) {
        if (pq.empty() && jobIdx == n) {
            break;
        }
        
        // 특정 시간에 작업 추가
        while (jobIdx < n && t >= jobs[jobIdx][0]) {
            pq.push({jobIdx, jobs[jobIdx][0], jobs[jobIdx][1]});
            jobIdx++;
        }
        
        if (!pq.empty()) {
            Pr p = pq.top();
            pq.pop();
            
            t += p.work;
            
            answer += t - p.start;
        } else {
            t = jobs[jobIdx][0];
        }
    }
    
    answer = answer / n;
    return answer;
}