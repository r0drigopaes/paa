def naive(length):
	if (length == 0): return 0
	
	best = -1;
	for i in range(length):
	  aux = prices[i] + naive(length - i - 1)
	  best = best if (best > aux) else aux
	return best

def topDown_dp(length):
  if(memo[length] != -1):
    return memo[length]
  
  best = -1
  for i in range(length):
    aux = prices[i] + topDown_dp(length - i - 1)
    best = best if (best > aux) else aux
  
  memo[length] = best
  return memo[length]

def bottomUp_dp(length):
  for i in range(1, length + 1):
    best = -1
    for j in range(i):
      aux = prices[j] + memo[i - j - 1]
      best = best if (best > aux) else aux
    memo[i] = best
  
  return memo[length] 
  
rodLength = int(input())
while(rodLength != 0):
  prices = []
  memo = []
  
  for i in range(rodLength):
    prices.append(int(input()))
  
  memo.append(0)
  memo.extend([-1 for x in range(rodLength)])

  #print(naive(rodLength))
  #print(topDown_dp(rodLength))
  #print(bottomUp_dp(rodLength))
  rodLength = int(input())
