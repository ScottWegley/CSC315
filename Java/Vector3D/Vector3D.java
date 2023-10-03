package Vector3D;

public class Vector3D implements VectorInterface3D {

    private double x, y, z;

    public Vector3D(double _x, double _y, double _z) {
        x = _x;
        y = _y;
        z = _z;
    }

    public Vector3D() {
        this(0, 0, 0);
    }

    public Vector3D(Vector3D in) {
        this(in.get(COMPONENTS.XCOMPONENT), in.get(COMPONENTS.YCOMPONENT), in.get(COMPONENTS.ZCOMPONENT));
    }

    @Override
    public double get(COMPONENTS component) {
        double out;
        switch (component) {
            case XCOMPONENT:
                out = x;
                break;
            case YCOMPONENT:
                out = y;
                break;
            default:
                out = z;
                break;
        }
        return out;
    }

    @Override
    public void set(COMPONENTS component, double value) {
        switch (component) {
            case XCOMPONENT:
                x = value;
                break;
            case YCOMPONENT:
                y = value;
            default:
                z = value;
                break;
        }
    }

    @Override
    public VectorInterface3D Add(VectorInterface3D rhs) {
        return new Vector3D(rhs.get(COMPONENTS.XCOMPONENT) + x, rhs.get(COMPONENTS.YCOMPONENT) + y,
                rhs.get(COMPONENTS.ZCOMPONENT) + z);
    }

    @Override
    public VectorInterface3D Subtract(VectorInterface3D rhs) {
        return new Vector3D(x - rhs.get(COMPONENTS.XCOMPONENT), y - rhs.get(COMPONENTS.YCOMPONENT),
                z - rhs.get(COMPONENTS.ZCOMPONENT));
    }

    @Override
    public VectorInterface3D Multiply(double value) {
        return new Vector3D(value * x, value * y, value * z);
    }

    @Override
    public double Dot(VectorInterface3D rhs) {
        return x * rhs.get(COMPONENTS.XCOMPONENT) + y * rhs.get(COMPONENTS.YCOMPONENT)
                + z * rhs.get(COMPONENTS.ZCOMPONENT);
    }

    @Override
    public VectorInterface3D Cross(VectorInterface3D rhs) {
        return new Vector3D(
                (y * rhs.get(COMPONENTS.ZCOMPONENT) - z * rhs.get(COMPONENTS.YCOMPONENT)),
                (z * rhs.get(COMPONENTS.XCOMPONENT) - x * rhs.get(COMPONENTS.ZCOMPONENT)),
                (x * rhs.get(COMPONENTS.YCOMPONENT) - y * rhs.get(COMPONENTS.XCOMPONENT)));
    }

    @Override
    public double Norm() {
        return Math.sqrt(x * x + y * y + z * z);
    }

    @Override
    public VectorInterface3D Unit() {
        return new Vector3D(x / Norm(), y / Norm(), z / Norm());
    }

    @Override
    public double AngleBetween(VectorInterface3D rhs) {
        return Math.acos(Dot(rhs) / (Norm() * rhs.Norm()));
    }

    @Override
    public double DirectionAngle(COMPONENTS comp) {
        double num;
        switch (comp) {
            case XCOMPONENT:
                num = x;
                break;
            case YCOMPONENT:
                num = y;
                break;
            default:
                num = z;
                break;
        }
        num /= Norm();
        return Math.cos(num);
    }

    /**
     * If angle between is 0;
     */
    @Override
    public boolean Parallel(VectorInterface3D rhs) {
        return Math.abs(Cross(rhs).Norm()) <= PRECISION;
    }

    /**
     * The angle between = pi ish
     */
    @Override
    public boolean AntiParallel(VectorInterface3D rhs) {
        return Math.abs((Dot(rhs) / (Norm() * rhs.Norm())) + 1) <= PRECISION;
    }

    /**
     * 
     */
    @Override
    public VectorInterface3D Projection(VectorInterface3D rhs) {
        return Multiply(Dot(rhs) / rhs.Dot(rhs));
    }

    @Override
    public String toString() {
        return "<" + x + ", " + y + ", " + z + ">";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof VectorInterface3D) {
            VectorInterface3D vObj = (VectorInterface3D) obj;
            return ((Math.abs(x - vObj.get(COMPONENTS.XCOMPONENT)) < PRECISION)
                    && (Math.abs(y - vObj.get(COMPONENTS.YCOMPONENT)) < PRECISION)
                    && (Math.abs(z - vObj.get(COMPONENTS.ZCOMPONENT))) < PRECISION);
        }
        return false;
    }

}
