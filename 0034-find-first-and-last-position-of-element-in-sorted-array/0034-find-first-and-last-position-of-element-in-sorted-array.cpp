int firstOccurance(vector<int>&arr , int tar){
    int low = 0;
    int n = arr.size()-1;
    int high = n;
    int ans = -1;

    while(low <= high){
        int guess = (low + high)/2;

        if(arr[guess] > tar){
            high = guess - 1;
        }

        else if(arr[guess] < tar){
            low = guess + 1;
        }

        else{   // equal to target
              ans = guess;
              high = guess - 1;
        }
    }

    return ans;
}

int secondOccurance(vector<int>&arr , int tar){
    int low = 0;
    int n  = arr.size()-1;
    int high = n;
    int ans = -1;

    while(low <= high){
        int guess = (low + high)/2;

        if(arr[guess] > tar){
            high = guess-1;
        }

        else if(arr[guess] < tar){
            low = guess + 1;
        }

        else{       // equal ho gaya 
            ans = guess;
            low = guess + 1;
        }
    }

    return ans;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int first =  firstOccurance(nums , target);
       int last =  secondOccurance(nums , target);

       return{first , last};

    }
};