long long fun(vector<int>&piles , int speed ){
    long long int h=0;

    for(int i=0; i<piles.size(); i++){
        h= h+ piles[i]/speed;

        if(piles[i]%speed!=0){
            h++;
        }
    }

    return h;
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int res = -1;

        int maxval = 0;
        for(int i=0; i<n; i++){
            if(piles[i] > maxval){
                maxval = piles[i];
            }
        }

        int low =1;
        int high = maxval;

        while(low <= high){
            int guess = (low + high)/2;
            
            long long hour = fun(piles , guess );

            if(hour > h){
                low = guess + 1;
            }else{
                res = guess;
                high = guess-1;
            }
        }

        return res;
    }
};