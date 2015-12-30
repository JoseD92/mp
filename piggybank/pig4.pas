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
   counter : Word ; //contador ciclo principal
   counter1 : Word ; //contador ciclos segundarios
   counter2 : Word ;
   I : Word ;
   J : TP ;
   function min(X:longint) : longint; forward;
   function valmin(X:longint) : longint;
   begin
      //valmin(X) = min(B[counter1,0] + valmin (X - B[counter1,1]))
      if (X = 0) then begin
         valmin:=0;
      end else begin
         if (A[X] = -1) then begin
             A[X]:=min(X);
             valmin:=A[X];
         end else begin
             valmin:= A[X];
         end;
      end;
   end;
   function min(X:longint) : longint;
   begin
      counter2:=(counter2 + 1);
      J[counter2,0]:=0;
      repeat begin
         if (((X - (B[J[counter2,0],1]))) >= 0) then begin
         ypo[counter2,1]:=(valmin(X - (B[J[counter2,0],1])));
            if (ypo[counter2,1] >= 0) then begin
                ypo[counter2,0]:=((B[J[counter2,0],0]) + ypo[counter2,1]);
                if (J[counter2,1] = (-1)) then begin
                     J[counter2,1]:=ypo[counter2,0];
                end else begin
                    if (ypo[counter2,0] < J[counter2,1]) then begin
                     J[counter2,1]:=ypo[counter2,0];
                    end;
                end;
            end;
         end;
         J[counter2,0]:=(J[counter2,0] + 1);
      end until (J[counter2,0] = N); 
      min := J[counter2,1];
      J[counter2,1]:=(-1);
      counter2:=(counter2 - 1);
   end;
Begin
   readln(T);
   counter2:=(-1);
   repeat begin
      readln(E,F);//peso vacio-lleno
	  diferencia:=(F - E);
	  readln(N);//cantidad de monedas
      counter1:=0;
      Setlength(B,N,2); 
      Setlength(A,(diferencia + 1));
      Setlength(J,(diferencia + 2),2);
      Setlength(ypo,(diferencia + 2),2);
      for I := 0 to diferencia do A[I]:=(-1);
      for I := 0 to (diferencia + 1) do J[I,1]:=-1;
	  repeat begin
	     readln(B[counter1,0],B[counter1,1]); //valor - peso
		 counter1:=(counter1 + 1);
	  end until (counter1 = N);
      if (diferencia <> 0) then begin
         if (valmin(diferencia) = -1) then begin
             writeln('This is impossible.');
         end else begin
             writeln('The minimum amount of money in the piggy-bank is ',A[diferencia]);
         end
      end else begin
         writeln('The minimum amount of money in the piggy-bank is ',0);
      end;
      counter:=(counter + 1);
   end until (counter = T);
end.