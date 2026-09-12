class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        string word;
        vector<string>v(10);

        while(ss >> word){
            int pos = word.back() - '0';
            word.pop_back();
            v[pos] = word;
        }

        string str ="";
        for(int i=0 ; i<v.size(); i++){
            if(v[i]!=""){
                str = str + v[i]+" ";
            }
        }

        str.pop_back();
        return str;
    }
};