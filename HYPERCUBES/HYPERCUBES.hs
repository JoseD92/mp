import qualified Data.ByteString.Char8 as C

cases ([x]:xs) = take (fromInteger x) xs

resolv [x1,x2] = (x1^x2)-((x1-2)^x2)

main = do
  input <- C.getContents
  let k = map ((map (\(Just (x,_)) -> x)).(map C.readInteger).(C.words) ) $ C.lines input
  let j = (C.pack).unlines.(map show).(map resolv) $ (cases k)
  C.putStr j