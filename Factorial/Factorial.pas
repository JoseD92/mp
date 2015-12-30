program Factorial;
(*
function fac(N : real):real;
   begin
      fac:=N;
      N:=N-1;
      while N <> 0 do begin
         fac:=fac*N;
         N:=N-1;
      end;
   end;*)

function  last(n : longint; espacios : longint):longint;
   var
      counter : longint;
   begin
      counter:=0;
      while not ((n mod 10) = 0) do begin
         counter:=counter+1;
         n:=n-1;
      end;
      if espacios<>1 then
         counter:=counter+10*last((n div 10),espacios-1);
      last:=counter;
   end;

var
   N : longint;
   ceros : longint;
   mult1 : longint;
   mult2 : longint;
   casos : longint;
   cuenta : longint;
   counter : longint;
   counter2: longint;
   espacios : longint;
   k : longint;
begin
   readln(casos);
   counter:=0;
   ceros:=0;
   while counter<casos do begin
      ceros:=0;
      readln(N);
      counter2:=2;
      mult2:=1;
      espacios:=1;
      k:=10;
      while counter2<=N do begin
         if ((counter mod k)=0) then begin
            espacio:=espacio+1;
            k:=k*10;
         end;
         mult1:=counter2;
         if mult1=0 then mult1:=10;
         cuenta:=mult1*mult2;
//writeln(cuenta,' ',mult1,' ',mult2,' ',ceros);
         while ((cuenta mod 10) = 0) do begin
            ceros:=ceros+1;
            cuenta:=cuenta div 10;
         end;
         mult2:=last(cuenta,espacio);
         counter2:=counter2+1;
      end;
      writeln(ceros);
      counter:=counter+1;
   end;
end.