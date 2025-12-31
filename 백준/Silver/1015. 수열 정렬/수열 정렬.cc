#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int A[53], P[53];
vector<pair<int, int>> v1, v2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        v1.push_back({A[i], i});
    }

    sort(v1.begin(), v1.end(), [](pair<int, int> a ,pair<int, int> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

//    for (int i = 0; i < N; i++) {
//        cout << v1[i].first << " " << v1[i].second;
//        cout << '\n';
//    }

//    for (int i = 0; i < N; i++) {
//        v2.push_back({v1[i].second, i});
//    }
//
//    sort(v2.begin(), v2.end(), [](pair<int, int> a, pair<int, int> b) {
//        return a.first < b.first;
//    });
//
//    for (int i = 0; i < N; i++) {
//        cout << v2[i].second << " ";
//    }

    for (int i = 0; i < N; i++) {
        P[v1[i].second] = i;
    }

    for (int i = 0; i < N; i++) {
        cout << P[i] << " ";
    }
}