//最基础，没有考虑好边界条件，可以改进内存使用StringBuilder
class Solution {
    public String convert(String s, int numRows) {
        if(s.length() <= numRows || s.length() < 2 || numRows < 2){
            return s;
        }
        String[] ans = new String[numRows];
        int len = numRows * 2 - 2;
        for(int i = 0; i < s.length(); i++){
            if (i % len >= numRows){
                ans[len - i % len] += s.substring(i, i+1);
            }
            else if(ans[i % len] == null){
                ans[i % len] = s.substring(i, i+1);
            }
            else ans[i % len] += s.substring(i, i+1);

        }
        String res = new String();
        for(String value: ans){
            res += value;
        }
        return res;
    }
}
