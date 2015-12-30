def son(numero):
   counter = 0
   bool = 'true'
   while ((counter < len(numero)) and (bool == 'true')):
      if int(numero[counter]) != 9:
         bool = 'false'
      counter = counter + 1
   return(bool)

def ceros(numero):
   x = str(1)
   counter = 0
   while counter < (numero - 1):
      x = x + str(0)
      counter = counter + 1
   x = x + str(1)
   return(x)

def menorigual(palindromo,numero):
   if palindromo == 0:
      return(1)
   else:
      counter = 0
      bool = 1
      while ((counter < len(numero)) and bool):
         if palindromo[counter] > numero[counter]:
            bool = 0
         counter = counter + 1
      return(bool)

def copiamitad(numero,medio):
   counter = 0
   mitad = ''
   while counter < medio:
      mitad = mitad + numero[counter]
      counter = counter + 1
   return(mitad)

def palindrar(mitad,a):
   palindromo = mitad
   counter = len(mitad) - 1 - a
   '''  if (a == 0):'''
   while counter >= 0:
      palindromo = palindromo + mitad[counter]
      counter = counter - 1
   '''else:
      while counter > 0:
         palindromo = palindromo + mitad[counter]
         counter = counter - 1'''
   return(palindromo)

def sumauno(mitad):
   counter = len(mitad) - 1
   mitad2 = ''
   bool = 1
   while counter >= 0:
      if bool:
         if mitad[counter] == '9':
            mitad2 = str(0) + mitad2
         else:
            mitad2 = str(int(mitad[counter]) + 1) + mitad2
            bool = 0
      else:
         mitad2 = mitad[counter] + mitad2
      counter = counter - 1
   return(mitad2)

'''def suma(mitad,medio):
   mitad2 = mitad
   print(type(medio),medio)
   if int(mitad[medio]) != 9:
      mitad2[medio] = str(int(mitad2[medio]) + 1)
   else:
      mitad2 = suma(mitad2,(medio-1))
      mitad2[medio] = str(0)
   return(mitad2)'''

casos = int(input())
counter = 0
while counter < casos:
   numero = input()
   bool = son(numero)
   if bool == 'true' :
      palindromo = ceros(len(numero))
   else:
      if len(numero) == 1:
         palindromo = int(numero) + 1
      else:
         if ((len(numero) % 2) == 0):
            medio = len(numero)/2
            mitad = copiamitad(numero,medio)
            palindromo = 0
            while menorigual(palindromo,numero):
               palindromo = palindrar(mitad,0)
               '''print(mitad,palindromo,len(mitad))'''
               mitad = sumauno(mitad)
         else:
            medio = ((len(numero)-1)/2)+1
            mitad = copiamitad(numero,medio)
            palindromo = 0
            while menorigual(palindromo,numero):
               palindromo = palindrar(mitad,1)
               mitad = sumauno(mitad)
   print(palindromo)
   counter = counter + 1