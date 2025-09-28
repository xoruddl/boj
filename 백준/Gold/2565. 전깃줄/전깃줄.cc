#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int lis;
vector<pair<int, int>> line;
vector<int> LIS;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    line.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> line[i].first >> line[i].second;
    }

    sort(line.begin(), line.end());

//    for (int i = 0; i < N; i++) {
//        cout << line[i].first << " " << line[i].second << "\n";
//    }
//
    for (int i = 0; i < N; i++) {
        int cur = line[i].second;
        int last = (!LIS.empty()) ? LIS.back() : -1;

        if (last < cur) {
            LIS.push_back(cur);
        }
        else {
            LIS[lower_bound(LIS.begin(), LIS.end(), cur) - LIS.begin()]
            = cur;
        }
    }

    cout << N - LIS.size();
}