#include <iostream>
#include <string>
using namespace std;

/*
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0;
        string p1;
        while(i < p.length()) {
            if(p[i] != '*') {
                p1.push_back(p[i]);
                ++i;
            } else {
                p1.push_back('*');
                while(p[i] == '*') {
                    ++i;
                }
            }
        }
        if(p[p.length() - 1] != '*' && p[p.length() - 1] != '?') {
            if(s[s.length() - 1] != p[p.length() - 1]) {
                return false;
            }
        }
        return match(s, p1);
    }
    bool match(string s, string p) {
        if(s.length() == 0 && p.length() == 0) {
            return true;
        } else if(p.length() == 0) {
            return false;
        } else if(s.length() == 0) {
            if(p == "*") {
                return true;
            } else if(p[0] == '*') {
                return match(s, p.substr(1));
            } else {
                return false;
            }
        }
        if(s.length() == 1) {
            if(p == "?" || s == p) {
                return true;
            } else if(p[0] == '*') {
                if(p.length() == 1) {
                    return true;
                }
                return match(s, p.substr(1));
            } else if(p[0] == s[0] || p[0] == '?') {
                return match(s.substr(1), p.substr(1));
            } else {
                return false;
            }
        } else if(p.length() == 1) {
            if(p[0] == '*') {
                return true;
            } else {
                return false;
            }
        }
        if(p[0] == '*') {
            for(int i = 0; i < s.size(); ++i) {
                if(match(s.substr(i), p.substr(1))) {
                    return true;
                }
            }
            return false;
        } else if(p[0] == '?') {
            return match(s.substr(1), p.substr(1));
        } else {
            if(s[0] != p[0]) {
                return false;
            } else {
                return match(s.substr(1), p.substr(1));
            }
        }
        return false;
    }
};
*/
class Solution {
public:
    bool isMatch(string s1, string p1) {
        const char* s = s1.c_str();
        const char* p = p1.c_str();
        const char* star=NULL;
        const char* ss=s;
        while (*s){
            //advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that *p will not advance beyond its length 
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}
            // * found in pattern, track index of *, only advancing pattern pointer 
            if (*p=='*'){star=p++; ss=s;continue;}
            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing pattern pointer
            if (star){ p = star+1; s=++ss;continue;}
            //current pattern pointer is not star, last patter pointer was not *
            //characters do not match
            return false;
        }
        //check for remaining characters in pattern
        while (*p=='*'){p++;}
        return !*p;  
    }
};

int main() {
    Solution s;
    cout << s.isMatch("babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb", "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a") << endl;
    cin.get();
    return 0;
}
