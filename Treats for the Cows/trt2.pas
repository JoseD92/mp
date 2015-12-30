program trt;
type
   TP = array of array of real ;
var
   k : array of longint ;
   N : longint ;
   I : longint ;
   total : real ;
   t : TP ;

function max(a,b,c:longint;d,e:real) : real;
begin
   c:=(c+1);
   if (t[a,b]=0) then begin
   If (a=b) then begin max:=(k[a]*c); end
   else begin
      d:=((k[a])*c + max((a+1),b,c,0,0));
      e:=((k[b])*c + max(a,(b-1),c,0,0));
      if (e>=d) then begin max:=e; t[a,b]:=e; end
      else begin max:=d; t[a,b]:=d; end;
   end;
   end else begin
      max:=t[a,b];
   end;
end;

Begin
   readln(N);
   Setlength(k,N); 
   Setlength(t,N,N);
   for I := 0 to (N-1) do readln(k[I]);
   total:=(max(0,(N-1),0,0,0));
   writeln(total:1:0);
end.