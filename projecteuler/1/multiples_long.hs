-- If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
--  The sum of these multiples is 23.
-- Find the sum of all the multiples of 3 or 5 below 1000.

sumMultiples :: (Integral a) => a -> a
sumMultiples 0 = 0
sumMultiples x
    | mod x 3 == 0 = x + sumMultiples(x - 1)
    | mod x 5 == 0 = x + sumMultiples(x - 1)
    | otherwise  = sumMultiples(x - 1)

_TARGET = 1000
main = putStrLn ("SUM of multiples of 3 and 5 below " ++ show _TARGET ++ ": " ++ show (sumMultiples (_TARGET-1)))
