class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      unordered_map<int , int >mp;
      for(int i=0; i<numbers.size(); i++){
        int cmplmt = target - numbers[i];
        if(mp.find(cmplmt) != mp.end()){
            return {mp[cmplmt]+1 , i+1};
        }
        mp[numbers[i]]=i;
      }
      return {};
    }
};