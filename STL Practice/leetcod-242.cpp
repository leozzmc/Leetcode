#include <iostream>
#include <unordered_map>
using namespace std;



int main(){
    
    // Approach-1
    //character, times
    unordered_map<char, int> Dict;
    string s="anagram";
    string t="nagaram";

    if (s.length() != t.length()) {
        // If the lengths are different, they cannot be anagrams
        return false;
    }

    // Build the dictionary
    for(int i=0; i< s.length(); i++){
       Dict[s[i]]++;
    }

    for (int i=0; i<t.length(); i++){
        // Match
       if (Dict.find(t[i]) != Dict.end()){
            Dict[t[i]]--;
            if(Dict[t[i]] == 0){
                Dict.erase(t[i]);
            }
       }
       else{  //Not match
            return false;
       }
    }


    return 0;
}

// Approach-2
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
    
//         if (s.length() != t.length()) {
//             return false;
//         }

//         // A count vector with length 26 with init value 0
//         // Count only lowercase letters 
//         vector<int> count(26,0);

//         //build dictionary
//         for (int i=0; i< s.length(); i++){
//             count[s[i] - 'a']++;
//         }

//         for(int i=0; i < t.length(); i++){
//             count[t[i]-'a']--;
//         }

//         for(auto it=count.begin(); it!=count.end(); it++){
//             if(*it != 0){
//                 return false;
//             }
//         }
//         return true;
//     }
// };