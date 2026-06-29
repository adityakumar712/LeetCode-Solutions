class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        vector<int>res(m+n);
        int index = 0;

        while(i < m and j < n){
            if(nums1[i] <= nums2[j]){
                res[index] = nums1[i];
                i++;
                index++;
            }

            else{
                res[index] = nums2[j];
                j++;
                index++;
            }
        }

        while(j < n){
            res[index]= nums2[j];
            j++;
            index++;
        }

        while(i < m ){
            res[index] = nums1[i];
            i++;
            index++;
        }

        for(int k=0; k<res.size(); k++){
            nums1[k] = res[k];
        }
    }
};