/**
 * 演示字符串在 java 与 c 层之间的传递
 */
public class BasicDemo02 {
    static{
        System.loadLibrary("BasicDemo02");
    }

    private native String sayHello(String msg);

    public static void main(String[] args){
        System.out.println("In Java, sayHello " + new BasicDemo02().sayHello("Hello"));
    }
}
