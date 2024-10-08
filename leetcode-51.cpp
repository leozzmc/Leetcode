#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> result;

bool isValid(vector<string> &current, int row, int column){
    for(int i=0; i<row; i++){
        if(current[i][column] == 'Q') return false;
    }
    for(int i=row-1,j=column-1; i>=0 && j>=0; i--, j--){
        if(current[i][j] == 'Q') return false;
    }
    for(int i=row-1,j=column+1; i>=0 && j<current.size(); i--, j++){
        if(current[i][j] == 'Q') return false;
    }
    return true;
}

void nQueensHelper(vector<string> &current, int n, int row){
    if(row == n){
        result.push_back(current);
        return;
    }
    for(int col=0; col< n; col++){
        if(current[row][col] == '.' && isValid(current, row, col)){
                current[row][col] = 'Q';
                nQueensHelper(current, n, row+1);
                current[row][col] = '.';
            
        }
    
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<string> board(n, string(n, '.'));
    nQueensHelper(board,n, 0);
    return result;
}
int main(){

    vector<vector<string>> finalNQueens;
    finalNQueens = solveNQueens(4);
    cout << "[" << " ";
    for(int i = 0; i < finalNQueens.size();i++){
        cout << "[" << " ";
        for(int j = 0; j < finalNQueens[i].size(); j++){
            cout << "\"" << finalNQueens[i][j] << "\"";
            if(j< finalNQueens[i].size()-1) cout << ",";
            
        }
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}