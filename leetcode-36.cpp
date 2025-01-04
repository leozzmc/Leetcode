#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
#include <unordered_set>
#include <cmath>
using namespace std;




bool isValidSudoku(vector<vector<char>>& board){
    unordered_set<char> uset;

    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j]!= '.' ){
                if(uset.find(board[i][j])!= uset.end()) return false;
                else uset.insert(board[i][j]);
            }
        }
        uset.clear();
    }
    uset.clear();

    for(int j=0; j<board[0].size(); j++){
        for(int i=0; i<board.size(); i++){
            if(board[i][j]!= '.'){
                if(uset.find(board[i][j])!= uset.end()) return false;
                else uset.insert(board[i][j]);
            }
        }
        uset.clear();
    }
    uset.clear();
   
    for(int i=0; i<3; i++){
        for(int j=0; j< 3;j++ ){
            
            for(int row=i*3; row < i*3+3; row++){
                for(int col = j*3; col<j*3+3; col++){
                    if (board[row][col] != '.') {
                        if(uset.find(board[row][col])!=uset.end()) return false;
                        else uset.insert(board[row][col]);
                    }
                }
            }
            uset.clear();
        }
    }
    uset.clear();

    return true;

}

int main(){

    vector<vector<char>> board ={
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
    };

    cout << isValidSudoku(board) << endl;

    return 0;
}