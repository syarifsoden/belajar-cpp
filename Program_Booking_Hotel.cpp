#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std;
main ()
{
                int kamar,a,a1,a2,harga,m,total,waktu,b;
atas:
cout<<"\t\thttps://.syarifsoden.blogspot.com"<<endl;
cout<<"\t\tProgram Booking Kamar Hotel"<<endl;
cout<<endl;
cout<<"\t\tMenu                                         : "<<endl;
cout<<"\t\t1. Kelola tarif kamar berdasarkan jenis kamar "<<endl;;
cout<<"\t\t2. Simulasi hitung total biaya                "<<endl;
cout<<"\t\t3. Keluar sistem                              "<<endl;
cout<<"\t\t   Masukkan Pilihan Menu (1-3)               : "; cin>>m;


if(m==1)
{
cout<<"\n\n\t\tMenu No 1";
cout<<"\n\t\t1. Tampil semua tarif kamar ";
cout<<"\n\t\t2. Ubah tarif kamar ";
cout<<"\n\t\t3. Kembali ke menu sebelumnya ";
cout<<"\n\t\tMasukkan Pilihan : ";cin>>a1;
}
 else if(a1==1)
{
cout<<"\n\t\t1. Premiere Room :  $190.36";
cout<<"\n\t\t2. Deluxe Room   :  $366.66";
cout<<"\n\t\t3. Junior Suite  :  $366.66";
cout<<"\n\t\t4. Techno Suite  :  $684.44";

}

else if(a1==2)
{
cout<<"\t\tUbah Tarif Kamar"<<b;
getch();
}
else if(a1==3)
{
goto atas;
}

if(a==2)
{
cout<<"\n\n\t\tMenu No 2";
cout<<"\n\t\t1. Mulai simulasi hitung total biaya ";;
cout<<"\n\t\t2. Kembali ke menu sebelumnya ";
cout<<"\n\t\tMasukkan Pilihan : ";cin>>a2;
}
else if(a2=1)
{
cout<<"\n\t\t1. Premiere Room :  $190.36";
cout<<"\n\t\t2. Deluxe Room   :  $366.66";
cout<<"\n\t\t3. Junior Suite  :  $366.66";
cout<<"\n\t\t4. Techno Suite  :  $684.44";
return 0;
getch();
}

else if(a2==2)
{
goto atas;
getch();
}

cout<<"\n\n\t\tSilahkan Pilih Tipe Kamar Yang Anda Inginkan";
cout<<"\n\t\t1. Premiere Room";
cout<<"\n\t\t2. Deluxe Room";
cout<<"\n\t\t3. Junior Suite";
cout<<"\n\t\t4. Techno Suite";
cout<<"\n\t\tMasukan Pilihan : ";cin>>kamar;

                if(kamar==1)
                {
                    cout<<"\n\t\tPremiere Room";
                    harga=190.36;
                }
                else if(kamar==2)
                {
                    cout<<"\n\t\tDeluxe Room";
                    harga=366.66;
                }
                else if(kamar==3)
                {
                    cout<<"\n\t\tJunior Suite";
                    harga=573.21;
                }
                else if(kamar==4)
                {
                    cout<<"\n\t\tATechno Suite";
                    harga=684.44;
                }
                cout<<endl;
                cout<<"\n\t\twaktu Menginap    : ";cin>>waktu;
                cout<<"\n\t\tHarga Perhari    : $. "<<harga;
                cout<<"\n\t\tHarga Kamar Total: $. "<<waktu*harga;

               return 0;

}
