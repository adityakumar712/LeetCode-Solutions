class Solution {
public:
    bool isPalindrome(int x) {
        int rev =0;
        int temp = x;

        if(x < 0){return false;}
        while(x!=0){
            int rem = x%10; 
            x = x/10;

            if(rev > INT_MAX/10 || (rev == INT_MAX /10 && rem > 7)){return 0;}

            if(rev < INT_MIN/10 || (rev == INT_MIN /10 && rem > -8)){return 0;}
             rev = rev * 10 + rem;

        }

       

        if(temp == rev){
            return true;
        }
        else{
            return false;
        }
    }
};