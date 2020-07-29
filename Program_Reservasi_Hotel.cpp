#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

struct Simulasi{
	int tgl;
	int bln;
	int thn;
} In, Out;

struct Date{
	int d, m, y;
};


const int hari_dalam_bulan[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


void setcolor(unsigned short color);
void tampil_menu(int jenis, string judul);
void sukses_ubah_tarif(string jenis_kamar, float tarif_seb, float tarif_ses);
void tampil_jenis_kamar(float a, float b, float c, float d);
float harga_kamar(string kode, float a, float b, float c, float d, float *harga);
void total_biaya_kamar(Simulasi In, Simulasi Out, float harga_kamar, string kode_kamar);
void cek_kamar_tersedia(string nama_kamar[], string kamar[]);

int main()
{

	int waktu_sewa[3][2] = {};
	string pilih_kode_kamar_simulasi;
	float harga_kamar_tmp;;

	int pilih_menu_utama, pilih_menu_1, pilih_menu_2, pilih_menu_4;
	string pilih_kode_kamar;

	int tanggal, bulan, tahun;

	string semua_kamar_nama[4] = {"Premiere Room", "Deluxe Room", "Junior Suite", "Techo Suite"};
	string semua_kamar[4];
	semua_kamar[0] = "-";
	semua_kamar[1] = "-";
	semua_kamar[2] = "-";
	semua_kamar[3] = "-";

	int pilih_kamar_tersedia, hitung_kamar_tersedia, hitung_kamar_terisi, pilih_cek_out;
	string tampung_nama;

	float trf_premiere = 190.36, trf_deluxe = 366.66, trf_junior = 573.21, trf_techno = 684.44;
	float in_trf_premiere, in_trf_deluxe, in_trf_junior, in_trf_techno, tampung_tarif_sblm_diubah;
	bool cek_ubah_p = false, cek_ubah_d = false, cek_ubah_j = false, cek_ubah_t = false;

	do
        {
		in_trf_premiere = (cek_ubah_p == false) ? trf_premiere : in_trf_premiere;
		in_trf_deluxe 	= (cek_ubah_d == false) ? trf_deluxe : in_trf_deluxe;
		in_trf_junior 	= (cek_ubah_j == false) ? trf_junior : in_trf_junior;
		in_trf_techno 	= (cek_ubah_t == false) ? trf_techno : in_trf_techno;

		system("cls");
		tampil_menu(1, "\t\t  MENU UTAMA");
		setcolor(2);
		cout<<"1. Kelola Tarif Kamar Berdasar Jenis Kamar."<<endl;
		setcolor(2);
		cout<<"2. Simulasi Hitung Total Biaya."<<endl;
		setcolor(2);
		cout<<"3. Keluar Sistem."<<endl;
		setcolor(2);
		cout<<"4. Kelola Status Kamar."<<endl;
		setcolor(7);
		cout<<"Pilih menu (1-4) : ";cin>>pilih_menu_utama;

		switch(pilih_menu_utama)
		{
			case 1:
				do
				{
					system("cls");
					tampil_menu(1, "    Kelola Tarif Kamar Berdasar Jenis Kamar");
					setcolor(2);
					cout<<"1. Tampil Semua Tarif Kamar."<<endl;
					setcolor(4);
					cout<<"2. Ubah Tarif Kamar."<<endl;
					setcolor(1);
					cout<<"3. Kembali ke Menu Sebelumnya."<<endl;
					setcolor(7);
					cout<<"Pilih menu (1-3) : ";cin>>pilih_menu_1;

					switch(pilih_menu_1)
					{
						case 1:
							system("cls");
							tampil_menu(2, "\t\t  TARIF KAMAR");
							cout<<"    Jenis    "<<"       "<<"   Tarif/malam (USD)   "<<endl;
							cout<<"------------------------------------------------"<<endl;
							cout<<"Premiere Room"<<"       "<<in_trf_premiere<<endl;
							cout<<"Deluxe Room  "<<"       "<<in_trf_deluxe<<endl;
							cout<<"Junior Suite "<<"       "<<in_trf_junior<<endl;
							cout<<"Techno Suite "<<"       "<<in_trf_techno<<endl;
							cout<<"------------------------------------------------"<<endl;
							system("pause");
							break;

						case 2:
							system("cls");
							tampil_menu(2, "\t\tUBAH TARIF KAMAR");
							tampil_jenis_kamar(in_trf_premiere, in_trf_deluxe, in_trf_junior, in_trf_techno);
							cout<<"Masukkan kode kamar yang ingin diubah : ";cin>>pilih_kode_kamar;
							cout<<endl;

							if(pilih_kode_kamar == "K001")
                                {

								cout<<"Jenis kamar    : Premiere Room"<<endl;
								cout<<"Tarif sekarang : "<<in_trf_premiere<<endl<<endl;
								tampung_tarif_sblm_diubah = in_trf_premiere;
								cout<<"Masukkan tarif baru untuk -Premiere Room- : ";cin>>in_trf_premiere;
								cek_ubah_p = true;
								sukses_ubah_tarif("Premiere Room", tampung_tarif_sblm_diubah, in_trf_premiere);

                                }
							else if(pilih_kode_kamar == "K002")
                                {

								cout<<"Jenis kamar    : Deluxe Room"<<endl;
								cout<<"Tarif sekarang : "<<in_trf_deluxe<<endl<<endl;
								tampung_tarif_sblm_diubah = in_trf_deluxe;
								cout<<"Masukkan tarif baru untuk -Deluxe Room- : ";cin>>in_trf_deluxe;
								cek_ubah_d = true;
								sukses_ubah_tarif("Deluxe Room", tampung_tarif_sblm_diubah, in_trf_deluxe);

                                }
							else if(pilih_kode_kamar == "K003")
                                {

								cout<<"Jenis kamar    : Junior Suite"<<endl;
								cout<<"Tarif sekarang : "<<in_trf_junior<<endl<<endl;
								tampung_tarif_sblm_diubah = in_trf_junior;
								cout<<"Masukkan tarif baru untuk -Junior Suite- : ";cin>>in_trf_junior;
								cek_ubah_j = true;
								sukses_ubah_tarif("Junior Suite", tampung_tarif_sblm_diubah, in_trf_junior);

                                }
							else if(pilih_kode_kamar == "K004")
                                {

								cout<<"Jenis kamar    : Techno Suite"<<endl;
								cout<<"Tarif sekarang : "<<in_trf_techno<<endl<<endl;
								tampung_tarif_sblm_diubah = in_trf_techno;
								cout<<"Masukkan tarif baru untuk -Techno Suite- : ";cin>>in_trf_techno;
								cek_ubah_t = true;
								sukses_ubah_tarif("Techno Suite", tampung_tarif_sblm_diubah, in_trf_techno);

                                }
                            else
                                {
                                setcolor(4);
								system("cls");
								cout<<"==========================="<<endl;
								cout<<"Jenis kamar tidak tersedia!"<<endl;
								cout<<"==========================="<<endl<<endl;
								system("pause");
                                }

							break;

						default:
							break;
					}

				} while(pilih_menu_1 != 3);

				break;

			case 2:
				do
                    {
					system("cls");
					tampil_menu(1, "\t  Simulasi Hitung Total Biaya");
					setcolor(2);
					cout<<"1. Mulai simulasi hitung total biaya"<<endl;
					setcolor(1);
					cout<<"2. Kembali ke menu sebelumya"<<endl;
					setcolor(7);
					cout<<"Pilih menu (1-2) : ";cin>>pilih_menu_2;

					switch(pilih_menu_2)
					{
						case 1:
							system("cls");
							tampil_menu(2, "\t      SIMULASI HITUNG BIAYA");
							cout<<"Tanggal Cek-in : ";cin>>In.tgl;
							cout<<"Bulan Cek-in   : ";cin>>In.bln;
							cout<<"Tahun Cek-in   : ";cin>>In.thn;
							cout<<endl;
							cout<<"Tanggal Cek-out : ";cin>>Out.tgl;
							cout<<"Bulan Cek-out   : ";cin>>Out.bln;
							cout<<"Thaun Cek-out   : ";cin>>Out.thn;
							cout<<endl;
							cout<<"------------------------------------------------"<<endl;
							tampil_jenis_kamar(in_trf_premiere, in_trf_deluxe, in_trf_junior, in_trf_techno);
							cout<<"Masukkan kode kamar : ";cin>>pilih_kode_kamar_simulasi;

							harga_kamar(pilih_kode_kamar_simulasi, in_trf_premiere, in_trf_deluxe, in_trf_junior, in_trf_techno, &harga_kamar_tmp);

							total_biaya_kamar(In, Out, harga_kamar_tmp, pilih_kode_kamar_simulasi);


							system("pause");
							break;
						default:
							break;
					}
				}
				while(pilih_menu_2 != 2);
				break;

			case 4:
				do
                    {
					system("cls");
					tampil_menu(1, "\t       Kelola Status Kamar");
					setcolor(6);
					cout<<"1. Cek-In."<<endl;
					setcolor(1);
					cout<<"2. Cek-Out."<<endl;
					setcolor(2);
					cout<<"3. Kembali ke menu sebelumnya."<<endl;
					setcolor(7);
					cout<<"Pilih menu (1/2/3) : ";cin>>pilih_menu_4;

					switch(pilih_menu_4){
						case 1:
							system("cls");
							tampil_menu(2, "\t     	     Cek-In");

							cout<<"Kamar Tersedia : "<<endl;
							cout<<"--------------------------"<<endl;
							cout<<"No. Kamar | Nama Kamar"<<endl;
							cout<<"--------------------------"<<endl;
							hitung_kamar_tersedia = 0;
							for(int i = 0;i <= 3;i++){
								if(semua_kamar[i] == "-"){
									cout<<"    "<<i+1<<"       "<<semua_kamar_nama[i]<<endl;
									hitung_kamar_tersedia++;
								}
							}
							cout<<"---------------------------"<<endl;
							cout<<"Pilih nomor kamar : ";cin>>pilih_kamar_tersedia;
							cout<<"Masukan Nama : ";cin>>tampung_nama;


							if(pilih_kamar_tersedia > 0 && pilih_kamar_tersedia < 5){
								if(semua_kamar[pilih_kamar_tersedia-1] == "-"){
									semua_kamar[pilih_kamar_tersedia-1] = tampung_nama;

									system("cls");
									cout<<"----------------------"<<endl;
									cout<<"Proses Cek-In Berhasil"<<endl;
									cout<<"----------------------"<<endl;
									cout<<"Nama  : "<<tampung_nama<<endl;
									cout<<"Kamar : "<<semua_kamar_nama[pilih_kamar_tersedia-1]<<endl<<endl;
								} else {
									system("cls");
									cout<<"-------------------"<<endl;
									cout<<"Proses Cek-In GAGAL"<<endl;
									cout<<"-------------------"<<endl;
									cout<<"Kamar sudah terisi!"<<endl<<endl;
								}
							} else {
								cout<<"Kamar tidak tersedia!"<<endl<<endl;
							}

							system("pause");
							break;
						case 2:
							system("cls");
							tampil_menu(2, "\t     	     Cek-Out");

							cout<<"Kamar Terisi : "<<endl;
							cout<<"--------------------------------------"<<endl;
							cout<<"No. Kamar | Nama Kamar     | Nama Tamu"<<endl;
							cout<<"--------------------------------------"<<endl;
							hitung_kamar_terisi = 0;
							for(int i = 0;i <= 3;i++){
								if(semua_kamar[i] != "-"){
									cout<<setw(5)<<i+1<<setw(18)<<semua_kamar_nama[i]<<setw(10)<<semua_kamar[i]<<endl;
									hitung_kamar_terisi++;
								}
							}
							cout<<"--------------------------------------"<<endl;
							if(hitung_kamar_terisi != 0){
								cout<<"Pilih nomor kamar untuk Cek-Out : ";cin>>pilih_cek_out;
								if(pilih_cek_out > 0 && pilih_cek_out < 5){
									semua_kamar[pilih_cek_out-1] = "-";
									system("cls");
									cout<<"-----------------------"<<endl;
									cout<<"Proses Cek-Out Berhasil"<<endl;
									cout<<"-----------------------"<<endl;
								} else {
									cout<<"Nomor kamar salah!"<<endl<<endl;
								}
							} else {
								cout<<"Semua kamar Masih Kosong!"<<endl<<endl;
							}


							system("pause");
							break;
						default:
							break;
					}

				}while(pilih_menu_4 != 3);
				break;

			default:
				break;
		}

	} while(pilih_menu_utama != 3);
}

int hitung_tahun_kabisat(Date d)
{
	int tahun = d.y;

	if (d.m <= 2) {
		tahun--;
	}

	return tahun / 4 - tahun / 100 + tahun / 400;
}

int ambil_beda(Date dt1, Date dt2) {

	long int n1 = dt1.y*365 + dt1.d;

	for (int i=0; i<dt1.m - 1; i++) {
		n1 += hari_dalam_bulan[i];
	}
	n1 += hitung_tahun_kabisat(dt1);

	long int n2 = dt2.y*365 + dt2.d;

	for (int i=0; i<dt2.m - 1; i++) {
		n2 += hari_dalam_bulan[i];
	}
	n2 += hitung_tahun_kabisat(dt2);

	return (n2 - n1);
}

void total_biaya_kamar(Simulasi In, Simulasi Out, float harga_kamar, string kode){
	Date dt1 = {In.tgl, In.bln, In.thn};
	Date dt2 = {Out.tgl, Out.bln, Out.thn};
	int ambil_beda_ = ambil_beda(dt1, dt2);
	float total_harga = ambil_beda_ * harga_kamar;
	string nama_kamar;

	if(kode == "K001"){
		nama_kamar = "Premiere Room";
	} else if(kode == "K002"){
		nama_kamar = "Deluxe Room";
	} else if(kode == "K003"){
		nama_kamar = "Junior Suite";
	} else if(kode == "K004"){
		nama_kamar = "Techno Suite";
	}

	system("CLS");
	cout<<"----------------------------------------------"<<endl;
	cout<<"== Berhasil Menghitung Simulasi Total Biaya =="<<endl;
	cout<<"----------------------------------------------"<<endl;
	cout<<"Jenis Kamar     : "<<nama_kamar<<endl;
	cout<<"Harga Kamar     : "<<harga_kamar<<endl;
	cout<<"Tanggal Cek-In  : "<<In.tgl<<"/"<<In.bln<<"/"<<In.thn<<endl;
	cout<<"Tanggal Cek-Out : "<<Out.tgl<<"/"<<Out.bln<<"/"<<Out.thn<<endl;
	cout<<"Lama Menginap   : "<<ambil_beda_<<" Malam"<<endl;
	cout<<"----------------------------------------------"<<endl;
	cout<<"Total Biaya     : "<<total_harga<<endl<<endl;


}

void cek_kamar_tersedia(string nama_kamar[], string kamar[]){
	for(int i = 0;i <= 3;i++){
		if(kamar[i] == "-"){
			cout<<i+1<<". "<<nama_kamar[i]<<endl;
		}
	}

}

float harga_kamar(string kode, float a, float b, float c, float d, float *harga){
	if(kode == "K001"){
		*harga = a;
	} else if(kode == "K002"){
		*harga = b;
	} else if(kode == "K003"){
		*harga = c;
	} else if(kode == "K004"){
		*harga = d;
	} else {
		*harga = 0.0;
	}
}

void sukses_ubah_tarif(string jenis_kamar, float tarif_seb, float tarif_ses){
	system("cls");
	cout<<"==========================="<<endl;
	cout<<"Tarif Kamar berhasil diubah"<<endl;
	cout<<"==========================="<<endl;
	cout<<"Jenis Kamar   : "<<jenis_kamar<<endl;
	cout<<"Tarif Sebelum : "<<tarif_seb<<endl;
	cout<<"Tarif Sesudah : "<<tarif_ses<<endl<<endl;
	system("pause");
}

void tampil_menu(int jenis, string judul){
	if(jenis == 1)
        {
        setcolor(3);
		cout<<"================================================================="<<endl;
		cout<<"                   SYARIF SODEN                                  "<<endl;
		cout<<"   BELAJAR C++ UNTUK PEMULA : HTTPS://SYARIFSODEN.BLOGSPOT.COM   "<<endl;
		cout<<"================================================================="<<endl;
		cout<<judul<<endl;
		cout<<"------------------------------------------------"<<endl;
        }
	else
        {
		cout<<"================================================"<<endl;
		cout<<judul<<endl;
		cout<<"------------------------------------------------"<<endl;
        }
}

void tampil_jenis_kamar(float a, float b, float c, float d){
	cout<<"Kode"<<"   "<<"Jenis"<<"            "<<"Tarif/Malam"<<endl;
	cout<<"------------------------------------------------"<<endl;
	cout<<"K001"<<"   "<<"Premiere Room"<<"    "<<a<<endl;
	cout<<"K002"<<"   "<<"Deluxe Room  "<<"    "<<b<<endl;
	cout<<"K003"<<"   "<<"Junior Suite "<<"    "<<c<<endl;
	cout<<"K004"<<"   "<<"Techno Suite "<<"    "<<d<<endl;
	cout<<"------------------------------------------------"<<endl;
}

void setcolor(unsigned short color){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hCon,color);
}
