#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    stack<int> st;
    int cnt = 1;
    string ans;

    while (n--) {
        int t;
        cin >> t;
        while (cnt <= t) {
            st.push(cnt++);
            ans += "+\n";
        }
        if (st.top() != t) {
            cout << "NO\n";
            return 0;
        }
        st.pop();
        ans += "-\n";
    }
    cout << ans;
}