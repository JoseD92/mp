x=int(input())
y=0
while (y<x):
 s=input().split(' ')
 n=int(s[0])
 i=int(s[1])
 resp = n**i - (n-2)**i
 print(resp)
 y = y+1
quit()