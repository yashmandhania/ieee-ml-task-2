import java.util.*;
import java.text.*;
import java.lang.*;
class Person{
  private String name;
  private GregorianCalendar dob;
  
  
  public Person(){
    this.name = "";
    this.dob = new GregorianCalendar();
   }


  /*public Person(String name, GregorianCalendar dob){
   this.name = name;
   this.dob = dob;
   }*/
   
   
  public void set_name(String name){
   this.name = name;
   }
  public void set_dob(int y, int m, int d){
   this.dob = new GregorianCalendar(y,m,d);
   }
  public String get_name(){
   return this.name;
   }
   
   public String get_dob(){
      
      return(this.dob.get(Calendar.DATE)+"/"+this.dob.get(Calendar.MONTH)+"/"+this.dob.get(Calendar.YEAR));
   }
   
   public void input(){
      Scanner sc =new Scanner(System.in);
      System.out.println("Enter name: ");
      set_name(sc.nextLine());
      System.out.print("Enter DOB(yyyy mm dd): ");
      set_dob(sc.nextInt(),sc.nextInt()-1,sc.nextInt());
   }
   
   public void display(){
      SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");
      System.out.println("Name: "+ this.name);
      System.out.println("DOB: "+ dateFormat.format(this.dob.getTime()));
   }
}
class CollegeGraduate extends Person{
   private float gpa;
   private int gradYear;
   
   public CollegeGraduate(){
     super();
     this.gpa=0.0f;
     this.gradYear=0;
   }
   
   
   /*
   public CollegeGraduate(String name, GregorianCalendar dob, float gpa ,int gradYear){
      super(name,dob);
      this.gpa=gpa;
      this.gradYear=gradYear;
   }*/
   
   
   
   public void set_gpa(float gpa){
     this.gpa=gpa;
   }
   
   public void set_gradYear(int gradYear){
     this.gradYear = gradYear;
   }
   
   public float get_gpa(){
     return(this.gpa);
   }
   public int get_gradYear(){
     return(this.gradYear);
   }
   
   public void input(){
     Scanner sc = new Scanner(System.in);
     super.input();
     System.out.print("Enter GPA: ");
     set_gpa(sc.nextFloat());
     System.out.print("Enter Year of Graduation: ");
     set_gradYear(sc.nextInt());
   }
   
   public void display(){
     System.out.println("\nCollege Graduate Details:");
     super.display();
     System.out.println("GPA: "+this.gpa);
     System.out.println("Year of graduation: "+this.gradYear+"\n");
   }
}
   
   public class first{
     public static void main(String[] args){
       Scanner sc = new Scanner(System.in);
       int opt;
       while(true){
         System.out.print("Choose (1)Person (2)College Graduate (3)Exit: ");
         opt = sc.nextInt();
         
         switch(opt){
           case 1:
		   Person person = new Person();
		   person.input();
		   System.out.println("\nPerson Details:");
		   person.display();
		   System.out.println();
		   break;
           case 2:
                   CollegeGraduate cg = new CollegeGraduate();
                   cg.input();
                   cg.display();
                   break;
           case 3:
                   System.exit(0);
         }
       }
     }
   }

































