#include <iostream>
#include <stack>

using namespace std;

int T;
int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;

    int TT = T;
    while (TT--) {
        string s;
        cin >> s;
        stack<long long> st;

        long long ans = -1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                if (st.empty()) {
                    st.push(i);
                    ans = 1;
                }
                else {
                    ans = (ans * (i - st.top())) % MOD;
                    st.push(i);
                }
            }
        }
        cout << ans % 1000000007 << '\n';
    }
}