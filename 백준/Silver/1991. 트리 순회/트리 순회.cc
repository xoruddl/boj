#include <iostream>
#include <vector>

using namespace std;

int N;
pair<char, char> tree[28];

// 전위순회
void Preorder(char cur) {
    if (cur == '.') return;

    cout << cur;
    Preorder(tree[cur - 65].first);
    Preorder(tree[cur - 65].second);
}

// 중위순회
void Inorder(char cur) {
    if (cur == '.') return;

    Inorder(tree[cur - 65].first);
    cout << cur;
    Inorder(tree[cur - 65].second);
}

// 후위순회
void Postorder(char cur) {
    if (cur == '.') return;

    Postorder(tree[cur - 65].first);
    Postorder(tree[cur - 65].second);
    cout << cur;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    while (N--) {
        char parent, left, right;
        cin >> parent >> left >> right;

        tree[parent - 65] = {left, right};
    }

    Preorder('A');
    cout << '\n';
    Inorder('A');
    cout << '\n';
    Postorder('A');
}
