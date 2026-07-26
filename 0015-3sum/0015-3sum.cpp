class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin() , nums.end());
       vector<vector<int>>result;

       for(int i=0; i<nums.size()-2; i++){
        if(i > 0 && nums[i] == nums[i-1]){continue;}


        int sum = nums[i] * -1;
        int left = i+1;
        int right = nums.size()-1;

        while(left < right){
            int s = nums[left] + nums[right];
            if(sum == s){
                result.push_back({nums[i] , nums[left] , nums[right]});
                left++;
                right--;
            

            while(left < nums.size() && nums[left] == nums[left-1]){
                left++;
            }

            while(right >= 0 && nums[right] == nums[right + 1] ){
                right--;
            }
        }

        else if(s > sum){
            right--;
        }

        else if(s < sum){
            left++;
        }

        }
       }

       return result;
    }
};