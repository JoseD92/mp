program multi;

type

   informacion = char;

   puntero = ^cosa;

   cosa = record
      info : informacion;
      sig : puntero;
   end;

procedure agrega(pcosa : puntero; intro : informacion);
   begin
      while pcosa^.sig <> nil do begin
         pcosa:=pcosa^.sig;
      end;
      new(pcosa^.sig);
      pcosa:=pcosa^.sig;
      pcosa^.info:=intro;
   end;

procedure imprimecosa(pcosa : puntero);
   begin
      if pcosa = nil then writeln('nil')
      else begin
         writeln(pcosa^.info);
         while pcosa^.sig <> nil do begin
            pcosa:=pcosa^.sig;
            writeln(pcosa^.info);
         end;
      end;
   end;

procedure agregaen(lugar : longint ; pcosa : puntero; intro : informacion);
   var
      anterior : puntero;
      siguiente : puntero;
      bool : boolean;
      counter : longint;
      pcosa2 : puntero;
   begin
      counter := 0;
      bool := true;
      if lugar=0 then begin
         new(pcosa2);
         pcosa2^.sig:=pcosa^.sig;
         pcosa2^.info:=pcosa^.info;
         pcosa^.sig:=pcosa2;
         pcosa^.info:=intro;
         bool:=false;
      end;
      pcosa2:=pcosa;
      while ((counter<>lugar)and bool) do begin
         if (pcosa2^.sig<>nil) then begin
            anterior:=pcosa2;
            pcosa2:=pcosa2^.sig;
            counter:=counter+1;
         end else begin
            if counter+1<>lugar then begin
               bool:=false;
               writeln('no se puede');
            end else begin
               bool:=false;
               agrega(pcosa2,intro);
            end;
         end;
      end;
      if bool then begin
         siguiente:=pcosa2;
         new(pcosa2);
         pcosa2^.info:=intro;
         pcosa2^.sig:=siguiente;
         anterior^.sig:=pcosa2;
      end;
   end;

procedure borrarcosa(var pcosa : puntero);
   var
      pcosa2 : puntero;
      pcosa3 : puntero;
   begin
      pcosa3:=pcosa;
      pcosa2:=pcosa^.sig;
      while pcosa2<>nil do begin
         pcosa3:=pcosa2;
         pcosa2:=pcosa3^.sig;
         Dispose (pcosa3);
      end;
   pcosa:=nil;
   end;

