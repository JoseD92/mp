main = do
  num <- getLine
  if num /= "42"
    then do
      putStrLn num
      main
    else return ()