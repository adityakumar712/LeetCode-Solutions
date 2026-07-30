vector<vector<int>> handleOverlap(vector<vector<int>>&range){
    int start1 = range[0][0];
    int end1 =   range[0][1];
    vector<vector<int>>result;

    for(int i=1; i<range.size(); i++){
        int start2 = range[i][0];
        int end2 = range[i][1];

        if(end1 >= start2){
            start1 = start1;
            end1 = max(end1 , end2);
            continue;
        }else{
            result.push_back({start1 , end1});
            start1 = start2;
            end1 = end2;
        }
    }

    result.push_back({start1 , end1});
    return result;
}


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool insert = false;
        vector<vector<int>>res;
        for(int i=0; i<intervals.size(); i++ ){
            int start = intervals[i][0];
            if(insert == false and start >= newInterval[0] ){
                res.push_back(newInterval);
                insert = true;
            }
            res.push_back(intervals[i]);
        }

        if(insert == false){
            res.push_back(newInterval);
        }

        vector<vector<int>>finalres;

        finalres = handleOverlap(res);

        return finalres;
    }
};