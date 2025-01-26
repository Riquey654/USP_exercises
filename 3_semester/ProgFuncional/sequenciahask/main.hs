main = do
    
    l0 <- getLine
    let nums = map read (words l0) :: [Integer]
    
    if null nums
        then putStrLn $ show 0
        else putStrLn $ show $ valMaxLista $ seqCresc nums 1


seqCresc :: [Integer] -> Integer -> [Integer]
seqCresc [] tamAtual = [tamAtual]
seqCresc [x] tamAtual = [tamAtual]
seqCresc(x1:x2:xs) tamAtual
    |x1 < x2 = seqCresc (x2:xs) (tamAtual+1)
    |otherwise = tamAtual : seqCresc(x2:xs) 1
    
valMaxLista :: [Integer] -> Integer
valMaxLista [] = 0
valMaxLista [x] = x
valMaxLista (x1:xs)
    | valMaxLista xs > x1 = valMaxLista xs
    | otherwise = x1