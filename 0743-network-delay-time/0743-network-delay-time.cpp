class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int , int>>>a(n);

        for(int i=0; i<times.size(); i++){
            int src = times[i][0];
            int dest = times[i][1];
            int wet = times[i][2];

            a[src-1].push_back({dest-1 , wet});
        }

        priority_queue<pair<int , int > , vector<pair<int , int>>,greater<pair<int , int>>>pq;
        vector<int>dist(n,INT_MAX);
        dist[k-1] =0;
        pq.push({0 , k-1});
    

    while(!pq.empty()){
        pair<int , int>p = pq.top();
        pq.pop();

        int d = p.first;
        int node = p.second;

        if(d > dist[node]){
            continue;
        }

        for(int j=0; j<a[node].size(); j++){
            int neigh = a[node][j].first;
            int wt = a[node][j].second;

            if(d + wt < dist[neigh]){
                dist[neigh] = wt + d;
                pq.push({dist[neigh] , neigh});
            }
        }
    }


    int mintime = 0;
    for(int i=0; i<dist.size(); i++){
        if(dist[i] == INT_MAX){
            return -1;
        }else{
            mintime = max(mintime , dist[i]);
        }
    }
    

    return mintime;
    } 
};