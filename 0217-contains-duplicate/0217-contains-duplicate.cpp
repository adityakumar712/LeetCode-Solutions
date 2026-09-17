class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int , int>fq;

        for(int i=0; i<nums.size(); i++){
            fq[nums[i]]++;
        }

        for(auto x : fq){
            if(x.second> 1){
                return true;
            }
        }

        return false;
    }
};