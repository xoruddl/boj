#include <iostream>
#include <stack>

using namespace std;

int n, num, result;
stack<int> s;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++){
        string command;
        cin >> command;

        //push
        if (command == "push"){
            cin >> num;
            s.push(num);
        }
        //pop
        else if (command == "pop"){
            if (s.size() == 0){
                result = -1;
                cout << result << "\n";
            }
            else{
                result = s.top();
                cout << result << "\n";
                s.pop();
            }
        }
        //size
        else if (command == "size"){
            cout << s.size() << "\n";
        }
        //empty
        else if (command == "empty"){
            if (s.size() == 0){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        //top
        else if (command == "top"){
            if (s.size() == 0){
                cout << -1 << "\n";
            }
            else{
                cout << s.top() << "\n";
            }
        }
    }
    return 0;
}