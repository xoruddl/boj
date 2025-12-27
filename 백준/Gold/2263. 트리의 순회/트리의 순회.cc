#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> inorder;
vector<int> postorder;
int Index[100001];

void preorder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) {
        return;
    }

    int root = postorder[postEnd];
    int rootIndex = Index[root];
    int leftSize = rootIndex - inStart;
    int rightSize = inEnd - rootIndex;

    cout << root << " ";
    preorder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    preorder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        inorder.push_back(num);
        Index[num] = i;
    }
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        postorder.push_back(num);
    }
    preorder(0, n - 1, 0, n - 1);
}