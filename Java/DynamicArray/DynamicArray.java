package DynamicArray;

import java.util.InputMismatchException;

public class DynamicArray<T> {
    T[][] arr;

    public DynamicArray(int rows, int cols) {
        arr = (T[][]) new Object[rows][cols];
    }

    public DynamicArray(DynamicArray<T> toCopy) {
        this(toCopy.arr.length, toCopy.arr[0].length);
        if (arr.length != toCopy.arr.length) {
            throw new InputMismatchException("Cannot copy from an array of different dimensions");
        }
        for (int i = 0; i < arr.length; i++) {
            if (arr[i].length != toCopy.arr[i].length) {
                throw new InputMismatchException("Cannot copy from an array of different dimensions");
            } else {
                for (int j = 0; j < arr[i].length; j++) {
                    arr[i][j] = toCopy.arr[i][j];
                }
            }
        }
    }

    @Override
    public String toString() {
        String out = "";
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                out = out + "\t" + arr[i][j];
            }
            out = out + '\n';
        }
        return out;
    }

    public T getCell(int i, int j){
        if(i < 0 || i > arr.length){
            throw new IndexOutOfBoundsException("The specified i index is invalid.");
        }
        if(j < 0 || j > arr[i].length){
            throw new IndexOutOfBoundsException("The specified j index is invalid.");
        }
        return arr[i][j];
    }

    public void setCell(int i, int j, T val){
        if(i < 0 || i > arr.length){
            throw new IndexOutOfBoundsException("The specified i index is invalid.");
        }
        if(j < 0 || j > arr[i].length){
            throw new IndexOutOfBoundsException("The specified j index is invalid.");
        }
        arr[i][j] = val;
    }
}
