#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool isOdd = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            isOdd = false;
            continue;
        }
        
        if (isOdd) {
            isOdd = false;
            s[i] = tolower(s[i]);
        } else {
            isOdd = true;
            s[i] = toupper(s[i]);
        }
    }
    return s;
}