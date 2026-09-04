class Solution {

    static bool cmp(vector<int>&a , vector<int>&b){
            return a[1]<b[1];
        }

public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin() , courses.end() , cmp);

        priority_queue<int>pq;
        int time =0;

        for(auto course : courses){
            int duration = course[0];
            int deadline = course[1];

            time+=duration;
            pq.push(duration);

            if(time > deadline){
                time-=pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};