package ComplexNumber;

public class ComplexNumberPolar extends ComplexNumber {
    private double radius;
    private double theta;

    public static void main(String[] args) {
        ComplexNumber c = new ComplexNumber(Math.sqrt(3),-1);
        ComplexNumberPolar p = new ComplexNumberPolar(c);
        System.out.println(c);
        System.out.println(p);
    }

    public ComplexNumberPolar() {
        this(new ComplexNumber());
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

    @Override
    public void setReal(double r) {
        super.setReal(r);
        radius = mag();
        theta = Math.atan(imag/real);
    }

    @Override
    public void setImag(double i) {
        super.setImag(i);
        radius = mag();
        theta = Math.atan(imag/real);
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
