divisibleByAll :: ([Integer ], Integer ) -> Bool
divisibleByAll ([x], n) = mod n x == 0
divisibleByAll (x : xs, n) = mod n x == 0 && divisibleByAll(xs, n)

searchNumber :: ([Integer ], Integer)  -> Integer 
searchNumber (xs, n)
  | divisibleByAll(xs, n) = n 
  | otherwise  = searchNumber (xs, n + maximum (xs))


search :: [Integer ] -> Integer 
search xs = searchNumber(xs, maximum(xs))

main = print (search([11 .. 20]))