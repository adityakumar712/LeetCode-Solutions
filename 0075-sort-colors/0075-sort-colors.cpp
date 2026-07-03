class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one=0;
        int two=0;
        int zero=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zero++;
            }
            else if(nums[i] == 1){
                one++;
            }

            else{
                two++;
            }
        }

        int index = 0;

        for(int i=0; i<zero; i++){
            nums[index] = 0;
            index++;
        }

        for(int i=0; i<one; i++){
            nums[index] = 1;
            index++;
        }

        for(int i=0; i<two; i++){
            nums[index] = 2;
            index++;
        }

       
        
    }
};