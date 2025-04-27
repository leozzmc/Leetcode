class Solution {
public:

    int robHelper(vector<int> &nums,int start, int end){
        if(start > end) return 0;
        int prev = 0, current =0;
        for(int i= start; i<= end; ++i){
            int temp = max(current, prev + nums[i]);
            prev = current;
            current = temp;
        }
        return current;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        return max(robHelper(nums, 1, n-1), robHelper(nums, 0, n-2));
    }
};