class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int result = nums[0] + nums[1] + nums[2];
        int max_diff = INT_MAX;

        for(int i = 0; i < nums.size() - 2; i++) {

            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {

                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum - target);

                if(diff < max_diff) {
                    max_diff = diff;
                    result = sum;
                }

                if(sum == target) {
                    return sum;
                }
                else if(sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return result;
    }
};