#include <iostream>
#include <string>

using namaespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> matrix(min(numRows, (int)s.length()));
        int row=0, col=0;
        bool zig = false;
        for(char c: s){
            matrix[row]+= c;
            if(row==0) zig= false;
            if(row == numRows-1) zig=true;
            if(!zig) row++;
            else row--;
        }

        string result="";
        for(string c: matrix){
            result+=c;
        }
        return result;
    }
};

int main(){

    return 0;
}