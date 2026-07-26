#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

stack<int> st;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    
    for (auto num : moves) {
        int pick = 0;
        for (int i = 0; i < n; i++) {
            if (board[i][num - 1] != 0){
                pick = board[i][num - 1];
                board[i][num - 1] = 0;
                break;
            }
        }
        
        cout << pick << '\n';
        
        if (pick) {
            if (st.empty()) {
                st.push(pick);
            } else if (st.top() == pick) {
                st.pop();
                answer += 2;
            } else {
                st.push(pick);
            }
        }
    }
    
    return answer;
}