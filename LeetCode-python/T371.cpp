class Solution {
public:
    int getSum(int a, int b) 
    {
        int sum = 0, tmp = 1;
        while(tmp != 0)
        {
            sum = a ^ b;
            tmp = (unsigned int)(a&b) << 1;
            a = sum;
            b = tmp;
        }
        return sum;
    }
};
