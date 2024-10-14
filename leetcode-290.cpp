#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;



bool wordPattern(string pattern, string s){
    
    unordered_map<char, string> umap;
    unordered_map<string, char> umap2;
    vector<string> s_list;
    istringstream iss(s);
    string word="";
    while(iss >> word){
        s_list.push_back(word);
    }
    
    if(pattern.size()!= s_list.size()) return false;
    for(int i=0; i< pattern.size(); i++){
        char str = pattern[i];
        string s_word = s_list[i];
        if(umap.find(str)!=umap.end()){
            // find key - str  Ex. "a"
            if(umap[str]!= s_word){
                return false;
            }
        }
        else umap[str] = s_word;
        
        
        if(umap2.find(s_word)!=umap2.end()){
            if(umap2[s_word]!= str) return false;
        }
        else umap2[s_word] = str;
        
    }
    return true;
}

int main(){
    string pattern="abba";
    string s="dog dog dog dog";
    cout << wordPattern(pattern, s) << endl;
    return 0;
}