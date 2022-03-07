class Solution {
    public String convertToBase7(int num) {
        StringBuilder s = new StringBuilder();
        if(num == 0) return "0";
            int isF = 0;
            if(num < 0)
            {
                num = -num;
                isF = 1;
            }
            while(num != 0){
                s.append(num%7);
                num = num/7;
            }
            if (isF == 1)
                s.append("-");
            return s.reverse().toString();
    }
}
