# include <iostream>
# include <vector>
# include <string>
# include <algorithm>

using namespace std;

vector<vector<string>> result;

bool checkPalindrome(string str){

    string reverseStr = str;
    reverse(reverseStr.begin(), reverseStr.end());
    return str == reverseStr;
}
void partitionhelper(string s, vector<string> subList, string cur, int depth){
    if(depth== s.length()){
        result.push_back(subList);
    }
    for(int i=depth; i<s.length(); i++){
        //Check if current string is palindrome
        cur = s.substr(depth, i-depth+1);
        if(checkPalindrome(cur)){
            // current string is palindrome
            subList.push_back(cur);
            partitionhelper(s, subList, cur, i+1);
            subList.pop_back();
        }
        
    }

}
vector<vector<string>> partition(string s){
    if(s=="") return result;
    vector<string> sub;
    string temp_cur;
    partitionhelper(s,sub, temp_cur, 0);
    return result;
}
int main(){
    vector<vector<string>> final_partitions;
    string s = "aab";
    final_partitions = partition(s);

    //test cases
    cout << "[";
    for(int i = 0; i <final_partitions.size();i++){
        for(int j =0; j< final_partitions[i].size();j++){
            cout <<"\"" << final_partitions[i][j] << "\"" << ",";
        }
        cout << endl;
    }
    cout << "]" << endl;

    return 0;
}