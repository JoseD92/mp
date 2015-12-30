program pig;
type
   TP = array of array of longint ;
var
   A : array of longint ;//arreglo de funcion
   ypo : TP ;
   B : TP ;//matriz de datos ingresados
   T : Word ; //casos
   E : Word ; //peso cochino vacion
   F : Word ; //peso de cochino lleno
   N : Word ; //catidad de monedas diferentes
   diferencia : Word ; //E - F
   I : Word ;
   K : word ;
   J : array of word ;

   function valmin(X, Y:word) : longint;
   begin
      //valmin(X) = min(B[counter1,0] + valmin (X - B[counter1,1]))
      if (X = 0) then begin
         valmin:=0;
      end else begin
         if (A[X] = -1) then begin
   begin
      J[Y]:=0;
      repeat begin
         if (((X - (B[J[Y],1]))) >= 0) then begin
         ypo[Y,1]:=valmin((X - (B[J[Y],1])),(Y + 1));
            if (ypo[Y,1] >= 0) then begin
                ypo[Y,0]:=((B[J[Y],0]) + ypo[Y,1]);
                if (A[X] = (-1)) then begin
                     A[X]:=ypo[Y,0];
                end else begin
                    if (ypo[Y,0] < A[X]) then begin
                     A[X]:=ypo[Y,0];
                    end;
                end;
            end;
         end;
         J[Y]:=(J[Y] + 1);
      end until (J[Y] = N);
   end;
             valmin:=A[X];
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
      Setlength(B,N,2); 
      Setlength(A,(diferencia + 1));
      Setlength(J,(diferencia + 2));
      Setlength(ypo,(diferencia + 2),2);
      for I := 0 to diferencia do A[I]:=(-1);
      for I := 0 to (N -1) do readln(B[I,0],B[I,1]); //valor - peso
      if (diferencia <> 0) then begin
         if (valmin(diferencia,0) = -1) then begin
             writeln('This is impossible.');
         end else begin
             writeln('The minimum amount of money in the piggy-bank is ',A[diferencia]);
         end
      end else begin
         writeln('The minimum amount of money in the piggy-bank is ',0);
      end;
   end;
end.