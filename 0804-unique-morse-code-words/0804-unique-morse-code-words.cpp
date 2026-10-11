class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string>st;

        for(string word : words){
            string string1 = "";

            for(char ch :word){
                string1+=morse[ch - 'a'];
            }

            st.insert(string1);
        }

        return st.size();
    }
};