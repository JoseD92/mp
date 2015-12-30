program pig;
var
   A : array of longint ;//arreglo de funcion
   B : array of Word;//matriz de datos ingresados
   C : array of Word;
   T : Word ; //casos
   E : Word ; //peso cochino vacion
   F : Word ; //peso de cochino lleno
   N : Word ; //catidad de monedas diferentes
   diferencia : Word ; //E - F
   I : Word ;
   K : word ;

   function valmin(X, Y, z:word ;v,w,l:longint) : longint;
   begin
      //valmin(X) = min(B[counter1] + valmin (X - C[counter1]))
      if (X = 0) then begin
         valmin:=0;
      end else begin
         if (A[X] = 0) then begin
   begin
      for z:=0 to (N - 1) do begin
         if (((X - (C[z]))) >= 0) then begin
             v:=valmin((X - (C[z])),(Y + 1),0,0,0,0);
             if (v >= 0) then begin
                 w:=((B[z]) + v);
                 if (l = (-1)) then begin
                      l:=w;
                 end else begin
                    if (w < l) then begin
                     l:=w;
                    end;
                 end;
valmin:=l;
A[X]:=l;
             end;
         end;
      end;
   end;
         end else begin
             valmin:= A[X];
         end;
      end;
   end;

Begin
   readln(T);
      for K:=0 to (T - 1) do begin
      readln(E,F);//peso vacio-lleno
	  diferencia:=(F - E);
	  readln(N);//cantidad de monedas
      Setlength(B,N); 
      Setlength(C,N); 
      Setlength(A,(diferencia + 1));
      for I := 0 to (N -1) do readln(B[I],C[I]); //valor - peso
      if (diferencia <> 0) then begin
         if (valmin(diferencia,0,0,0,0,0) = 0) then begin
             writeln('This is impossible.');
         end else begin
             writeln('The minimum amount of money in the piggy-bank is ',A[diferencia]);
         end
      end else begin
         writeln('The minimum amount of money in the piggy-bank is ',0);
      end;
      Setlength(A,0);
   end;
end.