#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    // vector<pair<char, int>> Terms;
    map<char, int> Terms;
    
    // 오늘 날짜를 숫자로 변환
    int todayYear = stoi(today.substr(0, 4));
    int todayMonth = stoi(today.substr(5, 2));
    int todayDay = stoi(today.substr(8, 2));
    int todayNum = todayYear * 12 * 28 + (todayMonth - 1) * 28 + todayDay;
    
    // terms를 반복하면서 어떤 유형인지 파악하고 privacies의 해당 유형 날짜에 유효기간을 더해서 today와 비교한다.
    
    // terms 파싱해서 map으로 저장
    for (int i = 0; i < terms.size(); i++) {
        stringstream ss(terms[i]);
        char f;
        int num;
        ss >> f >> num;
        Terms[f] = num;
    }
    
    // for (auto p: Terms){
    //     cout << p.first << " " << p.second << '\n';
    // }
    
    for (int i = 0; i < privacies.size(); i++) {
        string curLine = privacies[i];
        char type = curLine[11];
        int year = stoi(curLine.substr(0, 4));
        int month = stoi(curLine.substr(5, 2));
        int day = stoi(curLine.substr(8, 2));
        
        int addMonth = Terms[type];
        month = month + addMonth;
        
        int temp = 0;
        temp = year * 12 * 28 + (month - 1) * 28 + day - 1;
        
        if (todayNum > temp){
            answer.push_back(i + 1);
        }
    }
    
    
    return answer;
}