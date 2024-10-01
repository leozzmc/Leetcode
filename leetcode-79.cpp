#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool existhelper(int depth ,vector<vector<char>>& board, string word, int UpperIndex, int InnerIndex){
    if( depth == word.length()) return true;

    //boundary check
    if(UpperIndex <0 || InnerIndex <0 || UpperIndex >= board.size() || InnerIndex >= board[0].size()) return false;
    
    if(board[UpperIndex][InnerIndex] != word[depth]) return false;
    
    char temp = board[UpperIndex][InnerIndex];
    board[UpperIndex][InnerIndex] = '#';
    
    //backtracking
    bool found = ( existhelper(depth+1, board, word, UpperIndex+1, InnerIndex) || 
    existhelper(depth+1, board, word, UpperIndex, InnerIndex+1) || 
    existhelper(depth+1, board, word, UpperIndex, InnerIndex-1) || 
    existhelper(depth+1, board, word, UpperIndex-1, InnerIndex));
    
    board[UpperIndex][InnerIndex] = temp;
    
    return found;   
}

bool exist(vector<vector<char>>& board, string word){
    //find the init value
    for(int i=0; i< board.size();i++){
        for(int j=0; j< board[i].size();j++){
            if(board[i][j] == word[0]){
                if(existhelper(0,board, word , i, j)) return true;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "BCCEE";
    if (exist(board, word)) {
        cout << "Word found!" << endl;
    } else {
        cout << "Word not found." << endl;
    }
    return 0;
}