
main = print (sum [x | x <- [1..(1000-1)], mod x 3 ==0 || mod x 5 ==0])