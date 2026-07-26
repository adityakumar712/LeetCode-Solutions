class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i=0;
      int j=0;
      vector<int>res(m+n);
      int index =0;

      while(i < m and j < n){
        if(nums1[i] <= nums2[j]){
            res[index] = nums1[i];
            i++;
            index++;
        }

        else{
            res[index] = nums2[j];
            index++;
            j++;
        }
      }

      while(j < n){
        res[index] = nums2[j];
        index++;
        j++;
      }

      while(i < m){
        res[index] = nums1[i];
        index++;
        i++;
      }

      for(int i=0; i<res.size(); i++){
        nums1[i] = res[i];
      }
    }
};