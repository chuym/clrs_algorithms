{-
Ex 2.3-7 - Describe a O(nlgn)-time algorithm that, given a set S of
n integers and another integer x, determines whether or not there exist
two elements in S whose sum is exactly x

We know that binarysearch takes O(lgn) time. Assuming that the set S is
ordered, then we can find the complement of S[i] in the set S/{S[i] which
added to it gives x. Worst case, we will try to find the complement for each i
in S, that means we have to do a binarry search n times, thus this algorithm
runs in O(nlgn) time.
-}

import Search
findcomplement :: (Eq a, Ord a, Num a) => [a] -> a -> Maybe (a,a)

findcomplement [] _ = Nothing
findcomplement (x:xs) y
    | binarysearch xs complement == Nothing = findcomplement xs y
    | otherwise = Just (x, complement)
    where complement = y - x
