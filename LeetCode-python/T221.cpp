class Solution {
public:
    int balancedStringSplit(string s) {
        int stack = 0, count = 0;
        int i = 0;
        while (i < s.length())
        {
            if (s[i] == 'L'){
                stack++;
            }
            else stack--;
            if (stack == 0){
                count++;
            }
            i++;
        }
        return count;
    }
};
