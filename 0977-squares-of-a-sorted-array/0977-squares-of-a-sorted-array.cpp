class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= 0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }

        if(pos.size() == 0){
            for(int i=0; i<neg.size(); i++){
                neg[i] = neg[i] * neg[i];
            }

            reverse(neg.begin() , neg.end());
            return neg;
        }

        if(neg.size() == 0){
            for(int i=0; i<pos.size(); i++){
                pos[i] = pos[i] * pos[i];
            }

            return pos;
        }

        for(int i=0; i<pos.size(); i++){
                pos[i] = pos[i] * pos[i];
            }

        for(int i=0; i<neg.size(); i++){
                neg[i] = neg[i] * neg[i];
            }

         reverse(neg.begin() , neg.end());


        int i=0;
        int j=0;
        int index = 0;
        vector<int>res(pos.size()+neg.size());

        while(i< pos.size() and j< neg.size()){
            if(pos[i] <= neg[j]){
                res[index] = pos[i];
                index++;
                i++;
            }
            else{
                res[index]=neg[j];
                index++;
                j++;

            }
        }

        while(j < neg.size()){
            res[index] = neg[j];
            index++;
            j++;
        }

        while(i < pos.size()){
            res[index] = pos[i];
            index++;
            i++;

        }

        for(int k=0; k<res.size(); k++){
            nums[k] = res[k];
        }

        return nums;
    }
};