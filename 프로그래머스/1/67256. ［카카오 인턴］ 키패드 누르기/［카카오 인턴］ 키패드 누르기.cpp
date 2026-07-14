#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<int, pair<int, int>> M = {
    {1, {1, 1}}, {2, {2, 1}}, {3, {3, 1}},
    {4, {1, 2}}, {5, {2, 2}}, {6, {3, 2}},
    {7, {1, 3}}, {8, {2, 3}}, {9, {3, 3}},
    {11, {1, 4}}, {0, {2, 4}}, {12, {3, 4}}
};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int L = 11; // *
    int R = 12; // #
    
    for (auto num : numbers) {
        if (num == 1 || num == 4 || num == 7) {
            answer += 'L';
            L = num;
        } else if (num == 3 || num == 6 || num == 9) {
            answer += 'R';
            R = num;
        } else {
            int d1 = abs(M[num].first - M[L].first) + abs(M[num].second - M[L].second);
            int d2 = abs(M[num].first - M[R].first) + abs(M[num].second - M[R].second);
            if (d1 > d2) {
                answer += 'R';
                R = num;
            } else if (d1 < d2) {
                answer += 'L';
                L = num;
            } else {
                if (hand == "right") {
                    answer += 'R';
                    R = num;
                } else {
                    answer += 'L';
                    L = num;
                }
            }
        }
    }
    
    return answer;
}