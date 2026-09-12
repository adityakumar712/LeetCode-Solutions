class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string word;
        string str="";
        while(ss >> word and k--){
           str+= word + " ";
        }

        str.pop_back();
        return str;
    }
};