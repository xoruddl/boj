#include <iostream>
#include <string>

using namespace std;

int a, b, c;
int arr[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b >> c;
    int result = 0;
    result = a * b * c;

    string s = to_string(result);
    for (int i = 0; i < s.size(); i++) {
        arr[s[i] - '0']++;
    }

    for (auto a : arr) {
        cout << a << '\n';
    }
    return 0;
}