#include<string>
#include <iostream>
#include <deque>

using namespace std;

deque<char> dq;

bool solution(string s)
{
    bool answer = true;
    
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '('){
            dq.push_back(c);
        } else {
            if (dq.empty()) {
                return false;
            } else {
                dq.pop_back();
            }
        }
    }
    if (!dq.empty()) {
        return false;
    }

    return answer;
}