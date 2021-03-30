value :: Char -> Integer
value c
  | c == '(' = 1
  | c == ')' = -1
  | otherwise = 0

nesting :: String -> Integer
nesting s = maximum (scanl1 (+) (map value s))

-- Ugyanez egy sorban, lambdákkal
-- nesting :: String -> Integer
-- nesting s = maximum . scanl1 (+) $ map (\x -> if x == '(' then 1 else -1) (filter (`elem` "()") s)

-- Ugyanűgy egy sorban, de pipeline-al, nem fv hívással
-- nesting :: String -> Integer
-- nesting s = maximum (scanl1 (+) (map (\x -> if x == '(' then 1 else -1) (filter (`elem` "()") s)))

-- nesting :: String -> Integer
-- nesting s = maximum . scanl1 (+) $ map value s

tests :: [[Char]]
tests = ["()", "(a + b)", "((a + b) * 3)", "3 + 4", "((((()))))"]

main :: IO ()
main = print (zip tests (map nesting tests))