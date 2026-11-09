#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    int N = participant.size();
    
    map<string, int> mp;
    for (int i = 0; i < N - 1; i++) {
        mp[completion[i]] += 1;
    }
    for (int i = 0; i < N; i++) {
        if (mp.find(participant[i]) != mp.end()) {
            mp[participant[i]] -= 1;
            if (mp[participant[i]] == 0) {
                mp.erase(participant[i]);
            }
        } else {
            return participant[i];
        }
    }
}