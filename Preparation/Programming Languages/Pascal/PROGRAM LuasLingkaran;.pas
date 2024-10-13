PROGRAM LuasLingkaran;
{ Program membaca panjang jari-jari lingkaran dan menghitung luasnya }
{ Dikutip dari ALGORITMA DAN PEMROGRAMAN, halaman 87 }

{* DEKLARASI *}
uses crt;

const pi = 3.14;

var
    r : real; { jari-jari }
    L : real; { luas lingkaran }

{* ALGORITMA *}
begin
    readln (r);
    L := pi * r * r;
    writeln (L);
end.