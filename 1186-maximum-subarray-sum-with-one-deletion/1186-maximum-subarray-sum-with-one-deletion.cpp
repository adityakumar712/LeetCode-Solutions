class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodlt = arr[0];
        int onedlt = INT_MIN;
        int res = arr[0];

        for(int i=1; i<arr.size(); i++){
            int prevnodlt = nodlt;
            nodlt = max(nodlt + arr[i] , arr[i]);
            

            int v2;
            if(onedlt == INT_MIN){
                v2 = arr[i];
            }
            else{
                v2 = onedlt + arr[i];
            }

            onedlt = max(v2 , prevnodlt);

            res = max(res , max(onedlt , nodlt));
        }

        return res;
    }
};