package ComplexNumber;

class ComplexNumber {
    protected double real;
    protected double imag;

    public ComplexNumber() {
        this(0, 0);
    }

    public ComplexNumber(double r, double i) {
        this.real = r;
        this.imag = i;
    }

    public ComplexNumber(ComplexNumber c) {
        this.real = c.getReal();
        this.imag = c.getImag();
    }

    public void setReal(double r) {
        this.real = r;
    }

    public void setImag(double i) {
        this.imag = i;
    }

    public double getReal() {
        return real;
    }

    public double getImag() {
        return imag;
    }

    public String toString() {
        return real + (imag == 0 ? "" : (imag < 0 ? " - " : " + ") + (imag < 0 ? imag * -1 : imag) + "i");
    }

    public ComplexNumber add(ComplexNumber rhs) {
        return new ComplexNumber(this.getReal() + rhs.getReal(), this.getImag() + rhs.getImag());
    }

    public ComplexNumber sub(ComplexNumber rhs) {
        return new ComplexNumber(this.getReal() - rhs.getReal(), this.getImag() - rhs.getImag());
    }

    public ComplexNumber mult(ComplexNumber rhs) {
        return new ComplexNumber(this.getReal() * rhs.getReal() - this.getImag() * rhs.getImag(),
                this.getReal() * rhs.getImag() + this.getImag() * rhs.getReal());
    }

    public ComplexNumber div(ComplexNumber rhs) throws ArithmeticException{
        if (rhs.getReal() == 0 && rhs.getImag() == 0) {
            throw new ArithmeticException("Denominator cannot equal 0");
        }
        return new ComplexNumber(
                (this.getReal() * rhs.getReal() + this.getImag() * rhs.getImag())
                        / (rhs.getReal() * rhs.getReal() + rhs.getImag() * rhs.getImag()),
                (this.getImag() * rhs.getReal() - this.getReal() * rhs.getImag())
                        / (rhs.getReal() * rhs.getReal() + rhs.getImag() * rhs.getImag()));
    }

    public ComplexNumber pow(int i){
        ComplexNumber out = new ComplexNumber(1,0);
        for (int j = 0; j < i; j++) {
            out = out.mult(this);
        }
        return out;
    }

    public double mag() {
        return Math.sqrt(this.getReal() * this.getReal() + this.getImag() * this.getImag());
    }

    public ComplexNumber conj() {
        return new ComplexNumber(this.getReal(), -this.getImag());
    }

    public ComplexNumber sqrt() {
        if (this.getImag() == 0) {
            if (this.getReal() < 0) {
                return new ComplexNumber(0, Math.sqrt(-this.getReal()));
            } else {
                return new ComplexNumber(Math.sqrt(this.getReal()), 0);
            }
        } else {
            double r = (Math.sqrt(
                    (this.getReal() + Math.sqrt(this.getReal() * this.getReal() + this.getImag() * this.getImag()))
                            / 2));
            double i = (Math.sqrt(
                    (-this.getReal() + Math.sqrt(this.getReal() * this.getReal() + this.getImag() * this.getImag()))
                            / 2));
            return new ComplexNumber(r, i);
        }
    }

    public boolean eqauls(Object o) {
        if (o instanceof ComplexNumber) {
            return ((ComplexNumber) o).getReal() == this.getReal() && ((ComplexNumber) o).getImag() == this.getImag();
        }
        return false;
    }

    public static void main(String[] args) {
        ComplexNumber c = new ComplexNumber(2,0);
        System.out.println(c.pow(3));
    }
}