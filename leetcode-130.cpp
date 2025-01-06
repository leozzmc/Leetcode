#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<char>>& board, int row, int col){
    if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != 'O') return;
    
    board[row][col] = 'T';
    
    
    int offsetRow[4] = {1,0,-1,0};
    int offsetCol[4] = {0,1,0,-1};

    for(int k = 0; k < 4; k++){
       dfs(board ,row+offsetRow[k], col+offsetCol[k]);
    }
}

void solve(vector<vector<char>>& board) {
    //Traverse the board
    int m = board.size();
    int n = board[0].size();
    
    //Handle boundary
    for(int row=0; row< m; row++){
        // Find connected components connected to boundary
        if(board[row][0] == 'O') dfs(board, row, 0);
        if(board[row][n-1] == 'O') dfs(board, row, n-1);
    }
    
    for(int col=0; col <n ; col++){
        if(board[0][col] == 'O') dfs(board, 0, col);
        if(board[m-1][col] == 'O') dfs(board, m-1, col);
    }
    
    for(int row=0; row< m; row++){
        for(int col=0; col < n; col++){
            if(board[row][col] == 'O'){
                board[row][col] = 'X';
            }
            else if (board[row][col] == 'T'){
                board[row][col] = 'O';
            }
        }
    }

}

int main(){

    vector<vector<char>> board = {
        {'O','O','O','O'},
        {'O','O','O','O'},
        {'O','O','O','O'},
        {'O','O','O','O'}
    };
    
    // vector<vector<char>> board = {
    //     {"X","O","X","O","X","O"},["O","X","O","X","O","X"],["X","O","X","O","X","O"],["O","X","O","X","O","X"]]
    // };

    solve(board);
    
    for(int i=0;i<board.size();i++){
        for(int j=0; j<board[0].size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}