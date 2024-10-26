public class javaCRTP {
    public static void main(String[] args) {
        // CRTP
        Derived crtpDerived = new Derived() {
            @Override
            public void specificProcess() {
                // 派生类特定的计算密集型操作
                for (int i = 0; i < 1000000; i++) {
                    System.out.println("crtp");
                }
            }
        };
        long startCRTP = System.nanoTime();
        crtpDerived.process();
        long endCRTP = System.nanoTime();


        // 多态
        PolyDerived polyDerived = new PolyDerived();
        long startPoly = System.nanoTime();
        polyDerived.process();
        long endPoly = System.nanoTime();
        System.out.println("Polymorphism time: " + (endPoly - startPoly) / 1000000.0 + " ms");
        System.out.println("CRTP time: " + (endCRTP - startCRTP) / 1000000.0 + " ms");
    }
}
