import collections 
s, t = input().split() 
deq1 = collections.deque() 
deq2 = collections.deque() 
for i in range(len(s)): 
    if s[i] != '#': 
        deq1.append(s[i]) 
    else: 
        deq1.pop() 
for i in range(len(t) ): 
    if  t[i] != '#': 
        deq2.append(t[i]) 
    else: 
        deq2.pop() 
if deq1 == deq2: 
    print("Yes") 
else: 
    print("No")