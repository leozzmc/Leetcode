class Solution {
    public:
        int findMin(vector<int>& nums) {
            if(nums.size()==1) return nums[0];
            int left = 0;
            int right = nums.size()-1;
            int minElement = INT_MIN;
    
            while(left < right){
                while(nums[left] > nums[right]){     
                    left++;      
                }
                minElement = nums[left];
                break;
            }
            return minElement;
        }
    };