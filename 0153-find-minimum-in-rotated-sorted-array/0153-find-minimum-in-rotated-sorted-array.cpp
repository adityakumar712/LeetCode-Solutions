class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0; 
        int high = nums.size()-1;
        int lastval = nums.size()-1;
        int res = -1;

        while(low <= high){
            int guess =(low + high) / 2;

            if(nums[guess] > nums[lastval] ){
                low = guess + 1;
            }else{
                res = nums[guess];
                high = guess - 1;
            }
        }

        return res;
    }
};