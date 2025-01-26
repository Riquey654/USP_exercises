{-|

Country, Confirmed, Deaths, Recovery, Active

-}


import System.IO
import Control.Exception
import Control.DeepSeq
import Data.Ord
import Data.List

data CountryInfo = CountryInfo { --struct CountryInfo para armazenar cada valor do pais
  country :: [Char],
  confirmed :: Int,
  deaths :: Int,
  recovery :: Int,
  active :: Int
}
  deriving (Show, Read)

main = do
    
    l0 <- getLine
    let params = map read $ words l0 :: [Int]
    
    --atribuicao de n1 a n4
    let n1 = params !! 0 
    let n2 = params !! 1 
    let n3 = params !! 2 
    let n4 = params !! 3
    
    --abertura do arquivo
    h <- openFile "dados.csv" ReadMode
    contentFile <- hGetContents h --le o arquivo
    evaluate $ force contentFile --impede o lazyness de acontecer, pois o conteudo do arquivo sera utilizado posteriormente
    hClose h
    --fecha o arquivo
    
    
    
    let paises = map parseCountryInfo $ lines contentFile
    
    --soma de "Active" dos países que "Confirmed" é maior ou igual a n1.
    --sum active $ filter confirmed >= n1 $
    putStrLn $
        show $
        sum $
        map active $ --pega somente os valores de active, e soma
        filter(\c -> confirmed c >= n1) $ --filtra todos os confirmeds maiores ou igual a n1
        paises
        
    --Dentre os n2 países com maiores valores "Active", a soma das "Deaths" dos n3 países com menores valores de "Confirmed".
    putStrLn $ 
        show $
        sum $
        map deaths $ --pega os valores deaths das structs que passaram, e soma
        take n3 $  --pega n3 primeiros
        sortBy (comparing confirmed) $ --Ordena de menor pra maior Confirmed
        take n2 $   --pega n2 primeiros valores
        sortBy(flip(comparing active)) $ --Ordena de maior pra menor por Active
        paises
        
        

    --putStrLn $ sort alphabetic $ take n4 $ sort confirmed $ contentFile
    --n4 países com maiores valores de "Confirmed". Devem estar em ordem alfabética.
    putStr $
        unlines $ -- junta todos numa unica string, colocando um \n para separar cada nome
        map country $ --pega somente os valores de country
        sortBy(comparing country) $ --ordena em ordem alfabetica
        take n4 $  --pega n4 primeiros valores
        sortBy(flip(comparing confirmed)) $ --ordena de maior pra menor por confirmed
        paises
        
        
--tentei utilizar a funcao splitOn, mas nao funciona no runcodes
--entao pesquisei e achei essa variacao da funcao words que ja existe
wordsWhen :: (Char -> Bool) -> String -> [String]
wordsWhen p s =  case dropWhile p s of
    "" -> []
    s' -> w : wordsWhen p s''
        where (w, s'') = break p s'
    
    
    
--funcao que transforma cada linha do arquivo em uma struct countryInfo
parseCountryInfo :: String -> CountryInfo
parseCountryInfo lineInfo =
    let fields = wordsWhen (==',') $ lineInfo
    in CountryInfo { --atribuicao para a struct
        country = fields !! 0,
        confirmed = read $ fields !! 1,
        deaths = read $ fields !! 2,
        recovery = read $ fields !! 3,
        active = read $ fields !! 4
    }
