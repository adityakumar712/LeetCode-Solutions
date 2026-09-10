class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>v;
        
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            int count=0;
            for(int j=0; j<nums.size(); j++){
                if(num > nums[j]){
                    count++;
                }
            }

            v.push_back(count);
            count=0;
        }
        return v;
    }
};