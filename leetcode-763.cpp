#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// vector<int> result;
// void helper(vector<char> &vec, int index){
//     if(index >= vec.size()) return;

//     char firstChar = vec[index];
//     int lastIndex = index;
//     for(int i=index; i<vec.size(); i++){
//         // update partition range
//         if(vec[i] == firstChar){
//             lastIndex = i;
//         }
//     }
//     // check other chars in the range 
//     for(int i=index; i<lastIndex; i++){
//         for(int j=lastIndex+1; j<vec.size(); j++){
//             if(vec[i] == vec[j]){
//                 lastIndex = j;
//             }
//         }
//     }
//     result.push_back(lastIndex - index + 1);
//     helper(vec, lastIndex+1);
// }

// vector<int> partitionLabels(string s) {
//     // string to vector
//     int n = s.size();
//     vector<char> stringVec;
//     for(char c:s){
//         stringVec.push_back(c);
//     }
//     helper(stringVec, 0);
//     return result;
// }


vector<int> partitionLabels(string s) {
   unordered_map<char, int> umap;
   for(int i=0; i<s.size();i++){
        umap[s[i]] = i;
   }
   vector<int> result;
   int start = 0;
   int end =0;

   for(int i=0; i<s.size();i++){
     end  = max(end, umap[s[i]]);
     if(i == end){
        result.push_back(end - start +1);
        start = end + 1;
     }
   }
   return result;

}
void main(){

};