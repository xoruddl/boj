#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool check(int num, vector<int>& ci) {
    auto it = lower_bound(ci.begin(), ci.end(), num);
    int cnt = ci.end() - it;
    if (num <= cnt) {
        return true;
    }
    return false;
}

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    
    sort(citations.begin(), citations.end());
    
    for (int i = 10000; i >= 0; i--) {
        if (check(i, citations)) {
            return i;
        }
    }
    
    return answer;
}