import System.Exit (exitSuccess)

main :: IO ()
main = do
    
    l1 <- getLine
    l2 <- getLine
    
    let num1 = read l1 :: Integer
    let num2 = read l2 :: Integer
        
    let primes = listaPrimos num1 num2
    let intervalos = listaIntervalos primes
    if length intervalos == 0
    then do
        exitSuccess
    else do
        let imprime = show(maximum intervalos)
        putStrLn imprime

isPrime :: Integer -> Bool
isPrime n
    | n < 2 = False
    | otherwise = all (\x -> n `mod` x /= 0) [2..(floor . sqrt . fromIntegral $ n)]

listaPrimos :: Integer -> Integer -> [Integer]
listaPrimos inicio fim
    | inicio > fim = []
    | isPrime inicio = inicio : listaPrimos (inicio + 1) fim
    | otherwise = listaPrimos (inicio + 1) fim

listaIntervalos :: [Integer] -> [Integer]
listaIntervalos (x:y:xs) = (y - x) : listaIntervalos (y:xs)
listaIntervalos _ = []
