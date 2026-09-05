class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>x;
        vector<int>y;
        vector<int>res;
        int size = nums.size();
        
        for(int i=0; i<n; i++){
            x.push_back(nums[i]);
        }

        for(int i=n; i<size; i++){
            y.push_back(nums[i]);
        }

        for(int i=0; i<n; i++){
            res.push_back(x[i]);
            res.push_back(y[i]);
            
        }

         return res;
 
           
    }
};