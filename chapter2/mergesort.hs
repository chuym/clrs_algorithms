sort :: (Ord a) => [a] -> [a]

sort [] = []
sort (x:[]) = [x]
sort xs = merge (sort left) (sort right)
    where left = take half xs
          right = take (length xs - half) $ drop half xs
          half = length xs `div` 2

merge :: (Ord a) => [a] -> [a] -> [a]
merge [] [] = []
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys)
    | x > y = [y] ++ merge (x:xs) ys
    | otherwise = [x] ++ merge xs (y:ys)
