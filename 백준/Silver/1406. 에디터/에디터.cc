#include <iostream>
#include <list>

using namespace std;

int main()
{
    int n;
    string s;   //문자열
    cin >> s;
    cin >> n;   //명령어 반복수
    list <char> l(s.begin(), s.end());
    //list <char>::iterator now = l.end();
    auto now = l.end();
    
    while (n--){
        char tmp;
        cin >> tmp;
        
        if (tmp == 'L'){
            if (now != l.begin()){
                now--;
            }
        }
        else if (tmp == 'D'){
            if (now != l.end()){
                now++;
            }
        }
        else if (tmp == 'B'){
            if (now != l.begin()){
                now = l.erase(--now);
            }
        }
        else if (tmp == 'P'){
            char c;
            cin >> c;
            l.insert(now, c);
        }
    }
    for ( auto it = l.begin(); it != l.end(); it++){
        cout << *it;
    }
    return 0;
}