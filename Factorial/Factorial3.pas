program Factorial;

var
   N : longint;
   ceros : longint;
   casos : longint;
   counter : longint;
   qi : longint;

begin
   readln(casos);
   counter:=0;
   while counter<casos do begin
      ceros:=0;
      readln(N);
      qi:=(N div 5);
      ceros:=qi;
      while (qi <> 0) do begin
         qi:=(qi div 5);
         ceros:=ceros+qi;
      end;
      writeln(ceros);
      counter:=counter+1;
   end;
end.