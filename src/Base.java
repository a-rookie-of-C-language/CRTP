public interface Base {
    default void process() {
        // 一些计算密集型操作
        for (int i = 0; i < 1000000; i++) {
            // 模拟计算
            ;
        }
        specificProcess(); // 调用派生类的特定处理
    }

    void specificProcess();
}