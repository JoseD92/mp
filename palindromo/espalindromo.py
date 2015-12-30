x = input()
counter1 = 0
counter2 = len(x) - 1
bool = 1
while ((counter2 > counter1) and bool):
   if x[counter1] != x[counter2]:
      bool = 0
   counter1 = counter1 + 1
   counter2 = counter2 - 1
print(len(x),bool)