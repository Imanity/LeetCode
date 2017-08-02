#include <iostream>
#include <vector>
#include <string>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int d = words[0].length();
        for(int start = 0; start < s.length() - d * words.size() + 1; ++start) {
            unordered_map<string, int> hmap;
            for(int i = 0; i < words.size(); ++i) {
                hmap[words[i]] += 1;
            }
            bool valid = true;
            for(int i = 0; i < words.size(); ++i) {
                string tmp = s.substr(start + i * d, d);
                if(hmap.find(tmp) == hmap.end()) {
                    valid = false;
                    break;
                }
                --hmap[tmp];
                if(hmap[tmp] < 0) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                res.push_back(start);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> dic;
    dic.push_back("word");
    dic.push_back("good");
    dic.push_back("best");
    dic.push_back("good");
    vector<int> res = s.findSubstring("wordgoodgoodgoodbestword", dic);
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << "\t";
    }
    cin.get();
    return 0;
}
