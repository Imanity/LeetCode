#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); ++i) {
            if (string("+-*/").find(tokens[i]) != string::npos) {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                switch (tokens[i][0]) {
                case '+':
                    s.push(a + b);
                    break;
                case '-':
                    s.push(a - b);
                    break;
                case '*':
                    s.push(a * b);
                    break;
                case '/':
                    s.push(a / b);
                    break;
                default:
                    break;
                }
            } else {
                s.push(atoi(tokens[i].c_str()));
            }
        }
        return s.top();
    }
};

int main() {
    string token[] = { "4", "13", "5", "/", "+" };
    vector<string> tokens(&token[0], &token[5]);
    Solution s;
    cout << s.evalRPN(tokens) << endl;
}
