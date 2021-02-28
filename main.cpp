#include <iostream>
#include <string>
using namespace std;

//concatenate string
string conCat(string str,int index){
    string tmp;
    for(int i = 0; i < str.size();i++){
        if(i != index)tmp.push_back(str[i]);
    }
    return tmp;
}

//is string palidrome
bool isPalindrome(const string& s) {
    if (s.length() == 0)
        return true;

    auto l = s.begin();
    auto r = s.end()-1;

    while (l < r) {
        if (!isalnum(*l)) {
            l++;
            continue;
        }

        if (!isalnum(*r)) {
            r--;
            continue;
        }

        if (tolower(*l) != tolower(*r))
            return false;

        l++;
        r--;
    }

    return true;
}

int main() {

    int T;
    string s;
    cin >> T;
    for(int t = 0; t < T; t++){

        cin >> s;
        if(isPalindrome(s)){
            cout << -1 << endl;
            continue;
        }
        int index = -1,len = s.size();
        for(int i = 0; i < len/2; i++){
            if(s[i] != s[len - i - 1]){
                if(isPalindrome(conCat(s, i)))index = i;
                if(isPalindrome(conCat(s, len - i - 1)))index = len - i - 1;
                break;
            }
        }
        cout << index << endl;
    }

    return 0;
}