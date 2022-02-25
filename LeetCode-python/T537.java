package basement;

/**
 * @Author: zqiusen@qq.com
 * @Date: 2022/2/25 17:50
 */
public class T537 {
    public static void main(String[] args) {
        Solution sol = new Solution();
        sol.complexNumberMultiply("1+1i","1+1i");
    }
}
class Solution {
    public String complexNumberMultiply(String num1, String num2) {
        String[] s1 = num1.split("[+i]",0);
        String[] s2 = num2.split("[+i]",0);
        int real = Integer.parseInt(s1[0]) * Integer.parseInt(s2[0]) +
                Integer.parseInt(s1[1]) * Integer.parseInt(s2[1]) * -1;
        int virtual = Integer.parseInt(s1[0]) * Integer.parseInt(s2[1]) +
                Integer.parseInt(s1[1]) * Integer.parseInt(s2[0]);
        System.out.println(real + "\n" + virtual);
//        return String.valueOf(real) + "+" + String.valueOf(virtual) + "i";
        return  new StringBuilder().append(real).append("+").append(virtual).append("i").toString();
    }
}
