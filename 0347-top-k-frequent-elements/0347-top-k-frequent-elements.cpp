struct compare{
    bool operator()(pair<int , int>&a , pair<int , int>&b){
        if(a.first != b.first){
            return a.first > b.first;
        }

        else{
            return a.second > b.second;
        }
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int>f;

        for(int i=0; i<nums.size(); i++){
            f[nums[i]]++;
        }

        priority_queue<pair<int , int> ,vector<pair<int , int>>,compare>pq;

        for(auto i : f){
            int elmt = i.first;
            int freq = i.second;

            pair<int , int >curr={freq , elmt};

            if(pq.size() < k){
                pq.push(curr);
                continue;
            }

            else{
                if(curr.first < pq.top().first){
                    continue;
                }
                else{
                    pq.pop();
                    pq.push(curr);
                }
            }
        }

        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};