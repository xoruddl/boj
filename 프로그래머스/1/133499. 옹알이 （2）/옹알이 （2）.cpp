#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (int i = 0; i < babbling.size(); i++) {
        string cur = babbling[i];
        int prevIdx = -1;
        bool flag = true;
        
        for (int j = 0; j < cur.size(); j++) {
            if (cur.substr(j, 3) == "aya" && prevIdx != 1) {
                prevIdx = 1;
                j += 2;
            } else if (cur.substr(j, 2) == "ye" && prevIdx != 2) {
                prevIdx = 2;
                j += 1;
            } else if (cur.substr(j, 3) == "woo" && prevIdx != 3) {
                prevIdx = 3;
                j += 2;
            } else if (cur.substr(j, 2) == "ma" && prevIdx != 4) {
                prevIdx = 4;
                j += 1;
            } else {
                flag = false;
                break;
            }
        }
        
        if (flag) {
            answer += 1;
        }
    }
    
    return answer;
}