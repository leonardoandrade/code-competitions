nextPrime :: (Integral a, Integral a) => (a, a) -> a 
nextPrime (divisor, n)
    | divisor * divisor > n = n --- only need to evaluate until the square root; this guard makes the problem O(sqrt(N))
    | mod n divisor == 0 = nextPrime (divisor + 1, quot n divisor) --- if its divisible,then we have a new (lower) max factor
    | otherwise = nextPrime (divisor + 1, n) -- otherwise, keep incrementing it

main :: IO ()
main = print ("Largest prime factor: " ++ show (nextPrime(2, 600851475143)))
