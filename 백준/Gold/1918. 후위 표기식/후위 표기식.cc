#include <iostream>
#include <stack>
using namespace std;

string s;
stack<char> st;

void solve() {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else if (s[i] == '*' || s[i] == '/') {
            while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if (s[i] == '+' || s[i] == '-') {
            while (!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else {
            cout << s[i];
        }
    }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> s;

    solve();
    return 0;
}