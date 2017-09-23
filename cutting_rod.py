def naive(length):
  best = -1
  for i in range(length):
    best = best if (best > prices[i] + topDown(length - i - 1)) else prices[i] + topDown(length - i - 1)
  return best

def topDown(length):
  if(memo[length] != -1):
    return memo[length]
  
  best = -1
  for i in range(length):
    best = best if (best > prices[i] + topDown(length - i - 1)) else prices[i] + topDown(length - i - 1)
  
  memo[length] = best
  return memo[length]

def bottomUp(length):
  for i in range(length):
    best = -1
    for j in range(i + 1):
      best = best if (best > prices[i] + memo[j - i - 1]) else prices[i] + memo[j - i - 1]
    memo[i] = best
  
  return memo[length] 
  
rodLength = input()
while(rodLength != ''):
  iRodLength = int(rodLength)
  prices = []
  memo = []
  
  prices.extend(list(map(int, input().split())))
  
  memo.append(0)
  memo.extend([-1 for x in range(iRodLength)])

  #print(naive(iRodLength))
  #print(topDown(iRodLength))
  #print(bottomUp(iRodLength))
  rodLength = input()
