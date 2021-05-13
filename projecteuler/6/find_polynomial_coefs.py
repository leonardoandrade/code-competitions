from scipy.interpolate import lagrange
from fractions import Fraction


def square_diff(n):
    sum_of_squares = sum([x*x for x in range(1,n+1)])
    square_of_sum = sum(range(1, n+1)) * sum(range(1,n+1))
    return square_of_sum - sum_of_squares

#find the xs and ys of the plot
xs = range(2,10)
ys = [square_diff(x) for x in xs] 

#find the polynomial by lagrange interpolation:

polynomial = lagrange(xs, ys)

print("coefficients: ")
for i, coef in enumerate(polynomial.coef):
    if(abs(coef) > 0.0001): # because float
        fract_coef = Fraction(coef).limit_denominator()
        print("  n^" + str(len(polynomial.coef) - i - 1) + " = " + str(fract_coef.numerator) + "/" + str(fract_coef.denominator))
 