#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isMatch(char c1, char c2) {
        switch(c1) {
            case '{':
            if(c2 == '}') return true; break;
            case '[':
            if(c2 == ']') return true; break;
            case '(':
            if(c2 == ')') return true; break;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if(c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if(st.empty() || !isMatch(st.top(), c)) {
                    return false;
                }
                st.pop();
            }
        }
        if(st.empty()) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isValid("{[([])]}[]") << endl;
    cin.get();
    return 0;
}
