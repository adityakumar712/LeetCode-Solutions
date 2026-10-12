class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res = 0;

        for(int i=0; i<sentences.size(); i++){
            stringstream ss(sentences[i]);
            string word;
            int count = 0;

            while(ss >> word){
                count++;
            }

            res = max(res , count);
        }

        return res;
    }
};