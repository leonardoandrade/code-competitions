
primeFactors x  = let sqrt_x = floor(sqrt( fromIntegral x)) in [i | i <- [2..sqrt_x], mod x i == 0]
prime x = null (primeFactors x)
main = print ("the 10001 th prime:" ++ show ([i |  i <-  [1..], prime i]!!10001)) 