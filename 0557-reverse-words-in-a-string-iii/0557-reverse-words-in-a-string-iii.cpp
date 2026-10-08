class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans;

        while(ss >> word){
            string temp = "";

            for(int i=word.size()-1 ; i>=0; i--){
                temp+=word[i];
            }

            ans+=temp;
            ans+=" ";
        }
        
        ans.pop_back();
        return ans;
    }
};