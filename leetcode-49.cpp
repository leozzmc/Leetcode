#include <iostream>
#include <vector>
#include <unordered_map>


int main(){

    vector<string> strs =  ["eat","tea","tan","ate", "nat","bat"];
    vector<vector<string>> ans;
    vector<vector<int>> charCounts(strs.size(), vector<int>(26,0));


    //Step1 - Build the hash table 
    for(int i=0; i<strs.size(); i++){
        //iterate the string
        for(char c: strs[i]){
            charCounts[i][c -'a']++;
        }
    }

    //Step2 - group the anagram
    unordered_map <vector<int>, vector<string>> groups;
    for (int i=0; i< strs.size(); i++){
        groups[charCounts[i]].push_back(strs[i]);

    }

    // Step 3 - Store grouped anagrams in the result vector
    for (const auto& group : groups) {
        ans.push_back(group.second);
    }
    //return ans;

    return 0;
}