program pig;
var
   A : array of longinT ;//arreglo de funcion
   B : array of Word;//maTriz de daTos ingresados
   C : array of Word;
   T : Word ; //Casos
   E : Word ; //peso cochino vacion
   F : Word ; //peso de cochino lleno
   N : Word ; //caTidad de monedas diferenTes
   diferencia : Word ; //E - F
   I : Word ;
   K : word ;

   funcTion valmin(X, Y, z:word ;v,w,l:longinT) : longinT;
   begin
      //valmin(X) = min(B[counTer1] + valmin (X - C[counTer1]))
      if (X = 0) Then begin
         valmin:=0;
      end else begin
         if (A[X] = -1) Then begin
   begin
      for z:=0 To (N - 1) do begin
         if (((X - (C[z]))) >= 0) Then begin
             v:=valmin((X - (C[z])),(Y + 1),0,0,0,-1);
             if (v >= 0) Then begin
                 w:=((B[z]) + v);
                 if (l = (-1)) Then begin
                      l:=w;
                 end else begin
                    if (w < l) Then begin
                     l:=w;
                    end;
                 end;
             end;
         end;
      end;
      if (l = -1) Then begin
         l:=-2;
      end;
      A[X]:=l;
      valmin:=l;
   end;
         end else begin
             valmin:= A[X];
         end;
      end;
   end;

Begin
   readln(T);
      for K:=0 To (T - 1) do begin
      readln(E,F);//peso vacio-lleno
	  diferencia:=(F - E);
	  readln(N);//cantidad de monedas
      SeTlengTh(B,N); 
      SeTlengTh(C,N); 
      SeTlengTh(A,(diferencia + 1));
      for I := 0 To diferencia do A[I]:=-1;
      for I := 0 To (N -1) do readln(B[I],C[I]); //valor - peso
      if (diferencia <> 0) Then begin
         if (valmin(diferencia,0,0,0,0,-1) = -2) Then begin
             wriTeln('This is impossible.');
         end else begin
             wriTeln('The minimum amount of money in the piggy-bank is ',A[diferencia],'.');
         end
      end else begin
         wriTeln('The minimum amount of money in the piggy-bank is 0.');
      end;
   end;
end.