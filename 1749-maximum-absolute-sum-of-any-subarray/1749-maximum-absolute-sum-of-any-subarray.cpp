int MaxSum(vector<int>&nums){
    int bestEnding = nums[0];
    int res = nums[0];

    for(int i=1; i<nums.size(); i++){
        int v1 = nums[i];
        int v2 = bestEnding + nums[i];

        bestEnding = max(v1 , v2);

        res = max(res , bestEnding);
    }
    return res;
}

int MinSum(vector<int>nums){
    int bestEnding = nums[0];
    int res = nums[0];

    for(int i=1; i<nums.size(); i++){
        int v1 = nums[i];
        int v2 = bestEnding + nums[i];

        bestEnding = min(v1 ,v2);
        res = min(res , bestEnding);
    }

    return res;
}


class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum = MaxSum(nums);
        int minsum = abs(MinSum(nums));

        return max(maxsum , minsum);

    }
};