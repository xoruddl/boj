#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<char> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    if (N == 0) {
        cout << 0;
        return 0;
    }
    bool flag = true;
    if (N < 0) {
        flag = false;
        N = abs(N);
    }
    while (N) {
        if (flag) {
            if (N % 3 == 2) {
                N /= 3;
                N++;
                v.push_back('T');
            }
            else if (N % 3 == 1) {
                N /= 3;
                v.push_back('1');
            }
            else {
                N /= 3;
                v.push_back('0');
            }
        }
        else {
            if (N % 3 == 2) {
                N /= 3;
                N++;
                v.push_back('1');
            }
            else if (N % 3 == 1) {
                N /= 3;
                v.push_back('T');
            }
            else {
                N /= 3;
                v.push_back('0');
            }
        }
    }

    reverse(v.begin(), v.end());

    for (auto s : v) {
        cout << s;
    }
}