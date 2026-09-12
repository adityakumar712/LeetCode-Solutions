class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>t;

        for(int i=0; i< s.size(); i++){
            t.push(s[i]);
        }

        for(int i=0 ; i<s.size(); i++){
            s[i]=t.top();
            t.pop();
        }
    }
};