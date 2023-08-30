package RationalNumbers;

/**
 * A class representing a number expressed as an integer {@link #numerator} and
 * a {@link #denominator}
 */
public class RationalNumber implements RationalNumberInterface {

    /**
     * Variable storing the numerator of this {@link RationalNumber}
     */
    private int numerator;
    /**
     * Variable storing the denominator of this {@link RationalNumber}
     */
    private int denominator;

    /**
     * Creates a new {@link RationalNumber} with a {@link #numerator} of 0 and a
     * {@link #denominator} of 1.
     */
    public RationalNumber() {
        this.numerator = 0;
        this.denominator = 1;
    }

    /**
     * Creates a new {@link RationalNumber} with a specified {@link #numerator} and
     * {@link #denominator}.
     * 
     * @param n An integer value will be assigned to the {@link #numerator}
     * @param d An integer value that will be assigned to the {@link #denominator}.
     *          Cannot be equal to 0.
     * @throws IllegalArgumentException Thrown if the specified {@link #denominator}
     *                                  equals 0.
     */
    public RationalNumber(int n, int d) throws IllegalArgumentException {
        this.numerator = n;
        if (d == 0) {
            throw new IllegalArgumentException("Divide by Zero Error");
        } else {
            this.denominator = d;
        }
        if (this.denominator < 0) {
            this.denominator *= -1;
            this.numerator *= -1;
        }
    }

    /**
     * Creates a new {@link RationalNumber} with the same {@link #numerator} and
     * {@link #denominator} as a specified {@link RationalNumber}.
     * 
     * @param nrn The {@link RationalNumber} to copy the {@link #numerator} and
     *            {@link #denominator} from.
     */
    public RationalNumber(RationalNumberInterface nrn) {
        this.numerator = nrn.getNumerator();
        this.denominator = nrn.getDenominator();
    }

    @Override
    public int getNumerator() {
        return numerator;
    }

    @Override
    public int getDenominator() {
        return denominator;
    }

    @Override
    public RationalNumberInterface add(RationalNumberInterface rhs) {
        return new RationalNumber(this.numerator * rhs.getDenominator() + this.denominator * rhs.getNumerator(),
                this.denominator * rhs.getDenominator());
    }

    @Override
    public RationalNumberInterface sub(RationalNumberInterface rhs) {
        return new RationalNumber(this.numerator * rhs.getDenominator() - this.denominator * rhs.getNumerator(),
                this.denominator * rhs.getDenominator());
    }

    @Override
    public RationalNumberInterface mult(RationalNumberInterface rhs) {
        return new RationalNumber(this.numerator * rhs.getNumerator(), this.denominator * rhs.getDenominator());
    }

    @Override
    public RationalNumberInterface div(RationalNumberInterface rhs) throws ArithmeticException {
        if (rhs.getNumerator() == 0) {
            throw new ArithmeticException("Divide by Zero Error");
        }
        return new RationalNumber(this.numerator * rhs.getDenominator(), this.denominator * rhs.getNumerator());
    }

    @Override
    public double sqrt() throws ArithmeticException {
        if (this.numerator < 0) {
            throw new ArithmeticException("Divide by Zero Error");
        } else {
            return Math.sqrt((double) this.numerator / (double) this.denominator);
        }
    }

    @Override
    public String toString() {
        int tempNum = this.numerator;
        int tempDen = this.denominator;
        int prefix = 0;
        while (tempNum >= tempDen) {
            prefix++;
            tempNum -= tempDen;
        }
        int gcd = eucGCD(tempNum, tempDen);
        return ((prefix != 0 ? Integer.toString(prefix) + "  " : "")) + (tempNum == 0 ? "0" : (tempNum/gcd) + " / " + (tempDen/gcd));
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof RationalNumberInterface) {
            return this.numerator == ((RationalNumber) obj).getNumerator()
                    && this.denominator == ((RationalNumber) obj).getDenominator();
        }
        return false;
    }

    /**
     * Loop implementation to find the greatest common denominator of two numbers.
     * @param a The first number, must be smaller than b.
     * @param b The second number, must be greater than a.
     * @return The greatest common denominator of a and b.
     */
    private int eucGCD(int a, int b) {
        if(a == 0){
            return 1;
        }
        int temp = 0;
        do {
            temp = b % a;
            b = a;
            a = temp;
        } while (temp != 0);
        return b;
    }

}
