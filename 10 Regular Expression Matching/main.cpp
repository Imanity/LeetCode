#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Word {
    char ch;
    bool isDup;
    Word(char x, bool y) : ch(x), isDup(y) {}
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int len = p.length();
        int i = 0;
        vector<Word> wordsTmp, words;
        while (i < len) {
            if (i == len - 1 || p[i + 1] != '*') {
                wordsTmp.push_back(Word(p[i], false));
                i++;
            } else {
                wordsTmp.push_back(Word(p[i], true));
                i += 2;
            }
        }
        Word tmpW = Word('#', false);
        for (i = 0; i < wordsTmp.size(); ++i) {
            if (wordsTmp[i].isDup == false || tmpW.ch != wordsTmp[i].ch || tmpW.isDup != wordsTmp[i].isDup) {
                if (tmpW.ch != '#')
                    words.push_back(tmpW);
                tmpW.ch = wordsTmp[i].ch;
                tmpW.isDup = wordsTmp[i].isDup;
            }
        }
        if (tmpW.ch != '#')
            words.push_back(tmpW);
        return isWordMatch(s, words);
    }
    bool isWordMatch(string s, vector<Word> p) {
        if(s.length() == 0 && p.size() == 0) {
            return true;
        } else if(s.length() == 0) {
            if(p[0].isDup == false) {
                return false;
            } else {
                vector<Word> newP(p.begin() + 1, p.end());
                return isWordMatch(s, newP);
            }
        } else if(p.size() == 0) {
            return false;
        }
        if(p[0].ch != s[0] && p[0].ch != '.') {
            if(p[0].isDup == false) {
                return false;
            } else {
                vector<Word> newP(p.begin() + 1, p.end());
                return isWordMatch(s, newP);
            }
        } else {
            if(p[0].isDup == false) {
                vector<Word> newP(p.begin() + 1, p.end());
                return isWordMatch(s.substr(1), newP);
            } else {
                vector<Word> newP(p.begin() + 1, p.end());
                return isWordMatch(s.substr(1), p) || isWordMatch(s.substr(1), newP) || isWordMatch(s, newP);
            }
        }
    }
};

int main() {
    Solution s;
    cout << s.isMatch("", "") << endl;
    cin.get();
    return 0;
}
