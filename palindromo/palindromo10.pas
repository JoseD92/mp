{$COPERATORS ON}
program palin;

var
   numero : ansistring;
   casos : longint;
   apuntador : ^char;
   apuntador2 : ^char;
   son :  boolean ; //dice si todos los numeros son 9s.
   i : longint;
   tamanho : longint;
   valor : byte;
   mitad : longint;
   sumar : boolean;
   s : string;
begin
   readln(casos);
   while casos <> 0 do begin

   readln(numero);
   tamanho:=length(numero);

   son := true;
   i :=1;
   apuntador:=@numero[1];
   while (i <= tamanho) and son do begin
      if apuntador^ <> '9' then son:= false;
      apuntador+=1;
      i+=1;
   end;

   if not son then begin
      if tamanho <> 1 then begin
         if (tamanho mod 2) = 0 then begin
            mitad := tamanho div 2;

            i := 0 ;
            sumar:=true;
            apuntador:=@numero[mitad];
            apuntador2:=@numero[mitad+1];
            while (i < mitad ) and (apuntador^ = apuntador2^) do begin
               apuntador-=1; apuntador2+=1; i+=1;
            end;
            if apuntador^ > apuntador2^ then sumar:=false;

            if sumar then begin
               apuntador:=@numero[mitad];
               while sumar do begin
                  if apuntador^ <> '9' then begin
                     val(apuntador^,valor);
                     valor+=1;
                     str(valor,s);
                     apuntador^:=s[1];
                     sumar:=false;
                  end else begin
                     apuntador^:='0';
                     apuntador-=1;
                  end;
               end;
            end;

            apuntador:=@numero[1];
            for i := 1 to mitad do begin write(apuntador^); apuntador+=1; end;
            apuntador:=@numero[mitad];
            for i := 1 to mitad do begin write(apuntador^); apuntador-=1; end;

         end else begin
            mitad := (tamanho + 1) div 2;

            i := 0 ;
            sumar:=true;
            apuntador:=@numero[mitad-1];
            apuntador2:=@numero[mitad+1];
            while (i < mitad-1 ) and (apuntador^ = apuntador2^) do begin
               apuntador-=1; apuntador2+=1; i+=1;
            end;
            if apuntador^ > apuntador2^ then sumar:=false;

            if sumar then begin
               apuntador:=@numero[mitad];
               while sumar do begin
                  if apuntador^ <> '9' then begin
                     val(apuntador^,valor);
                     valor+=1;
                     str(valor,s);
                     apuntador^:=s[1];
                     sumar:=false;
                  end else begin
                     apuntador^:='0';
                     apuntador-=1;
                  end;
               end;
            end;

            apuntador:=@numero[1];
            for i := 1 to mitad do begin write(apuntador^); apuntador+=1; end;
            apuntador-=2;
            for i := 1 to mitad-1 do begin write(apuntador^); apuntador-=1; end;

         end;
      end else begin
         val(numero,valor);
         write(valor+1);
      end;
   end else begin
      write('1');
      for i := 0 to tamanho-1 do if i<>tamanho-1 then write('0');
      write('1');
   end;
   writeln;

   casos-=1;
   end;
end.