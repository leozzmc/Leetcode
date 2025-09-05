#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    unordered_map<string, char> umap = {
        {"1", 'a'}, {"2", 'b'}, {"3", 'c'},
        {"4", 'd'}, {"5", 'e'}, {"6", 'f'},
        {"7", 'g'}, {"8", 'h'}, {"9", 'i'},
        {"10", 'j'},{"11", 'k'},{"12", 'l'},
        {"13", 'm'},{"14", 'n'},{"15", 'o'},
        {"16", 'p'},{"17", 'q'},{"18", 'r'},
        {"19", 's'},{"20", 't'},{"21", 'u'},
        {"22", 'v'},{"23", 'w'},{"24", 'x'},
        {"25", 'y'},{"26", 'z'}
    };

    int helper(vector<char> &vec,int index, vector<int> &memoVec){
        //reach the end of string
        if(index == vec.size()) return 1;
        if(memoVec[index]!= -1) return memoVec[index];
        int ways = 0;
        if(vec[index]!= '0'){
            //create a string which lenght is 1
            string stringOne(1, vec[index]);
            if(umap.count(stringOne)){
                ways+=helper(vec, index+1, memoVec);
            }
        }

        if(index+1 < vec.size()){
            string stringTwo;
            stringTwo.push_back(vec[index]);
            stringTwo.push_back(vec[index+1]);
            if(umap.count(stringTwo)){
                ways+=helper(vec, index+2, memoVec);
            }
        }
        return memoVec[index]=ways;
    }

    int numDecodings(string s) {
        int n=s.length();
        int counter = 0;
        vector<char> stringVec;
        vector<int> memo(n+1 , -1);
        for(char c : s){
            stringVec.push_back(c);
        }
        counter = helper(stringVec, 0, memo);
        return counter;
    }
};

void main(){


    
}