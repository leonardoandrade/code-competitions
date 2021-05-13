-- polynomial was found using the python script
squareDiffByPolynomial :: Fractional a => a -> a
squareDiffByPolynomial n = n^4 / 4 + n^3 / 6 - n^2 / 4 - n / 6

main = print (squareDiffByPolynomial 100)
