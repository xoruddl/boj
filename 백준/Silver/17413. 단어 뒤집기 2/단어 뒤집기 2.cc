#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<char>& st) {
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie();

    string s;
    stack<char> st;

    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '<') {
            printStack(st);
            while (1) {
                cout << s[i];
                if (s[i] == '>') break;
                i++;
            }
        }
        else if (s[i] == ' ') {
            printStack(st);
            cout << " ";
        }
        else {
            st.push(s[i]);
        }
    }
    printStack(st);
}