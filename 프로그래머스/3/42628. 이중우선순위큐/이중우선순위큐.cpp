#include <string>
#include <vector>
#include <set>

using namespace std;

multiset<int> ms;

vector<int> solution(vector<string> operations) {
    int n = operations.size();
    
    for (int i = 0; i < n; i++) {
        string op = operations[i];
        char com = op[0];
        int num = stoi(op.substr(2));
        
        if (com == 'I') {
            ms.insert(num);
        } else {
            if (ms.empty()) {
                continue;
            }
            if (num == -1) {
                ms.erase(ms.begin());
            } else {
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