procedure inviertecosa(pcosa : puntero);
   var
      aux : puntero;
      aux2 : puntero;
      aux3 : puntero;
      borrar : puntero;
   begin
      if pcosa^.sig<>nil then begin
      new(aux);
      aux^.info:=pcosa^.info;
      aux2:=pcosa;
      while aux2^.sig<>nil do begin
         new(aux3);
         aux2:=aux2^.sig;
         aux3^.sig:=aux;
         aux3^.info:=aux2^.info;
         aux:=aux3
      end;
      end;
      borrar:=pcosa^.sig;
      pcosa^.info:=aux^.info;
      pcosa^.sig:=aux^.sig;
      borrarcosa(borrar);
      Dispose (borrar);
      Dispose (aux);
   end;

   procedure imprime_numero(numero : puntero);
   var
      salida : ansistring;
   begin
      salida:=numero^.info;
      numero:=numero^.sig;
      while numero <> nil do begin
         salida:=numero^.info + salida;
         numero:=numero^.sig;
      end;
      writeln(salida);
   end;

   function operacion_suma(numero1 : puntero ; numero2 : puntero):puntero;
   var
      aux1:integer;
      aux2:integer;
      aux3:integer;
      aux4:string;
      aux5:puntero;
   begin
      new(operacion_suma);
      operacion_suma^.info:='0';
      val(numero1^.info,aux1);
      val(numero2^.info,aux2);
      aux3:=aux1+aux2;

      if aux3<10 then begin
         str(aux3,aux4);
         operacion_suma^.info:=aux4[1];
      end else begin
         str(aux3,aux4);
         operacion_suma^.info:=aux4[2];
         new(operacion_suma^.sig);
         operacion_suma^.sig^.info:='1';
      end;

      aux5:=operacion_suma;

      while ((numero1^.sig<>nil)or(numero2^.sig<>nil)) do begin
         if aux5^.sig = nil then begin
            new(aux5^.sig);
            aux5:=aux5^.sig;
            aux3:=0;
         end else begin
            aux5:=aux5^.sig;
            aux3:=1;
         end;
         if numero1^.sig<>nil then begin
            numero1:=numero1^.sig;
            val(numero1^.info,aux1);
         end else begin
            aux1:=0;
         end;
         if numero2^.sig<>nil then begin
            numero2:=numero2^.sig;
            val(numero2^.info,aux2);
         end else begin
            aux2:=0;
         end;
         aux3:=aux1+aux2+aux3;
         if aux3<10 then begin
            str(aux3,aux4);
            aux5^.info:=aux4[1];
         end else begin
            str(aux3,aux4);
            aux5^.info:=aux4[2];
            new(aux5^.sig);
            aux5^.sig^.info:='1';
         end;
      end;
   end;

   procedure lee_numero(var numero : puntero);
   var
      caracter:char;
      aux:puntero;
   begin
      read(caracter);
      numero^.info:=caracter;
      read(caracter);
      while ((ord(caracter)<>(26)) and (ord(caracter)<>(13)) and (ord(caracter)<>(10))) do begin
         aux:=numero;
         new(numero);
         numero^.sig:=aux;
         numero^.info:=caracter;
         read(caracter);
      end;
      //borrar siguientes dos lineas para enviar a ideone/spoj
      if ((ord(caracter)=(13)) or (ord(caracter)=(10))) then
        read(caracter);
   end;

   function mult_simple(numero : puntero ; multiplicador : char):puntero;
   var
      valor : integer;
      aux : integer;
      aux2 : puntero;
      aux3 : string;
      respuesta : integer;
   begin
      val(multiplicador,valor);
      val(numero^.info,aux);
      new(mult_simple);
      respuesta:=valor*aux;
      str(respuesta,aux3);
      if respuesta<10 then begin
         mult_simple^.info:=aux3[1];
      end else begin
         mult_simple^.info:=aux3[2];
         new(mult_simple^.sig);
         mult_simple^.sig^.info:=aux3[1];
      end;
      aux2:=mult_simple;
      numero:=numero^.sig;

      while numero<>nil do begin
         if aux2^.sig=nil then begin
            respuesta:=0;
            new(aux2^.sig);
            aux2:=aux2^.sig;
         end else begin
            aux2:=aux2^.sig;
            val(aux2^.info,respuesta);
         end;
         val(numero^.info,aux);
         respuesta:=respuesta+(valor*aux);
         str(respuesta,aux3);
         if respuesta<10 then begin
            aux2^.info:=aux3[1];
         end else begin
            aux2^.info:=aux3[2];
            new(aux2^.sig);
            aux2^.sig^.info:=aux3[1];
         end;
         numero:=numero^.sig;
      end;
   end;

   function operacion_mult(numero1 : puntero ; numero2 : puntero):puntero;
   var
      aux1:puntero;
      aux2: puntero;
      borrar:puntero;

   begin

      new(operacion_mult);
      operacion_mult^.info:='0';
      aux1:=mult_simple(numero2,numero1^.info);
      borrar:=operacion_mult;
      operacion_mult:=operacion_suma(operacion_mult,aux1);
      borrarcosa(borrar);
      dispose (borrar);
      numero1:=numero1^.sig;
      aux2:=operacion_mult;

      while numero1<>nil do begin
         borrarcosa(aux1);
         dispose (aux1);
         aux1:=mult_simple(numero2,numero1^.info);
         borrar:=aux2^.sig;
         aux2^.sig:=operacion_suma(aux1,aux2^.sig);
         aux2:=aux2^.sig;
         numero1:=numero1^.sig;
         borrarcosa(borrar);
         dispose (borrar);
      end;
      borrarcosa(aux1);
      dispose (aux1);
   end;

   procedure lee_numero_mult(var numero1 : puntero; var numero2 : puntero; var b:boolean);
   var
      caracter:char;
      aux:puntero;
   begin
      read(caracter);
      numero1^.info:=caracter;
      read(caracter);
      while caracter<>' ' do begin
         aux:=numero1;
         new(numero1);
         numero1^.sig:=aux;
         numero1^.info:=caracter;
         read(caracter);
      end;

      read(caracter);
      numero2^.info:=caracter;
      read(caracter);
      while ((ord(caracter)<>(26)) and (ord(caracter)<>(13)) and (ord(caracter)<>(10))) do begin
         aux:=numero2;
         new(numero2);
         numero2^.sig:=aux;
         numero2^.info:=caracter;
         read(caracter);
      end;
      //borrar siguientes dos lineas para enviar a ideone/spoj
      if ((ord(caracter)=(13)) or (ord(caracter)=(10))) then
        read(caracter);

      if (numero1^.sig=nil) and (numero1^.info='0') then b:=true;
      if (numero2^.sig=nil) and (numero2^.info='0') then b:=true;
   end;


var
   numero1:puntero;
   numero2:puntero;
   respuesta:puntero;
   casos: integer;
   cero:boolean;
begin
   writeln;
   readln(casos);
   while casos <> 0 do begin
      cero:=false;
      new(numero1);
      new(numero2);
      lee_numero_mult(numero1,numero2,cero);
      if not cero then begin
         respuesta:=operacion_mult(numero1,numero2);
         imprime_numero(respuesta);
         borrarcosa(respuesta); 
         dispose (respuesta);
      end else
         writeln('0');
      borrarcosa(numero1);
      borrarcosa(numero2);
      dispose (numero1);
      dispose (numero2);
      casos:=casos-1;
   end;
end.
