#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> nodes;
        vector<vector<int> > edges;
        int length = 1;
        nodes.push_back(beginWord);
        int end_pos = -1;
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord) {
                end_pos = i + 1;
            }
            nodes.push_back(wordList[i]);
        }
        if (end_pos == -1) {
            return 0;
        }
        int n = nodes.size();
        vector<bool> used(n, false);
        for (int i = 0; i < n; ++i) {
            vector<int> tmp;
            for (int j = 0; j < n; ++j) {
                if (j != i && isValidEdge(nodes[i], nodes[j])) {
                    tmp.push_back(j);
                }
            }
            edges.push_back(tmp);
        }
        used[0] = true;
        vector<int> c(1, 0);
        bool isFound = false;
        for (int times = 0; times < nodes.size() - 1; ++times) {
            vector<int> newC;
            for (int i = 0; i < c.size(); ++i) {
                for (int j = 0; j < edges[c[i]].size(); ++j) {
                    int tmp = edges[c[i]][j];
                    if (used[tmp]) {
                        continue;
                    }
                    if (tmp == end_pos) {
                        isFound = true;
                    }
                    newC.push_back(tmp);
                }
            }
            vector<int> tmpC;
            tmpC.swap(c);
            c = newC;
            for (int i = 0; i < c.size(); ++i) {
                used[c[i]] = true;
            }
            ++length;
            if (isFound) {
                break;
            }
        }
        if (!isFound) {
            return 0;
        }
        return length;
    }
    bool isValidEdge(string s, string t) {
        int diff = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) {
                diff++;
            }
        }
        if (diff == 1) {
            return true;
        }
        return false;
    }
};

int main() {
    string dic[] = { "hot","dot","dog","lot","log","cog" };
    vector<string> wordList(&dic[0], &dic[6]);
    Solution s;
    cout << s.ladderLength("hit", "cog", wordList) << endl;
    cin.get();
    return 0;
}
