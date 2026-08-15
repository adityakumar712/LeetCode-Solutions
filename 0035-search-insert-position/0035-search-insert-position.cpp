class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low =0;
        int n = nums.size()-1;
        int high = n;
        int ans = nums.size();

        while(low <= high){
            int guess = (low + high)/2;

            if(nums[guess] == target){
                return guess;
            }

            else if(nums[guess] < target){
                low = guess + 1;
            }

            //greater milega uske index ko store krege wahi indes pe target fit hoga and array sorted bhi rahega

            else{   
                ans = guess;
                high = guess - 1;
            }
        }

        return ans;
    }
};