#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct MyTreeNode {
    int val;
    MyTreeNode *parent;
    MyTreeNode(int x) : val(x), parent(NULL) {}
};

class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> nodes;
        vector<vector<int> > edges;
        vector<vector<string> > res;
        nodes.push_back(beginWord);
        int end_pos = -1;
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord) {
                end_pos = i + 1;
            }
            nodes.push_back(wordList[i]);
        }
        if (end_pos == -1) {
            return res;
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
        MyTreeNode *r = new MyTreeNode(0);
        used[0] = true;
        vector<MyTreeNode *> c(1, r);
        for (int times = 0; times < nodes.size() - 1; ++times) {
            vector<MyTreeNode *> newC;
            bool isFound = false;
            for (int i = 0; i < c.size(); ++i) {
                for (int j = 0; j < edges[c[i]->val].size(); ++j) {
                    int tmp = edges[c[i]->val][j];
                    if (used[tmp]) {
                        continue;
                    }
                    if (tmp == end_pos) {
                        isFound = true;
                    }
                    MyTreeNode *t = new MyTreeNode(tmp);
                    t->parent = c[i];
                    newC.push_back(t);
                }
            }
            vector<MyTreeNode *> tmpC;
            tmpC.swap(c);
            c = newC;
            for (int i = 0; i < c.size(); ++i) {
                used[c[i]->val] = true;
            }
            if (isFound) {
                break;
            }
        }
        for (int i = 0; i < c.size(); ++i) {
            if (c[i]->val == end_pos) {
                MyTreeNode *t = c[i];
                vector<string> route;
                while (t != NULL) {
                    route.push_back(nodes[t->val]);
                    t = t->parent;
                }
                reverse(route.begin(), route.end());
                res.push_back(route);
            }
        }
        return res;
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
    vector<vector<string> > ladder = s.findLadders("hit", "cog", wordList);
    for (int i = 0; i < ladder.size(); ++i) {
        for (int j = 0; j < ladder[i].size(); ++j) {
            cout << ladder[i][j] << " ";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
