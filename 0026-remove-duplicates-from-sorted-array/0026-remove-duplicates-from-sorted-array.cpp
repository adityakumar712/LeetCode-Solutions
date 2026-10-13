class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int index = 1;
     int unique = 1;
     int i = 1;

     while(i<nums.size()){
        if(nums[i] == nums[i-1]){
            i++;
            continue;
        }

        nums[index] = nums[i];
        i++;
        index++;
        unique++; 
     }

     return unique;

    }
};