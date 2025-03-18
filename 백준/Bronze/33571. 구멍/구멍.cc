#include <iostream>

using namespace std;

pair<int,int> arr[28]; // 대, 소

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string str;
    getline(cin, str);

    arr[1] = {1, 1}; // A
    arr[2] = {2, 1};
    arr[4] = {1, 1};
    arr[5] = {0, 1};
    arr[7] = {0, 1};
    arr[15] = {1, 1};
    arr[16] = {1, 1};
    arr[17] = {1, 1};
    arr[18] = {1, 0};
    arr[27] = {1, 0}; //@

    int ans = 0;

    for (int i = 0; i < str.size(); i++) {
        // 대문자
        if (str[i] >= 65 && str[i] <= 90) {
            ans += arr[str[i] - 64].first;
        }
        // 소문자
        else if (str[i] >= 97 && str[i] <= 122) {
            ans += arr[str[i] - 96].second;
        }
        else if (str[i] == '@') {
            ans++;
        }
    }
    cout << ans;
}