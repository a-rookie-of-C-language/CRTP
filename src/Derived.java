public interface Derived extends Base {
    default void specificProcess() {
        // 派生类特定的计算密集型操作
        for (int i = 0; i < 1000000; i++) {
         ;
        }
    }
}