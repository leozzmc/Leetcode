#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int  lengthOfLongestSubstring(string s){
    if(s.size()==0) return 0;
    int left=0, right=0;
    int maxLength = 0;
    unordered_map<char, int> umap;

    // Find substrings
    // Checking if the characters are repeated
    for(int right=0; right< s.size(); right++){
        if(umap.find(s[right])!=umap.end() && umap[s[right]]>=left){
            left = umap[s[right]]+1;
        }
        umap[s[right]]= right;
        maxLength= max(maxLength, right - left+1);
    }
    return maxLength;
}

int main(){
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl; // Output: 3

    s = "bbbbb";
    cout << lengthOfLongestSubstring(s) << endl; // Output: 1

    s= "au";
    cout << lengthOfLongestSubstring(s) << endl; //Output: 2
    
    s="dvdf";
    cout << lengthOfLongestSubstring(s) << endl; // Output: 3
    
    s="ddajakdijdwpki"; //Output: 6
    cout << lengthOfLongestSubstring(s) << endl; 
    

    return 0;
}