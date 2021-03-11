package ro.ase.acs.interfaces;

public interface Taxable {
    public static final float min_Tax = 5;

    public float computeTax();
}