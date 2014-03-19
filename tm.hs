data Tape = Tape [Int] Int [Int]
  deriving Show

-- Tape [1,0] 2 [3,4]
-- corresponds to
-- 0  1  2  3  4
--      /|\

-- If we move left, we have
-- 0  1  2  3  4
--   /|\
-- which is
-- Tape [0] 1 [2,3,4]

-- We assume that the tape has value 0 beyond its current boundaries.

moveLeft :: Tape -> Tape
moveLeft (Tape [] current right) = Tape [] 0 (current:right)
moveLeft (Tape (x:xs) current right) = Tape xs x (current:right)

moveRight :: Tape -> Tape
moveRight (Tape l c r) = moveLeft (Tape r c l)

write :: Tape -> Int -> Tape
write (Tape l _ r) n = Tape l n r

