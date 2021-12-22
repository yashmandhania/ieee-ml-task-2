import java.util.*;

class multable{
  void display(int n){
   for(int i = 1;i <=10; i++){
     System.out.println(n + " * " + i + " = " + (n * i));
   }
  }
}


 class MxNTableThread extends Thread{
   int k;
   MxNTableThread(String name , int m){
   	super(name);
   	this.k = m;
   }

   public void run(){
   	System.out.println("Starting....."+getName());
   	try{
   		multable m1= new multable();
   		m1.display(this.k);
   	}
   	catch(Exception e){
   		System.out.println(getName()+"Interrupted");
   	}
   	System.out.println("terminating"+getName());

   }
}

class tableDemo{
	public static void main(String[] args){
		System.out.println("Starting main thread");
		MxNTableThread n1= new MxNTableThread("Multiplication table of 5 ",5);
		Thread t1 = new Thread(n1);
		t1.start();
		MxNTableThread n2= new MxNTableThread("Multiplication table of 7 ",7);
		Thread t2 = new Thread(n2);
		t2.start();
		for(int i = 0;i<50;i++){
			try {
				Thread.sleep(100);
			}
			catch (InterruptedException e){
				System.out.println("Main thread Interrupted");
			}
		}
		System.out.println("Ending Main thread");
	}
}

