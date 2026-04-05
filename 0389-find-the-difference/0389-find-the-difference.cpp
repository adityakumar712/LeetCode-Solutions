class Solution {
public:
    char findTheDifference(string s, string t) {
        char res =0;

        for(char ch : s){
            res = res ^ ch;
        }

        for(char ch2 : t){
            res = res ^ ch2;
        }

        return res;

        
    }
};