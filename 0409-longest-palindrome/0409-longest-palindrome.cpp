class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        int res = 0;
        unordered_map<char , int>f;

        for(int i=0; i<n; i++){
            f[s[i]]++;
        }
        
        bool odd = false;
        for(auto i : f){
            int freq = i.second;
            if(freq % 2 == 0){
                res+=freq;
            }
            else{
                res+=freq-1;
                odd = true;
            }
        }
       
       if(odd){
        res++;
       }
       
       return res;
        
        
    }
};