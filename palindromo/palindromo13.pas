{$COPERATORS ON}
program palin;

var
   numero : ansistring;
   casos : longint;
   apuntador : ^char;
   apuntador2 : ^char;
   apuntador3 : ^byte;
   puntero : pointer;
   son :  boolean ; //dice si todos los numeros son 9s.
   i : longint;
   tamanho : longint;
   valor : byte;
   mitad : longint;
   sumar : boolean;
   respuesta : ansistring;

begin
   respuesta:='';
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

            i:=1;
            apuntador:=@numero[mitad];
            apuntador2:=@numero[mitad+1];
            if sumar then begin
               while sumar do begin
                  if apuntador^ <> '9' then begin
                     puntero:=apuntador;
                     apuntador3:=puntero;
                     apuntador3^+=1;
                     apuntador2^:=apuntador^;
                     sumar:=false;
                  end else begin
                     apuntador^:='0';
                     apuntador2^:='0';
                  end;
                  apuntador-=1;
                  apuntador2+=1;
                  i+=1;
               end;
            end;

            for i := i to mitad do begin
               apuntador2^:=apuntador^;
               apuntador-=1; 
               apuntador2+=1; 
            end;
            respuesta:=respuesta + numero + char(10);

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

            i:=1;
            apuntador:=@numero[mitad];
            apuntador2:=@numero[mitad];
            if sumar then begin
               while sumar do begin
                  if apuntador^ <> '9' then begin
                     puntero:=apuntador;
                     apuntador3:=puntero;
                     apuntador3^+=1;
                     apuntador2^:=apuntador^;
                     sumar:=false;
                  end else begin
                     apuntador^:='0';
                     apuntador2^:='0';
                  end;
                  apuntador-=1;
                  apuntador2+=1;
                  i+=1;
               end;
            end;

            for i := i to mitad do begin
               apuntador2^:=apuntador^;
               apuntador-=1; 
               apuntador2+=1; 
            end;
            respuesta:=respuesta + numero + char(10);

         end;
      end else begin
         val(numero,valor);
         valor+=1;
         str(valor,numero);
         respuesta:=respuesta + numero + char(10);
      end;
   end else begin
      numero:='1';
      i := 0;
      while i <> tamanho-1 do begin numero:=numero+'0'; i+=1; end;
      numero:=numero+'1';
      respuesta:=respuesta + numero + char(10);
   end;

   casos-=1;
   end;
   write(respuesta);
end.