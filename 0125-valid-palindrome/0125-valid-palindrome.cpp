bool fun(string &s, int low, int high) {

    if(low >= high) {
        return true;
    }

    // non-alphanumeric character ko skip karo
    if(!isalnum(s[low])) {
        return fun(s, low + 1, high);
    }

    if(!isalnum(s[high])) {
        return fun(s, low, high - 1);
    }

    // case ignore
    if(tolower(s[low]) != tolower(s[high])) {
        return false;
    }

    return fun(s, low + 1, high - 1);
}

class Solution {
public:
    bool isPalindrome(string s) {
        return fun(s, 0, s.size() - 1);
    }
};