#include <iostream>
#include <queue>

using namespace std;

int n, num, result;
queue <int> q;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++){
        string command;
        cin >> command;

        //push
        if (command == "push"){
            cin >> num;
            q.push(num);
        }
        //pop
        else if (command == "pop"){
            if (q.size() == 0){
                result = -1;
                cout << result << "\n";
            }
            else{
                result = q.front();
                cout << result << "\n";
                q.pop();
            }
        }
        //size
        else if (command == "size"){
            cout << q.size() << "\n";
        }
        //empty
        else if (command == "empty"){
            if (q.size() == 0){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        //front
        else if (command == "front"){
            if (q.size() == 0){
                cout << -1 << "\n";
            }
            else{
                cout << q.front() << "\n";
            }
        }
        //back
        else if (command == "back"){
            if (q.size() == 0){
                cout << -1 << "\n";
            }
            else{
                cout << q.back() << "\n";
            }
        }
    }
    return 0;
}
