int sumofdigitsqre(int num){
    int sum =0;
    while(num > 0){
        int l_dig = num % 10;
        sum = sum + l_dig * l_dig;
        num = num / 10;
    }
    return sum;
}

class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while(fast!=1){
            slow = sumofdigitsqre(slow);
            fast = sumofdigitsqre(fast);
            fast = sumofdigitsqre(fast);

            if(slow == fast and slow != 1){
                return false;
            }
        }

        return true;
    }
};