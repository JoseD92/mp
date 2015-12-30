program palin;

function son(numero : array of char ; tamano : longint):boolean;
   var
      counter : longint;
   begin
      son:=true;
      counter:=0;
      while (son and (counter<tamano)) do begin
         if (numero[counter] <> '9') then son:=false;
         counter:=counter+1;
      end;
   end;

procedure ceros(tamano : longint ; var palindromo : array of char);
   var
      counter : longint;
   begin
      counter:=0;
      palindromo[0]:='1';
      while counter<(tamano-1) do begin
         palindromo[counter+1]:='0';
         counter:=counter+1;
      end;
      palindromo[counter+1]:='1';
   end;

procedure strinear(tamano : longint ; palindromo : array of char ; var salida : ansistring);
   var
      counter : longint;
   begin
      counter:=0;
      salida:='';
      while counter<tamano do begin
         salida:=salida+palindromo[counter];
         counter:=counter+1;
      end;
   end;

procedure copiamitad(numero: array of char;var palindromo: array of char;
          tamano : longint ; medio : longint ; a : integer);
   var
      counter : longint;
      counter2 : longint;
   begin
      counter:=0;
      while counter<medio do begin
         palindromo[counter]:=numero[counter];
         counter:=counter+1;
      end;
      palindromo[counter]:=numero[counter];
      counter2:=counter -1 - a;
      while counter<tamano do begin
         palindromo[counter]:=numero[counter2];
         counter:=counter+1;
         counter2:=counter2-1;
      end;
   end;

function menorigual(palindromo : array of char;numero : array of char;tamano : longint):boolean;
   var
      counter : longint;
      aux1 : integer;
      aux2 : integer;
   begin
      menorigual:=true;
      counter:=1;
      val(palindromo[0],aux1);
      val(numero[0],aux2);
      while ((counter<tamano) and (aux1=aux2)) do begin
         val(palindromo[counter],aux1);
         val(numero[counter],aux2);
         counter:=counter+1;
      end;
      if (aux1 < aux2) then menorigual:=true;
      if (aux1 > aux2) then menorigual:=false;
   end;

procedure suma(var palindromo: array of char; medio : longint ; moder : integer);
   var
      counter1 : longint;
      counter2 : longint;
      bool : boolean;
      aux : integer;
      aux2 : string;
   begin
      bool:=true;
      counter1:=medio-1+moder;
      counter2:=medio-1;
      while bool do begin
         if palindromo[counter1]='9' then begin
            if counter1=counter2 then begin
               palindromo[counter1]:='0';
            end else begin
               palindromo[counter1]:='0';
               palindromo[counter2]:='0';
            end;
            counter1:=counter1+1;
            counter2:=counter2-1;
         end else begin
            if counter1=counter2 then begin
               val(palindromo[counter1],aux);
               aux:=aux+1;
               str(aux,aux2);
               palindromo[counter1]:=aux2[1];
            end else begin
               val(palindromo[counter1],aux);
               aux:=aux+1;
               str(aux,aux2);
               palindromo[counter1]:=aux2[1];
               palindromo[counter2]:=aux2[1];
            end;
            bool:=false;
         end;
      end;
   end;

var 
   numero : array[0..1000000] of char;
   tamano : longint;
   medio : longint;
   palindromo : array[0..1000000] of char;
   casos : longint;
   counter : longint;
   counter2 : longint;
   caracter : char;
   aux : integer ;
   i : longint;

begin
   readln(casos);
   counter:=0;
   while (counter<=(casos-1)) do begin
      if counter>0 then
         writeln;
      read(caracter);
      counter2:=0;
      while ((ord(caracter)<>(26)) and (ord(caracter)<>(13)) and (ord(caracter)<>(10))) do begin
         numero[counter2]:=caracter;
         counter2:=counter2+1;
         tamano:=counter2;
         read(caracter);
      end;
      //borrar siguientes dos lineas para enviar a ideone/spoj
      if ((ord(caracter)=(13)) or (ord(caracter)=(10))) then
        read(caracter);
      if son(numero,tamano) then begin
         ceros(tamano,palindromo);
         tamano:=tamano+1;
      end else begin
         if tamano=1 then begin
            val(numero[0],aux);
         end else begin
            if ((tamano mod 2) = 0) then begin
               medio:=tamano div 2;
               copiamitad(numero,palindromo,tamano,medio,0);
               if menorigual(palindromo,numero,tamano) then
                  suma(palindromo,medio,1);
            end else begin
               medio:=((tamano-1) div 2) + 1;
               copiamitad(numero,palindromo,tamano,medio,1);
               if menorigual(palindromo,numero,tamano) then
                  suma(palindromo,medio,0);
            end;
         end;
      end;
      counter:=counter+1;
      if tamano<>1 then
      for i:=0 to tamano-1 do write(palindromo[i])
      else
      write(aux+1);
   end;
end.