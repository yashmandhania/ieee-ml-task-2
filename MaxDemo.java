import java.util.*;
import mypackages.p1.*;
import java.lang.*;

public class MaxDemo{
  public static void main(String[] args){
     Scanner sc = new Scanner(System.in);
       int opt;
       while(true){
         System.out.print("Choose (1)Max of 3 Int (2)Max of 3 Float (3)Max of array (4)Max of a Matrix  (5)Exit:");
         opt = sc.nextInt();
         
         switch(opt){
           case 1:
              System.out.println("Enter 3 Integers: ");
	      int a = sc.nextInt();
	      int b = sc.nextInt();
	      int c = sc.nextInt();
	      System.out.println("Greatest of the 3 integers: "+Maximum.max(a,b,c));
	      System.out.println();
	      break;
	      
           case 2:
              System.out.println("enter 3 float values");
              float p =sc.nextFloat();
              float q =sc.nextFloat();
              float r =sc.nextFloat();
              System.out.println("Greatest of these values is :"+Maximum.max(p,q,r));
              break;
              
           case 3:
               int[] arr;
              System.out.println("enter the size of array:");
              int n = sc.nextInt();
             
              arr=new int[n];
              System.out.println("Enter the elements of the array: ");
              for(int i=0;i<n;i++){
                  arr[i] = sc.nextInt();
                  }
              System.out.println("the max element of the array is:"+Maximum.max(arr));
              System.out.println();
              break;
              
            case 4:
              System.out.println("enter the dimentions of the matrix(rows columns): ");
              int row=sc.nextInt();
              int col=sc.nextInt();
              int[][] mat=new int[row][col];
              System.out.println("enter the elements of the matrix:");
              for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    mat[i][j]=sc.nextInt();
                }
              }
              System.out.println("Greatest number in the matrix is:"+Maximum.max(mat,row,col));
              System.out.println();
              break;
              
            case 5:
              System.exit(0);
         }
    }
  }
}
