package ComplexNumber;

public class TestComplexNumberPolar {
    public static void main(String[] args) {
        ComplexNumberPolar cnp = new ComplexNumberPolar(Math.sqrt(2), Math.PI / 4.0);
        System.out.println(cnp);
        ComplexNumber cn = new ComplexNumber(1, 1);
        cnp = new ComplexNumberPolar(cn);
        System.out.println(cnp);
        ComplexNumberPolar cnp1 = new ComplexNumberPolar(cnp);
        System.out.println(cnp1);
        ComplexNumberPolar p0 = new ComplexNumberPolar(new ComplexNumber(1, 1));
        ComplexNumberPolar p1 = new ComplexNumberPolar(new ComplexNumber(Math.sqrt(3), -1));
        System.out.println(p0.mult(p1));
        System.out.println(p0.div(p1));
        p0 = new ComplexNumberPolar(new ComplexNumber(0.5, 0.5));
        System.out.println(p0.pow(10));
        System.out.println("==========================");
        p0 = new ComplexNumberPolar(new ComplexNumber(-8, 0));
        ComplexNumberPolar[] roots = p0.roots(6);
        for (int k = 0; k < roots.length; ++k) {
            System.out.println(roots[k]);
        }
    }

}
