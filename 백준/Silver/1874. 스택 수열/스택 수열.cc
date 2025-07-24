#include <iostream>
#include <stack>

using namespace std;

int n;
stack<int> st;
string ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    int cnt = 1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        while (cnt <= a) {
            st.push(cnt);
            cnt++;
            ans += "+\n";
        }
        if (st.top() != a) {
            cout << "NO\n";
            return 0;
        }
        st.pop();
        ans += "-\n";
    }
    cout << ans;
}