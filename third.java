import java.util.*;
abstract class Figure {
    int d1, d2;
    public Figure(int a, int b) {
        this.d1 = a;
        this.d2 = b;
    }
    abstract int area();
}
class Rectangle extends Figure {
    public Rectangle(int a, int b) {
        super(a, b);
    }
    public int area() {
        return (this.d1 * this.d2);
    }
}
class Square extends Figure {
    public Square(int a) {
        super(a, a);
    }
    public int area() {
        return (this.d1 * this.d2);
    }
}
class Triangle extends Figure {
    public Triangle(int a, int b) {
        super(a, b);
    }
    public int area() {
        return (this.d1 * this.d2 / 2);
    }
}
public class third {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Figure f;
        System.out.print("Enter the dimensions for the Rectangle(l,b): ");
        Rectangle r = new Rectangle(sc.nextInt(), sc.nextInt());
        f = r;
        System.out.println("Area of Rectangle: " + f.area());
        System.out.print("Enter the dimensions for the Square(l): ");
        Square s = new Square(sc.nextInt());
        f = s;
        System.out.println("Area of Square: " + f.area());
        System.out.print("Enter the dimensions for the Triangle(b,h): ");
        Triangle t = new Triangle(sc.nextInt(), sc.nextInt());
        f = t;
        System.out.println("Area of Triangle: " + f.area());
    }
}
