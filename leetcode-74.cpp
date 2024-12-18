#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target){
    int m = matrix.size();
    int n = matrix[0].size();
    int left=0;
    int right = m*n-1;
    
    while(left <= right){
        int mid = left + (right-left/2);
        int midValue = matrix[mid/n][mid%n];
        if(midValue == target) return true;
        else if(target < midValue){
            right = mid-1;
        }
        else if(target > midValue){
            left = mid+1;
        }
    }
    return false;
}

int main(){
    // vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    // int target = 3;
    
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60},{61,62,88,90},{91,100,250,251},{270,301,302,355}};
    int target = 270;
    cout << searchMatrix(matrix, target) << endl; // Output: true

    target = 13;
    cout << searchMatrix(matrix, target) << endl; // Output: false
    return 0;
}