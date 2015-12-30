program scuba;
type
   TP = array of array of longint;
   TK = array of array of array of longint;

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
mint: TK ;
B : array of byte;

function elev(z:longint;x:longint):longint;
begin
   elev:=1;
   if (x=0) then elev:=1
   else begin
      for I:=1 to x do elev:=(elev*z);
   end;
end;

function binari : longint;
var J:longint; counter:longint;
begin
   counter:=0;
   J:=0;
   repeat begin
      if (B[counter]=1) then begin
         J:=J+(elev(2,counter));
      end;
      counter:=counter+1;
   end until (counter=n);
   binari:=J;
end;

function min(o,h:longint) : longint;
var G:longint; L:longint; J:longint; bi:longint;
begin
   if ((o<=0)and(h<=0)) then min:=0
   else begin
writeln('4');
      bi:=binari;
writeln('5');
      if (mint[o+1700,h+1700,bi] <> 0) then min:=mint[o+1700,h+1700,bi]
      else begin
         G:=-1;
         L:=0;
         repeat begin
writeln('6',o,h);
             if (B[L]=1) then begin
                B[L]:=2;
writeln('9');
                J:=(tanks[L,2]+min((o-tanks[L,0]),(h-tanks[L,1])));
                if ((J<G)or(G=-1)) then
                    G:=J;
                B[L]:=1;
writeln('7');
             end;
             L:=(L+1);
         end until (L=n);
writeln('8');
         mint[o+1700,h+1700,bi]:=G;
         min:=G;
      end;
   end;
end;

begin
readln(c);
countermain:=0;
repeat begin
   readln(t,a);
   readln(n);
   Setlength(tanks,n,3); 
   Setlength(mint,(t+1701),(a+1701),(elev(2,n)+1));
   Setlength(B,(n+1)); 
   for I:=0 to (n-1) do B[I]:=1;
writeln('1');
   for I:=0 to (n-1) do readln(tanks[I,0],tanks[I,1],tanks[I,2]);
writeln('2');
   p:=min(t,a);
writeln('3');
   if (c>0) then begin
   writeln(p);
   end;
   countermain:=(countermain+1);
end until (countermain>=c);
end.