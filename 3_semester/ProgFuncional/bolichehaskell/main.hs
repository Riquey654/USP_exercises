{-|
It is impossible to know how many numbers there will be in the input.

From the start:
    If the first number < 10, there will be another play.
    
    If the sum of the second number and the first number is 10, it's a spare, and the next play will be a bonus.
    Jump frame.
    
    If the sum of the second number and the first number is less than 10, it's a normal play.
    Jump frame.
    
    If the first number is 10, it's a strike, and the next 2 plays will be bonuses.
    Jump frame.
-}

main :: IO ()
main = do
    l0 <- getLine
    let nums = map read (words l0) :: [Int]
    let strArmazena = bowlingPrint nums "" 1 :: String
    putStr strArmazena
    
    let answer = bowlingCalculate nums 1 0
    putStr $ show answer

bowlingCalculate :: [Int] -> Int -> Int -> Int
bowlingCalculate [] _ score = score
bowlingCalculate seque frame score
    | frame > 10 = score
    | length seque >= 3 && head seque == 10 = bowlingCalculate (tail seque) (frame + 1) (score + 10 + sum (take 2 (tail seque)))
    | length seque >= 3 && sum (take 2 seque) == 10 = bowlingCalculate (drop 2 seque) (frame + 1) (score + 10 + seque !! 2)
    | length seque >= 2 = bowlingCalculate (drop 2 seque) (frame + 1) (score + sum (take 2 seque))
    | otherwise = score
    
bowlingPrint :: [Int] -> String -> Int -> String
bowlingPrint seque strDest frame
    | frame > 10 = strDest
    | frame == 10 && length seque >= 3 && head seque == 10 && seque !! 1 == 10 && seque !! 2 == 10 = bowlingPrint (tail seque) (strDest ++ "X X X | ") (frame + 1)
    | frame == 10 && length seque >= 3 && head seque == 10 && seque !! 1 == 10 = bowlingPrint (tail seque) (strDest ++ "X X " ++ show(seque !! 2) ++ " | ") (frame + 1)
    | frame == 10 && length seque >= 3 && head seque == 10 && sum (take 2(tail seque)) == 10 = bowlingPrint (tail seque) (strDest ++ "X " ++ show(seque !! 1) ++ " / | ") (frame + 1)
    | frame == 10 && length seque >= 3 && head seque == 10 = bowlingPrint (tail seque) (strDest ++ "X " ++ show(seque !! 1) ++ " " ++ show(seque !! 2) ++ " | ") (frame + 1)
    
    | frame == 10 && length seque >= 3 && sum (take 2 seque) == 10 && seque !! 2 == 10 = bowlingPrint (drop 2 seque) (strDest ++ show (head seque) ++ " / " ++"X | ") (frame + 1)
    | frame == 10 && length seque >= 3 && sum (take 2 seque) == 10 = bowlingPrint (drop 2 seque) (strDest ++ show (head seque) ++ " / " ++ show(seque !! 2) ++ " | ") (frame + 1)
    
    
    | frame == 10 && length seque >= 3 && head seque == 10 = bowlingPrint (tail seque) (strDest ++ "X " ++ show(seque !! 1) ++ " " ++ show(seque !! 2) ++ " | ") (frame + 1)
    
    | frame == 10 && length seque >= 3 && sum (take 2 seque) == 10 = bowlingPrint (drop 2 seque) (strDest ++ show (head seque) ++ " / " ++ show(seque !! 2) ++ " | ") (frame + 1)
    
    | length seque >= 3 && head seque == 10 = bowlingPrint (tail seque) (strDest ++ "X _ | ") (frame + 1)
    | length seque >= 3 && sum (take 2 seque) == 10 = bowlingPrint (drop 2 seque) (strDest ++ show (head seque) ++ " / | ") (frame + 1)
    | length seque >= 2 = bowlingPrint (drop 2 seque) (strDest ++ show (head seque) ++ " " ++ show(seque !! 1) ++" | ") (frame + 1)
    | otherwise = strDest

