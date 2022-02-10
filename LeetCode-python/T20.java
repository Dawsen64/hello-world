// package test;

class Solution {
    public boolean isValid(String s) {
        StringBuilder stack = new StringBuilder();
        char[] s1 = s.toCharArray();
        for (char ch : s1){
            if (ch == '(' || ch =='{' || ch =='['){
                stack.append(ch);
                System.out.println(stack);
            }
            else if (!stack.isEmpty()){
                if ((ch == ')' && stack.charAt(stack.length()-1) == '(') ||
                        (ch == '}' && stack.charAt(stack.length()-1) == '{')||
                        (ch == ']' && stack.charAt(stack.length()-1) == '['))
                {
                    int len = stack.length();
                    stack.delete(len-1, len);
                    System.out.println(stack);
                }
                else return false;
            }
            else return false;
        }
        if(stack.isEmpty())
            return true;
        else return false;
    }
    public static void main(String[] args) {
        Solution ans = new Solution();
        System.out.println(ans.isValid("()"));
    }
}
