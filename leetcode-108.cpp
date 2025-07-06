#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode *left, *right;
        TreeNode():val(0), left(nullptr), right(nullptr){};
        TreeNode(int node): val(node), left(nullptr), right(nullptr){};
        TreeNode(int node, TreeNode *leftNode, TreeNode *rightNode): val(node), left(leftNode), right(rightNode){};
};



TreeNode* helper(vector<int>&nums, int left, int right){
    it(left > right) return nullptr;

    int mid = left + (right - left)/2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = helper(nums,left, mid-1);
    root->right = helper(nums,mid+1, right);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums){
    return helper(nums, 0, nums.size()-1);
}

int main(){

    

    return 0;
}