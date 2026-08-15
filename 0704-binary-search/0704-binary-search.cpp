class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size()-1;
        int high = n;

        while(low <= high){
            int guess = (low + high)/2;

            if(nums[guess] == target){
                return guess;
            }

            else if(nums[guess] > target){
                high = guess - 1;
            }

            else if(nums[guess] < target){
                low = guess + 1;
            }
        }

        return -1;
    }
};