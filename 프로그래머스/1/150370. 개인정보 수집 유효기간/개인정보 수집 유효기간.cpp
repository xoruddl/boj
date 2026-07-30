#include <string>
#include <vector>
#include <iostream>
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
    
    // terms를 반복하면서 어떤 유형인지 파악하고 privacies의 해당 유형 날짜에 유효기간을 더해서 today와 비교한다.
    
    // terms 파싱해서 map으로 저장
    for (int i = 0; i < terms.size(); i++) {
        char f = terms[i][0];
        string d1 = "";
        for (int j = 2; j < terms[i].size(); j++) {
            d1 += terms[i][j];
        }
        // cout << d1 << '\n';
        int d2 = stoi(d1);
        Terms[f] = d2;
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
        day = day - 1;
        month = month + addMonth;
        
        // 날짜 범위에 맞게 변경 작업
        if (day == 0){
            day = 28;
            month -= 1;
        }
        // 유효 기간이 24개월도 넘을 수 있음
        if (month > 12){
            while (month > 12){
                year += 1;
                month -= 12;
            }
        }
        
        cout << year << " " << month << " " << day << '\n';
        
        // 최종 비교
        if (todayYear > year){
            answer.push_back(i + 1);
        } else if (todayYear == year){
            if (todayMonth > month){
                answer.push_back(i + 1);
            } else if (todayMonth == month){
                if (todayDay > day){
                    answer.push_back(i + 1);
                }
            }
        }
    }
    
    
    return answer;
}