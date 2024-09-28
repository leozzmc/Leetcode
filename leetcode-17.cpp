#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<string>> umap{
    {"2", {"a","b","c"}},
    {"3", {"d","e","f"}},
    {"4", {"g","h","i"}},
    {"5", {"j","k","l"}},
    {"6", {"m","n","o"}},
    {"7", {"p","q","r", "s"}},
    {"8", {"t","u", "v"}},
    {"9", {"w","x","y","z"}},
};

vector<string> result;

void leeterhelper(int depth, string current, string digits){
    if(depth == digits.length()){
        result.push_back(current);
        return;
    }
    string digit = string(1, digits[depth]);
 
    for(int i=0; i< umap[digit].size(); i++){
        leeterhelper(depth+1, current+umap[digit][i], digits);
    }

}

vector<string> letterCombinations(string digits){
    if(digits.empty()) return result;
    leeterhelper(0, "", digits);
    return result;
}

int main(){

    vector<string> finalResults;
    string digits = "23";
    finalResults= letterCombinations(digits);;
    for(int i=0; i<finalResults.size(); i++){
        cout << finalResults[i] << endl; 
    }
  

    return 0;
}