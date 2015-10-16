module Search (binarysearch) where

binarysearch :: (Ord a, Eq a) => [a] => a => Maybe a
binarysearch [] _ = Nothing
binarysearch xs x
  | xs !! pivot == x = Just x
  | xs !! pivot > x  = binarysearch ([ xs !! i | i <- [0..(pivot - 1)] ]) x
  | otherwise        = binarysearch ([ xs !! i | i <- [(pivot + 1)..(length xs - 1)] ]) x
  where pivot = length xs `div` 2
                         
