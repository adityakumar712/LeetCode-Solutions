class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>one , two ,zero;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zero.push_back(0);
            }

            else if(nums[i] == 1){
                one.push_back(1);
            }
            else{
                two.push_back(2);
            }
        }

        int index = 0;

        for(int i=0; i<zero.size(); i++){
            nums[index] = zero[i];
            index++;
        }

          for(int i=0; i<one.size(); i++){
            nums[index] = one[i];
            index++;
        }

          for(int i=0; i<two.size(); i++){
             nums[index] = two[i];
             index++;
        }

       
        
    }
};