program pig;
var
   T : longint ; //casos a evaluar
   counter : longint ; //contador de ciclo
   counter1 : longint ; //contador de ciclo interno
   E : longint ; //peso vacio
   F : longint ; //peso lleno
   N : longint ; //catidad de monedas diferentes
   P : array of longint;
   W : array of longint;
   R : array of real; //relacion valor peso
   min : longint ;//posicion de moneda a usar
   comp : real ;
   listo : boolean ; //ya se termino
   diferencia : longint ;//peso de monedas del cerdo
   existsol : boolean ; //existe o no solucion
   suma : longint ;
   minmoney : longint ;
   
   
begin
   listo:=false;
   suma:=0;
   counter;=0;
   readln(T);
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
	  setlength(P,N);//valor moneda
	  setlength(W,N);//peso moneda
	  counter1:=0;
	  repeat begin
	     readln(P[counter1],W[counter1]);
		 R[counter1]:=(P[counter1] / W[counter1])
	     counter1:=(counter1 + 1);
	  end until (counter1 = N);
	  counter1:=0;
	  existsol:=false;
	  repeat begin
	     //chequeando mas pequeno
		  if (counter1 = 0) then begin
			 comp:=R[0];
			 min:=0;
			 repeat begin
			    if (R[(counter1 + 1)] < comp) then begin
			 	  comp:=R[(counter1 + 1)];
			      min:=(counter1 + 1);
			 	end;
			    counter1:=(counter1 + 1);
		     end until (counter1 = (N - 1));
		  end else begin
		     R[min]:=(-1);
			 counter1:=0;
			 repeat begin
			     if (counter1 < N) then begin
				     if (R[counter1] <> -1) then begin
					     comp:=R[counter1];
						 min:=counter1;
						 listo:=true;
					 end;
				 end;
				 if (counter1 = N) THEN begin
				     existsol:=false;
			     end;
				 counter1:=(counter1 + 1);
			 end until ((counter1 > N) or (listo = true));
			 listo:=false;
			 counter1:=1;
			 if (existsol <> 0) then begin
			     counter1:=0;
			     repeat begin
			         if ((R[counter1] < comp) and (R[counter1] <> -1)) then begin
			        	  comp:=R[(counter1 + 1)];
			              min:=(counter1 + 1);
			         end;
			         counter1:=(counter1 + 1);
		          end until (counter1 = N);
				  counter1:=1;
			 end;
		 end;
		 //evaluando cantidad de monedas
		 if (existsol = false) then begin
		     writeln('This is impossible.');
			 listo:=true;
		 end else begin
		     suma:=(suma + ((
			 minmoney
	     
	  end until (listo = true);
	  suma:=0;
	  listo:=false;
	  existsol:=true;
	  counter:=(counter + 1);
   end until (counter = T);
   
   
   
   