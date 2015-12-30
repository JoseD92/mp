program palindor;

   procedure arreglizar(palindromo : QWord; var arreglo : array of byte; var tamanho : QWord);
   var I:longint;
   begin
      for I:=0 to 19 do arreglo[I]:=0;
      I:=1;
      repeat begin
         while ((palindromo mod 10)<>0) do begin
            palindromo:=palindromo-1;
            arreglo[20-I]:=arreglo[20-I]+1;
         end;
      palindromo:=palindromo div 10;
      I:=I+1;
      end until(palindromo = 0);
      tamanho:=I-1;
   end;

   function son(arreglo : array of byte; tamanho : QWord):boolean;
   var I: longint;
   begin
      son:=true;
      for I:=0 to tamanho-1 do begin
         if (arreglo[19-I]<>9) then son:=false;
      end;
   end;

   function elev(z:QWord;x:QWord):QWord;
   var I:longint;
   begin
      elev:=1;
      if (x=0) then elev:=1
      else begin
         for I:=1 to x do elev:=(elev*z);
      end;
   end;

   function numerar(var arreglo: array of byte; tamanho : QWord):QWord;
   var I: longint;
   begin
      numerar:=0;
      for I:=0 to tamanho-1 do numerar:=numerar + arreglo[tamanho-1-I]*elev(10,I);
   end;

   procedure copiamitad(arreglo : array of byte; tamanho:QWord ; medio : QWord ; var mitad : array of byte);
   var I:longint;
   begin
      for I:=(20-tamanho) to (20-tamanho+medio-1) do begin
         mitad[I-(20-tamanho)]:=arreglo[I];
      end;
   end;

   function palindrar(var mitad : array of byte; tamanho: QWord; medio : QWord):QWord;
   var I: array of byte; J:longint;
   begin
      Setlength(I,tamanho-1);
      for J:=0 to medio-1 do I[J]:=mitad[J];
      for J:=0 to medio-1 do I[tamanho-J-1]:=mitad[J];
      palindrar:=numerar(I,tamanho);
   end;

   procedure suma(var mitad : array of byte; lugar : QWord);
   begin
      if (mitad[lugar]=9) then begin mitad[lugar]:=0; suma(mitad,lugar-1); end
      else begin
         mitad[lugar]:=mitad[lugar]+1;
      end;
   end;

var 
   casos: QWord;
   palindromo : QWord;
   arreglo : array[0..19] of byte;
   mitad : array of byte;
   medio: QWord;
   counter: QWord;
   numero : QWord;
   tamanho : QWord;
   a : boolean;
I : longint ;

begin
   counter:=0;
   repeat begin
      numero:=counter;
      arreglizar(numero,arreglo,tamanho);
      a:=son(arreglo,tamanho);
      if a then palindromo:=numero+2;
      if ((tamanho=1) and not(a)) then palindromo:=numero+1;
      if (not(tamanho=1) and not(a)) then begin
         if ((tamanho mod 2)=0) then begin
            medio:=(tamanho div 2);
            if (medio<>1) then Setlength(mitad,medio-1)
            else Setlength(mitad,1);
            copiamitad(arreglo,tamanho,medio,mitad);
            repeat begin
               palindromo:=palindrar(mitad,tamanho,medio);
               suma(mitad,medio-1);
            end until(palindromo>numero);
         end else begin
            medio:=(((tamanho-1) div 2)+1);
            Setlength(mitad,medio-1);
            copiamitad(arreglo,tamanho,medio,mitad);
            repeat begin
               palindromo:=palindrar(mitad,tamanho,medio);
               suma(mitad,medio-1);
            end until(palindromo>numero);
         end;
      end;
      writeln(palindromo);
      counter:=counter+1;
   end until(counter>= 100000000);
end.