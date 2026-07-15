class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int bestEnding =nums[0];
     int res = nums[0];

     for(int i=1; i<nums.size(); i++){
        int v1 = nums[i];
        int v2 = bestEnding + nums[i];

        bestEnding = max(v1 , v2);
        res = max(res ,  bestEnding);

     }

     return res;
        
    }
};