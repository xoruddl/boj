#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

bool fc(vector<int>& diffs, vector<int>& times, ll limit, ll mid){
    ll total = 0;
    ll time_prev = 0;
    
    for (int i = 0; i < diffs.size(); i++) {
        ll time_cur = times[i];
        
        if (mid - diffs[i] >= 0){
            total += time_cur;
        } else {
            total += (time_cur + time_prev) * (diffs[i] - mid) + time_cur;
        }
        time_prev = time_cur;
        
    }
    
    // cout << total << '\n';
    if (total <= limit) {
        return true;
    } else {
        return false;
    }
}

int solution(vector<int> diffs, vector<int> times, ll limit) {
    ll l = 0;
    ll r = 1000000000000000 + 1;
    
    while (l + 1 < r){
        ll mid = (l + r) / 2;
        
        // 레벨을 낮춰도 됨
        if (fc(diffs, times, limit, mid)){
            r = mid;
        } else {
            // 해당 레벨보다는 높아야함.
            l = mid;
        }
    }
    
    return r;
}