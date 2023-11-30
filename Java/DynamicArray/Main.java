package DynamicArray;

public class Main {
    public static void main(String[] args) {
        DynamicArray<Integer> dmi = new DynamicArray<Integer>(2, 3);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                dmi.setCell(i, j, i * 3 + j);
            }
        }
        System.out.println(dmi);
        DynamicArray<Double> dmd = new DynamicArray<Double>(2, 3);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                dmd.setCell(i, j, (double) (i * 3 + j) / 6.0);
            }
        }
        System.out.println(dmd);
        DynamicArray<Double> dmdcopy = new DynamicArray<Double>(dmd);
        System.out.println(dmdcopy);
        DynamicArray<String> dms = new DynamicArray<String>(2, 3);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                dms.setCell(i, j, "value: " + (i * 3 + j));
            }
        }
        System.out.println(dms);
    }
}