{$COPERATORS ON}
program fmult;

var
   casos : longint;
   numero1 : ansistring;
   numero2 : ansistring;
   i : longint;
   apuntador1 : ^char;
   apuntador2 : ^char;
begin
   readln(casos);
   while casos <> 0 do begin
      readln(numero2);
      numero1:='';
      while numero2[1] <> ' ' do begin
         numero1:=numero1+numero2[1];
         delete(numero2,1,1);
      end;
      delete(numero2,1,1);
      apuntador1

      casos-=1;
   end;
end.