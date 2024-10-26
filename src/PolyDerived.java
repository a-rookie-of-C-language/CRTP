public class PolyDerived extends PolyBase {
    @Override
    public void specificProcess() {
        // 派生类特定的计算密集型操作
        for (int i = 0; i < 1000000; i++) {
            System.out.println("PolyDerived");
        }
    }
}