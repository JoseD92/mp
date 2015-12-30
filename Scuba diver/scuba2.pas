program scuba;
type
   TP = array of array of integer;

var
c:longint;
a:byte;
t:byte;
n:longint;
countermain:longint;
counter1:longint;
I:longint;
K:longint;
p:longint;
tanks: TP ;
B : array of byte;

function min(o,h:longint) : longint;
var G:longint; L:longint; J:longint;
begin
   if ((o<=0)and(h<=0)) then min:=0
   else begin
         G:=-1;
         L:=0;
         repeat begin
             if (B[L]=1) then begin
                B[L]:=2;
                J:=(tanks[L,2]+min((o-tanks[L,0]),(h-tanks[L,1])));
                if ((J<G)or(G=-1)) then
                    G:=J;
                B[L]:=1;
             end;
             L:=(L+1);
         end until (L=n);
         min:=G;
   end;
end;

begin
readln(c);
countermain:=0;
repeat begin
   readln(t,a);
   readln(n);
   Setlength(tanks,n,3); 
   Setlength(B,n); 
   for I:=0 to (n-1) do B[I]:=1;
   for I:=0 to (n-1) do readln(tanks[I,0],tanks[I,1],tanks[I,2]);
   p:=min(t,a);
   if (c>0) then begin
   writeln(p);
   end;
   countermain:=(countermain+1);
end until (countermain>=c);
end.