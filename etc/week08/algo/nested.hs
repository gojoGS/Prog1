value :: Char -> Integer
value c
  | c == '(' = 1
  | c == ')' = -1
  | otherwise = 0

nesting :: String -> Integer
nesting s = maximum (scanl1 (+) (map value s))

tests :: [[Char]]
tests = ["()", "(a + b)", "((a + b) * 3)", "3 + 4", "((((()))))"]

main :: IO ()
main = print (map nesting tests)