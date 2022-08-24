/**
 * 演示基本变量在 java 与 c 层之间的传递
 */
public class BasicDemo01 {
    static{
        System.loadLibrary("BasicDemo01");
    }

    private native double average(int n1, int n2);

    public static void main(String[] args){
        System.out.println("In Java, the average is " + new BasicDemo01().average(3, 2));
    }
}
