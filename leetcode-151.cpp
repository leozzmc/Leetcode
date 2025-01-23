#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string tempStr = s;
        string subString = "";
        vector<string> wordList;
        
        // Add to wordlist
        for (char c : tempStr) {
            if (c == ' ') {
                if (!subString.empty()) {
                    wordList.push_back(subString);
                }
                subString = "";
            } else {
                subString += c;
            }
        }
        
        // make sure the last word added to list
        if (!subString.empty()) {
            wordList.push_back(subString);
        }
        
        // Reverse iterate the wordList, output reversed string
        subString = "";
        for (int i = wordList.size() - 1; i >= 1; i--) {
            subString += wordList[i];
            subString += " ";
        }
        subString += wordList[0];
        return subString;
    }
};

int main(){return 0;};