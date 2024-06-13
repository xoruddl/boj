#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    int arr[26];
    bool isPossible;
    string s1, s2;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s1 >> s2;
        isPossible = true;
        fill(arr, arr + 26, 0);
        for (int j = 0; j < s1.size(); j++) {
            arr[s1[j] - 'a']++;
            arr[s2[j] - 'a']--;
        }
        for (int j = 0; j < 26; j++) {
            if (arr[j] != 0) {
                isPossible = false;
                break;
            }
        }
        if (isPossible) cout << "Possible\n";
        else cout << "Impossible\n";
    }
    return 0;
}