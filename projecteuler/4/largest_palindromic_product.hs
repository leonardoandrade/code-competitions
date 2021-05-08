isPalindrome :: [Char] -> Bool
isPalindrome [x] = True --single always palindrome
isPalindrome [x, y] = x == y --two must be or not palindrome
isPalindrome (x : xs) = (x == last xs) && isPalindrome (init xs) --if head does not equals tail, its not palindrome

searchRightDescending :: (Int, Int, Int) -> Int
searchRightDescending  (x, y, max) 
 | (x * y) < max = max -- to prune useless search
 | otherwise = if isPalindrome (show (x * y)) then x * y else searchRightDescending (x, y -1, max)

_search :: (Int, Int) -> Int
_search (x, max)
  | (x * x) < max = max -- to prune useless search
  | otherwise = _search (x -1, maximum [max, searchRightDescending (x, x, max)])

search :: Int -> Int
search x = _search (x, 0) -- encapsulation: hide the max searched so far

main = print (search 999)