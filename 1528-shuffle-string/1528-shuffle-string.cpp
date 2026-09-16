class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = indices.size();
        string str ="";
        vector<string>v(n);
        for(int i=0; i<indices.size(); i++){
            v[indices[i]].push_back(s[i]);
        }

        for(int i=0; i<v.size(); i++){
            str+=v[i];
        }

        return str;
    }
};