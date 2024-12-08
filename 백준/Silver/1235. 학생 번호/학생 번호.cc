#include <iostream>
#include <vector>

using namespace std;

int N;
vector<string> v;
vector<string> test;
int ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    v.resize(N);
    test.resize(N);
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        v[i] = s;
    }
    ans = s.size();


    for (int j =  s.size() - 1; j >= 0; j--) {
        bool flag = true;
        for (int i = 0; i < N; i++) {
            test[i] = v[i].substr(j, v[i].size());
        }

        for (int i = 0; i < N - 1; i++) {
            for (int k = i + 1; k < N; k++) {
                if (test[i] == test[k]) {
                    flag = false;
                    break;
                }
            }
            if (flag == false) break;
        }
        if (flag == true) {
            ans = test[0].size();
            break;
        }
    }
    cout << ans;
}
