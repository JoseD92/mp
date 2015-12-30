program trt;
var
   comp1: longint ;
   comp2 : longint ;
   a : longint ;
   b : array of longint ;
   N : longint ;
   ganancia : real ;
   I : longint ;

procedure compar(c,d:longint);
begin
   if ( c <= d) then begin
      ganancia:=(ganancia + (a*c));
      comp1:=(comp1+1);
   end else begin
      ganancia:=(ganancia + (a*d));
      comp2:=(comp2-1);
   end;
end;

begin
   readln(N);
   ganancia:=0;
   Setlength(b,N); 
   a:=1;
   for I := 0 to (N-1) do readln(b[I]);
   comp1:=0;
   comp2:=(N-1);
   for I:= 0 to (N-1) do begin compar(B[comp1],B[comp2]); a:=(a+1); end;
   writeln(ganancia:1:0);
end.