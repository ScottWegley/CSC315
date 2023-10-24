package ComplexNumber;

public class ComplexNumberPolar extends ComplexNumber {
    private double radius;
    private double theta;

    public static void main(String[] args) {
        ComplexNumber c = new ComplexNumber(1,1);
        ComplexNumberPolar p = new ComplexNumberPolar(c);
        System.out.println(c);
        System.out.println(p);
    }

    public ComplexNumberPolar() {

    }

    public ComplexNumberPolar(double _r, double _i) {
        super(_r, _i);
        radius = mag();
        theta = Math.atan(_i / _r);
    }

    public ComplexNumberPolar(ComplexNumber _c) {
        this(_c.getReal(), _c.getImag());
    }

    public double getRadius() {
        return radius;
    }

    public double getTheta() {
        return theta;
    }

    public String toString() {
        return super.toString() + " : " + radius + "(cos(" + theta + ") + isin(" + theta + "))";
    }

    // public ComplexNumberPolar mult(ComplexNumberPolar rhs){

    // }

    // public ComplexNumberPolar div(ComplexNumberPolar rhs){

    // }

    // public ComplexNumberPolar pow(int i){

    // }

    // public ComplexNumberPolar[] roots(int i){

    // }
}
