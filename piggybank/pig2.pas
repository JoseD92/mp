program pig;
type
   TA = Array of array of real;

var
   T : longint ; //casos a evaluar
   E : longint ; //peso vacio
   F : longint ; //peso lleno
   diferencia : longint ;//peso de monedas del cerdo
   N : longint ; //catidad de monedas diferentes
   A : TA ; //arreglo de valor - peso - relacion v/p - peso div  diferencial
   B : TA ; //pivote para cambios
    C : TA ;
   counter : longint;
   counter1 : longint ;
   counter2 : longint ;
   suma : longint ;
   listo : boolean ;
   min : longint ;//cantidad de dinero minima
   I,J : Integer;
   
   procedure determin;
   begin
	  repeat begin
	     A[counter1,4]:=(A[counter1,4] + 1)
		 if (counter1 < N ) then begin
		 begin determin end;
		 end else begin
		 repeat begin
		     suma:=(suma + (A[counter2,1] * A[counter1,4]))
		     counter2:=(
	  end until (
   end;
   
begin
   readln(T);
   listo:=false;
   repeat begin
      readln(E,F);//peso vacio-lleno
	  diferencia:=(F - E);
      if not ((1 <= E) and (E <= F) and (F <= 10000)) THEN begin
         halt;
      end;
	  readln(N);//cantidad de monedas
      if not ((1 <= N) and (N <= 500)) THEN begin
         halt;
      end;
	  Setlength(A,N,5); 
	  Setlength(B,1,5); 
	  Setlength(C,N,1);
	  counter1:=0;
	  repeat begin
	     readln(A[counter1,0],A[counter1,1]);
		 if not ((1 <= A[counter1,0]) and (A[counter1,0] <= 50000)) THEN begin
            halt;
         end;
		 if not ((1 <= A[counter1,1]) and (A[counter1,1] <= 10000)) THEN begin
            halt;
         end;
		 A[counter1,2]:=(A[counter1,0] / A[counter1,1]);
		 A[counter1,3]:=(diferencia div Trunc(A[counter1,1]));
		 A[counter1,4]:=0;//ultima columna - necesarias
		 counter1:=(counter1 + 1);
	  end until (counter1 = N);
	  counter1:=0;
	  counter2:=0;
	  //ordenando matriz con respecto a la relacion
	  //ordenado de burbuja
	  writeln;
	  	    For I:=0 to (N - 1) do  
    begin  
    For J:=0 to 3 do  
      Write(A[I,J]:1:0,' ');  
    Writeln;  
    end;  
	writeln;
	  repeat begin
	     counter1:=0;
	     repeat begin
		     if (A[counter1,2] > A[(counter1 + 1),2]) then begin
			     B[0]:=A[counter1];
				 A[counter1]:=A[(counter1 + 1)];
				 A[(counter1 + 1)]:=B[0];
			 end;
		     counter1:=(counter1 + 1);
		 end until (counter1 = (N +(-1)));
	     counter2:=(counter2 + 1);
	  end until (counter2 = N);
	    For I:=0 to (N - 1) do  
    begin  
    For J:=0 to 3 do  
      Write(A[I,J]:1:0,' ');  
    Writeln;  
    end;  
	
	//evaluando catidad de monedas de cada tipo
	counter1:=0;
	counter2:=0;
    begin determin end;
	end until true;
end.
	  
	  
	  
	  
	  
	  