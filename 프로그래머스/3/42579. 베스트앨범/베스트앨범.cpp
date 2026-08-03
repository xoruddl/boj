#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

unordered_map<string, vector<pair<int,int>>> T;
unordered_map<string, int> total;

bool cmp(pair<int, int> v1, pair<int, int> v2){
    return v1.first == v2.first ? v1.second < v2.second : v1.first > v2.first;
}

bool cmp2(pair<string, int> p1, pair<string, int> p2){
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int n = genres.size();
    
    for (int i = 0; i < n; i++) {
        string g = genres[i];
        int p = plays[i];
        
        total[g] += p;
        T[g].push_back({p, i});
    }
    
    // for (auto [k, v]: total){
    //     cout << k << " " << v << '\n';
    // }
    
    for (auto& p: T){
        sort(p.second.begin(), p.second.end(), cmp);
    }
    vector<pair<string, int>> v(total.begin(), total.end());
    sort(v.begin(), v.end(), cmp2);
    
    for (auto & p: v){
        string g = p.first;
        for (int i = 0; i < T[g].size(); i++) {
            if (i < 2){
                answer.push_back(T[g][i].second);
            }
        }
    }
    
    return answer;
}