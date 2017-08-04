#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> pathName;
        vector<string> simplifiedPath;
        splitPath(path, pathName);
        mergePath(pathName, simplifiedPath);
        string res;
        for (int i = 0; i < simplifiedPath.size(); ++i) {
            res += '/';
            res += simplifiedPath[i];
        }
        if (!simplifiedPath.size()) {
            res += '/';
        }
        return res;
    }
    void splitPath(string path, vector<string> &pathName) {
        string curr;
        for (int i = 0; i < path.size(); ++i) {
            if (path.at(i) == '/') {
                if (curr.size()) {
                    pathName.push_back(curr);
                    curr = "";
                }
            } else {
                curr.push_back(path.at(i));
            }
        }
        if (curr.size()) {
            pathName.push_back(curr);
        }
    }
    void mergePath(vector<string> &origin, vector<string> &dest) {
        for (int i = 0; i < origin.size(); ++i) {
            if (origin[i] == ".") {
                continue;
            } else if (origin[i] == "..") {
                if (dest.size()) {
                    dest.erase(dest.end() - 1);
                }
            } else {
                dest.push_back(origin[i]);
            }
        }
    }
};

int main() {
    Solution s;
    cout << s.simplifyPath("/home//foo/") << endl;
    cin.get();
    return 0;
}
