def son(numero):
   counter = 0
   bool = 1
   while ((counter < len(numero)) and bool):
      if int(numero[counter]) != 9:
         bool = 0
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
      x = len(numero)
      while ((counter < x) and bool):
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
   while counter >= 0:
      palindromo = palindromo + mitad[counter]
      counter = counter - 1
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

casos = int(input())
counter = 0
while counter < casos:
   numero = input()
   bool = son(numero)
   if bool:
      palindromo = ceros(len(numero))
   else:
      if len(numero) == 1:
         palindromo = int(numero) + 1
      else:
         if ((len(numero) % 2) == 0):
            medio = len(numero)/2
            mitad = copiamitad(numero,medio)
            palindromo = 0
            palindromo = palindrar(mitad,0)
            while menorigual(palindromo,numero):
               mitad = sumauno(mitad)
               palindromo = palindrar(mitad,0)
         else:
            medio = ((len(numero)-1)/2)+1
            mitad = copiamitad(numero,medio)
            palindromo = 0
            palindromo = palindrar(mitad,1)
            while menorigual(palindromo,numero):
               mitad = sumauno(mitad)
               palindromo = palindrar(mitad,1)
   print(palindromo)
   counter = counter + 1