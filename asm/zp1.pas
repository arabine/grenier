program zp1;

{$N+}
{$L zasmp1}

var

   Rayon, Surface, Perim:single;

procedure FONC1(Rayon:single;var Surface:single;var Perim:single);EXTERNAL;

begin
     writeln('Entrer rayon');
     readln(Rayon);
     FONC1(Rayon,Surface,Perim);
     writeln('Surface : ',Surface);
     writeln('Perimetre : ',Perim);
end
.