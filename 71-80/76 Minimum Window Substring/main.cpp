#include <iostream>
#include <tr1/unordered_map>
#include <vector>
#include <climits>

using namespace std;
using namespace std::tr1;

class Solution {
public:
    string minWindow(string S, string T) {
        string result;
        if(S.empty() || T.empty()){
            return result;
        }
        unordered_map<char, int> map;
        unordered_map<char, int> window;
        for(int i = 0; i < T.length(); i++){
            map[T[i]]++;
        }
        int minLength = INT_MAX;
        int letterCounter = 0;
        for(int slow = 0, fast = 0; fast < S.length(); fast++){
            char c = S[fast];
            if(map.find(c) != map.end()){
                window[c]++;
                if(window[c] <= map[c]){
                    letterCounter++;
                }
            }
            if(letterCounter >= T.length()){
                while(map.find(S[slow]) == map.end() || window[S[slow]] > map[S[slow]]){
                    window[S[slow]]--;
                    slow++;
                }
                if(fast - slow + 1 < minLength){
                    minLength = fast - slow + 1;
                    result = S.substr(slow, minLength);
                }
            }
        }
        return result;
    }
};

int main () {
    Solution s;
    cout << s.minWindow("aa", "aa") << endl;
    cin.get();
    return 0;
}
