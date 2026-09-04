#include <string>
#include <vector>
#include <set>

using namespace std;

multiset<int> ms;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for (auto op: operations) {
        int num = stoi(op.substr(2));
        
        if (op[0] == 'I'){
            ms.insert(num);
        }
        if (op[0] == 'D') {
            if (ms.empty()) continue;
            if (num == -1) {
                ms.erase(ms.begin());
            }
            if (num == 1) {
                ms.erase(--ms.end());
            }
        }
    }
    
    if (ms.empty()) {
        return {0, 0};
    } else {
        return {*ms.rbegin(), *ms.begin()};
    }
    
}