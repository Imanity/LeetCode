#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> formattedLines;
        vector<string> line;
        if (maxWidth == 0) {
            return words;
        }
        for (int i = 0; i < words.size(); ++i) {
            if (line.size() == 0 || minSize(line) + 1 + words[i].size() <= maxWidth) {
                line.push_back(words[i]);
            } else {
                formattedLines.push_back(format(line, maxWidth));
                line.resize(0);
                line.push_back(words[i]);
            }
        }
        if (line.size() != 0) {
            formattedLines.push_back(format(line, maxWidth));
        }
        if (formattedLines.size() > 0) {
            formattedLines[formattedLines.size() - 1] = reFormat(formattedLines[formattedLines.size() - 1], maxWidth);
        }
        return formattedLines;
    }
    int minSize(vector<string> line) {
        int size = 0;
        for (int i = 0; i < line.size(); ++i) {
            size += line[i].size();
        }
        if (line.size() != 0)
            size += (line.size() - 1);
        return size;
    }
    string format(vector<string> line, int maxWidth) {
        string str;
        int spaceNum = maxWidth;
        for (int i = 0; i < line.size(); ++i) {
            spaceNum -= line[i].size();
        }
        int n = line.size() - 1;
        if (n == 0) {
            str = line[0];
            int size = maxWidth - str.size();
            for (int i = 0; i < size; ++i) {
                str += ' ';
            }
            return str;
        }
        int singleSpace = spaceNum / n;
        int bigNum = spaceNum % n;
        int smallNum = n - bigNum;
        for (int i = 0; i < bigNum; ++i) {
            str += line[i];
            for (int j = 0; j <= singleSpace; ++j) {
                str += ' ';
            }
        }
        for (int i = 0; i < smallNum; ++i) {
            str += line[bigNum + i];
            for (int j = 0; j < singleSpace; ++j) {
                str += ' ';
            }
        }
        str += line[bigNum + smallNum];
        return str;
    }
    string reFormat(string &origin, int maxWidth) {
        string res;
        bool isSpace = false;
        for (int i = 0; i < origin.size(); ++i) {
            if (origin.at(i) != ' ') {
                isSpace = false;
                res.push_back(origin.at(i));
            } else {
                if (!isSpace) {
                    res.push_back(' ');
                }
                isSpace = true;
            }
        }
        int size = maxWidth - res.size();
        for (int i = 0; i < size; ++i) {
            res.push_back(' ');
        }
        return res;
    }
};

int main() {
    string word[] = { "Listen","to","many,","speak","to","a","few." };
    vector<string> words(&word[0], &word[7]);
    Solution s;
    words = s.fullJustify(words, 6);
    for (int i = 0; i < words.size(); ++i) {
        cout << words[i] << endl;
    }
    cin.get();
    return 0;
}
