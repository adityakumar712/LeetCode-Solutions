class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char , int>need;
        unordered_map<char , int>have;

        for(int i=0; i<s.size(); i++){
            need[s[i]]++;
        }

        for(int i=0; i<t.size(); i++){
            have[t[i]]++;
        }

        for(auto i : need){
            int ch = i.first;
            int fneed = i.second;
            int fhave = have[ch];

            if(fhave != fneed){
                return false;
            }
        }

        return true;
    }
};