package mypackages.p1;
public class Maximum {
    public static  int max(int a, int b, int c) {
        if (a > b) {
            if (a > c)
                return a;
            else
                return c;
        } 
        else {
            if (b > c)
                return b;
            else
                return c;
        }
    }
    public static  float max(float a, float b, float c) {
        if (a > b) {
            if (a > c)
                return a;
            else
                return c;
        } else {
            if (b > c)
                return b;
            else
                return c;
        }
    }
    public static int max(int[] arr) {
        int len = arr.length;
        int large = arr[0];
        for (int i = 1; i < len; i++) {
            if (arr[i] > large)
                large = arr[i];
        }
        return large;
    }
    public static int max(int[][] mat, int row, int col) {
        int large = mat[0][0];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] > large)
                    large = mat[i][j];
            }
        }
        return large;
    }
}
