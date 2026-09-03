class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char , int>fq;
        for(int i=0; i<tasks.size(); i++){
            fq[tasks[i]]++;
        }

        priority_queue<int>pq;

        for(auto frq : fq ){
            pq.push(frq.second);
        }

        int time =0;

        while(!pq.empty()){
            vector<int>vec; 
            int executed =0;

            for(int i=0; i<=n; i++){
               if(!pq.empty()){
                  int count = pq.top();
                  pq.pop();
                  count--;

                  if(count>0){
                    vec.push_back(count);
                  }

                  executed++;
               }
            }

            for(int count : vec){
                pq.push(count);
            }

            if(!pq.empty()){
                time+=n+1;
            }else{
                time+=executed;
            }
        }

        return time;

    }
};