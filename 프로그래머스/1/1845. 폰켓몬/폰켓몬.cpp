#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map<int, int> mp;
int N;

int solution(vector<int> nums) {
    N = nums.size();
    
    for (int i = 0; i < N; i++) {
        mp[nums[i]] += 1;
    }

    int ans = 0;
    ans = min((int)mp.size(), N / 2);
    
    return ans;
}