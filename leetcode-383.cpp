#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool canConstruct(string ransomNote, string magazine){
    unordered_map<char, int> umap;
    for(int i=0; i< magazine.length(); i++){
        umap[magazine[i]]++;
    }

    //Iterate through the ranSomNote for checking if it can construct by magazines
    for(char ch: ransomNote){
        if(umap[ch] == 0) return false;
        umap[ch]--;
    }
    return true;
}


int main(){

    string ransomNote = "aa";
    string magazine = "aab";
    cout << canConstruct(ransomNote, magazine) << endl;

    return 0;
}