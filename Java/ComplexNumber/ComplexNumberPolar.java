package ComplexNumber;

public class ComplexNumberPolar extends ComplexNumber {
    private double radius;
    private double theta;

    public static void main(String[] args) {
        ComplexNumberPolar lhs = new ComplexNumberPolar(-8,0);
        // ComplexNumberPolar rhs = new ComplexNumberPolar(Math.sqrt(3),-1);
        System.out.println(lhs.toString());
        // System.out.println(rhs.toString());
        System.out.println(lhs.roots(6));
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

    public ComplexNumberPolar mult(ComplexNumberPolar rhs){
        return new ComplexNumberPolar(((ComplexNumber)this).mult((ComplexNumber)rhs));
    }

    public ComplexNumberPolar div(ComplexNumberPolar rhs){
        return new ComplexNumberPolar(((ComplexNumber)this).div((ComplexNumber)rhs));
    }

    @Override
    public ComplexNumberPolar pow(int i){
        return new ComplexNumberPolar(new ComplexNumber((ComplexNumber)this).pow(i));
    }

    public ComplexNumberPolar[] roots(int i){
        ComplexNumberPolar[] out = new ComplexNumberPolar[i];
        double reduced = Math.pow(radius, ((double)1)/i);
        for (int j = 0; j < i; j++) {
            out[j] = new ComplexNumberPolar(new ComplexNumber(reduced * Math.cos((this.theta + (2*j*Math.PI)/i)), reduced * Math.sin((this.theta + (2*j*Math.PI)/i))));
        }
        return out;
    }
}
