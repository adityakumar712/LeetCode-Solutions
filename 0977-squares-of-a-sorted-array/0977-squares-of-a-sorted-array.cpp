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

        if(neg.size() == 0){
            for(int i=0; i<pos.size(); i++){
                pos[i] = pos[i] * pos[i];
            }
            return pos;
        }

        if(pos.size() == 0){
            for(int i=0; i<neg.size(); i++){
                neg[i] = neg[i]*neg[i];
            }

            reverse(neg.begin() , neg.end());
            return neg;
        }

        for(int i=0; i<neg.size(); i++){
            neg[i] = neg[i]*neg[i];
        }

        reverse(neg.begin() , neg.end());

        for(int i=0; i<pos.size(); i++){
            pos[i] = pos[i] * pos[i];
        }

        int i=0 , j =0;
        int index = 0;
        vector<int>res(pos.size()+neg.size());

        while(i<neg.size() and j<pos.size()){
            if(neg[i] <= pos[j]){
                res[index] = neg[i];
                i++;
                index++;
            }
            
            else{
                res[index] = pos[j];
                j++;
                index++;
            }
        }

        while(j < pos.size()){
            res[index] = pos[j];
            j++;
            index++;
        }

        while(i < neg.size()){
            res[index] = neg[i];
            i++;
            index++;
        }

        return res;
    }
};