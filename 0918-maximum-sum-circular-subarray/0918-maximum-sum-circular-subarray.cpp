int maxsubArray(vector<int>nums){
    int bestEnding = nums[0];
    int res = nums[0];

    for(int i=1; i<nums.size(); i++){
        int prevBestEnding = bestEnding;

        int v1 = nums[i];
        int v2 = prevBestEnding + nums[i];

        bestEnding = max(v1 , v2);
        res = max(res , bestEnding);
    }
    return res;
}

int minsubArray(vector<int>nums){
    int bestEnding = nums[0];
    int res = nums[0];
    int Arraysum = nums[0];

    for(int i=1; i<nums.size(); i++){
        Arraysum +=nums[i];
        int prevbestEnding = bestEnding;

        int v1 = nums[i];
        int v2 = prevbestEnding + nums[i];

        bestEnding = min(v1 , v2);
        res = min(res , bestEnding);
    }

    res = Arraysum - res;
    return res;
}

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int case1 = maxsubArray(nums);
        if(case1 < 0){return case1;}
        int case2 = minsubArray(nums);
        
        return max(case1 , case2);
    }
    
};