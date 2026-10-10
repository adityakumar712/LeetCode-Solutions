class Solution {
public:
    bool isPalindrome(int x) {
       int rev = 0;
       int temp = x;

       if(x < 0){
        return false;
       }

       while(x != 0){
        int ldigit = x % 10;
        x = x/10;

        if(rev > INT_MAX / 10 || rev == INT_MAX/10 && rev > 7 ){
            return false;
        }

        rev = rev * 10 + ldigit;
       }

       return rev == temp;
    }
};