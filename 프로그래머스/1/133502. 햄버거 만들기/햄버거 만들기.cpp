#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    vector<int> v;
    for (auto num: ingredient) {
        v.push_back(num);
        
        vector<int> sub(v.end() - 4, v.end());
        if (sub == vector<int>{1, 2, 3,1 }){
            answer += 1;
            v.erase(v.end() - 4, v.end());
        }
    }
    
    return answer;
}