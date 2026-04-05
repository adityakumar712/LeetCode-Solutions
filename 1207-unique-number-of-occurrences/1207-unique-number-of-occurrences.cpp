class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int >ump;

        for(int freq : arr){
            ump[freq]++;
        }

        unordered_set<int>st;

       for(auto kval : ump ){
        if(st.count(kval.second)){
            return false;
        }
        else{
            st.insert(kval.second);
        }
       }

       return true;

       
    }
};
