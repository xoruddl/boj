#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<double, int>> tmp;

bool cmp(pair<double, int> p1, pair<double, int> p2) {
    return p1.first == p2.first ? p1.second < p2.second : p1.first > p2.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int l = stages.size();
    
    for (int i = 1; i <= N; i++) {
        double a = 0, b =0;
        for (int j = 0; j < l; j++) {
            if (stages[j] == i) {
                a++;
            }
            if (stages[j] >= i) {
                b++;
            }
        }
        if (b != 0) {
            tmp.push_back({a/b, i});
        } else {
            tmp.push_back({0, i});
        }
    }
    
    sort(tmp.begin(), tmp.end(), cmp);
    
    for (int i = 0; i < tmp.size(); i++) {
        answer.push_back(tmp[i].second);
    }
    
    return answer;
}