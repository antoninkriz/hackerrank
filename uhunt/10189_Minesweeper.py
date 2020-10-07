#  10189 - Minesweeper
count = 0
while True:
  y, x = [int(x) for(x) in input().split()]
  if y == 0 and x == 0:
    break

  count += 1
  print("{1}Field #{0}:".format(count, '\n' if count != 1 else ''))

  inp = [['.'] * (x + 2)] * (y + 2)
  
  for i in range(y):
    inp[i + 1] = ['.'] + list(input()) + ['.']

  for r in range(y):
    for c in range(x):
      if inp[r + 1][c + 1] == '*':
        print('*', end='')
        continue
      
      row = [1 for c in inp[r][c : c + 3] if c == '*'] +\
            [1 for c in inp[r + 1][c : c + 3] if c == '*'] +\
            [1 for c in inp[r + 2][c : c + 3] if c == '*']

      print(sum(row), end='')
    print()
