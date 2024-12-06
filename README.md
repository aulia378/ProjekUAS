# ProjekUAS
ProjekUas Praktikum Pemrograman

Kelompok 5
Anggota:
1. Muhammad Isra' Aulia_2408107010006
2. Syakila Naira_2408107010034
3. Annisa Haura Dhiya_2408107010030
4. Rahmatul Uliya_2408107010012
5. Naila Hafizha_2408107010026
6. Jazil Nazvi Khalilullah_2408107010113

-> Cara Kerja pada Header.H

Program ini mencatat informasi alat laboratorium dalam bentuk daftar. Untuk setiap alat, disimpan data seperti:
ID alat: Nomor unik untuk setiap alat.
Nama alat: Misalnya, "Mikroskop".
Merek dan model: Informasi tambahan tentang alat.
Tahun produksi: Tahun pembuatan alat.
Jumlah unit: Berapa banyak alat tersedia di laboratorium.
Jumlah tersedia: Berapa banyak alat yang belum dipinjam.

lalu, ada dua jenis pengguna:

Admin: Bertugas mengelola alat.
User: Meminjam alat untuk keperluan mereka.
Setiap akun memiliki:

Username: Nama pengguna untuk login.
Password: Kata sandi untuk keamanan.
Role: Peran pengguna, apakah mereka admin atau user.
Contoh akun:
Username: "admin123", Password: "pass123", Role: "admin".

Setelah itu, ada data Peminjaman
Program mencatat siapa yang meminjam alat dan alat apa yang dipinjam. Untuk setiap peminjaman, disimpan:
ID alat yang dipinjam.
Username peminjam.

Apa Saja yang Bisa Dilakukan Program Ini?
Admin (Pengelola Laboratorium)
Admin memiliki banyak kemampuan, seperti:
-Menambahkan alat baru: Mengisi data alat ke dalam daftar.
-Menghapus alat: Jika alat sudah tidak digunakan.
-Mengedit alat: Misalnya, memperbarui jumlah unit yang tersedia.
-Melihat daftar alat: Menampilkan semua alat beserta informasi lengkapnya.
-Menyimpan data alat: Agar informasi alat tidak hilang saat program ditutup.

User (Pengguna Laboratorium)
User memiliki kemampuan, seperti:
-Melihat daftar alat: Mengecek alat apa saja yang tersedia di laboratorium.
-Meminjam alat: Jika tersedia, user bisa meminjam alat tertentu.
-Mengembalikan alat: Setelah selesai, user bisa mengembalikan alat yang dipinjam.
-Melihat riwayat peminjaman: User bisa melihat alat apa saja yang pernah dipinjam.

Cara Kerja Program
Login: User atau admin login ke sistem dengan username dan password.
Menu Utama:
Jika admin, akan ditampilkan menu pengelolaan alat.
Jika user, akan ditampilkan menu peminjaman dan pengembalian alat.
Penyimpanan Data:
Semua data (alat, akun, dan peminjaman) disimpan ke file, sehingga tidak hilang meskipun program dimatikan.

-> Cara Kerja Fungsi Login
Fungsi Login: Memastikan hanya pengguna yang terdaftar (admin atau user) yang bisa masuk ke sistem.
Lalu Mencari File Data Akun.
Login: Memastikan hanya pengguna yang terdaftar (admin atau user) yang bisa masuk ke sistem.
Program mencoba membuka file akun.txt.
Programnya Membaca dan Mencocokkan:
Program membaca satu per satu data dari file.
Program memeriksa apakah username dan password yang dimasukkan cocok dengan data di file.
Jika ditemukan akun yang sesuai, peran pengguna (role) (misalnya: admin atau user) disalin ke variabel role.
Jika login berhasil: Pengguna akan melanjutkan ke menu sesuai perannya.
Jika login gagal: Pengguna akan diminta mencoba lagi.

-> Cara Kerja Admin Menu
Fungsi ini adalah menu utama untuk admin, memungkinkan admin melakukan beberapa tugas pengelolaan alat laboratorium, seperti:
1.Menambah alat baru.
2.Menghapus alat berdasarkan ID-nya.
3.Mengedit data alat.
4.Keluar dari menu admin.

Lalu, Cara Kerjanya
Admin diminta memasukkan pilihan (1, 2, 3, atau 4).
Pilihan 1 (Tambah Alat):
Memanggil fungsi tambahAlat untuk menambahkan alat baru ke daftar.
Pilihan 2 (Hapus Alat):
Admin memasukkan ID alat yang ingin dihapus.
Fungsi hapusAlat akan menghapus alat tersebut dari daftar.
Perubahan langsung disimpan ke file menggunakan fungsi SimpanAlat.
Pilihan 3 (Edit Alat):
Admin memasukkan ID alat yang ingin diedit.
Fungsi editAlat akan digunakan untuk memperbarui informasi alat.
Perubahan langsung disimpan ke file menggunakan fungsi SimpanAlat.
Pilihan 4 (Keluar):
Admin keluar dari menu.
Lalu, Jika admin memasukkan pilihan yang tidak valid maka admin diminta memilih kembali sampai memasukkan angka yang benar.
Perulangan Menu:
Menu akan terus ditampilkan sampai admin memilih Keluar (Pilihan 4).

-> cara kerja tambah alat:
1.Menampilkan Prompt untuk Data Baru
Program memulai dengan menampilkan pesan Masukkan data alat baru: untuk memberi tahu pengguna bahwa mereka akan memasukkan data alat baru.
2.Auto Increment ID
ID alat baru ditentukan secara otomatis dengan menambahkan 1 ke jumlah alat saat ini.
3. Memasukkan Data Alat
Nama alat: Pengguna diminta memasukkan nama alat melalui fungsi scanf. Input disimpan di field nama dari elemen array ke-*jumlahAlat.
Merek alat: Serupa dengan nama, merek alat dimasukkan dan disimpan di field merek.
Model alat: Pengguna memasukkan model alat yang akan disimpan di field model.
Tahun produksi: Pengguna memasukkan tahun produksi alat, yang disimpan di field tahunProduksi.
Jumlah unit: Pengguna memasukkan jumlah unit alat yang dimiliki, disimpan di field jumlahUnit.
4.Menentukan Jumlah Tersedia
Field jumlahTersedia diatur sama dengan jumlahUnit, karena awalnya semua unit diasumsikan tersedia.
5.Menambahkan Counter Alat
Variabel *jumlahAlat dinaikkan (increment) untuk mencatat bahwa satu alat baru telah ditambahkan
6.Fungsi saveAlat dipanggil untuk menyimpan data alat baru ke dalam file (alat.txt).
7.Memberikan Konfirmasi
Pesan Alat berhasil ditambahkan. ditampilkan kepada pengguna sebagai konfirmasi.

-> cara kerja simpan alat (savealat):
1.Membuka File
-Fungsi fopen digunakan untuk membuka file alat.txt dalam mode penulisan ("w")
-Mode "w" akan membuat file baru jika file tidak ada, atau menghapus isi file lama sebelum menulis data baru.
2.Menulis Data ke File
- Fungsi fprintf digunakan untuk menulis data alat dari array ke dalam file dalam format yang terstruktur
- Data yang ditulis meliputi:
1.ID alat (%u): ID unik dari alat.
2.Nama alat (%s): Nama alat.
3.Merek alat (%s): Merek alat.
4.Model alat (%s): Model alat.
5.Tahun produksi (%u): Tahun alat diproduksi.
6.Jumlah unit (%u): Total jumlah unit alat.
7.Jumlah tersedia (%u): Unit yang tersedia saat ini.
- Setiap baris di dalam file merepresentasikan satu alat.
- Proses ini diulangi untuk setiap alat dalam array menggunakan perulangan for
3.Menutup File
- Setelah semua data selesai ditulis, fungsi fclose digunakan untuk menutup file.
- Menutup file memastikan data yang telah ditulis benar-benar disimpan ke disk dan menghindari kebocoran sumber daya.

-> cara kerja hapus alat:
Loop mencari alat berdasarkan ID.
Jika ditemukan:
Elemen array alat tersebut digeser ke kiri.
Jumlah alat dikurangi.
Tampilkan pesan berhasil.
Jika tidak ditemukan:
Tampilkan pesan alat tidak ditemukan.
Fungsi ini bekerja langsung pada array yang diberikan (menggunakan pointer) sehingga mengubah data asli tanpa perlu mengembalikan nilai

-> cara kerja fungsi edit alat
1. Mencari Alat
Variabel found: Variabel ini digunakan sebagai  untuk menandai apakah alat yang ingin diedit sudah ditemukan atau belum. Awalnya, nilai found diinisialisasi menjadi 0 (belum ditemukan).
Loop for: Loop ini akan mengiterasi setiap elemen dalam array alat untuk mencari alat dengan ID yang sesuai.
Perbandingan ID: Di dalam loop, ID alat yang sedang diperiksa dibandingkan dengan nilai id yang diberikan sebagai parameter. Jika kedua ID sama, maka alat tersebut telah ditemukan.

2. Menampilkan Informasi Alat
Jika Alat Ditemukan: Setelah alat ditemukan, informasi lengkap tentang alat tersebut akan ditampilkan ke pengguna. Hal ini berguna untuk memverifikasi bahwa pengguna sedang mengedit alat yang benar.

3. Memilih Data yang Ingin Diedit
Menu Pilihan: Pengguna diberikan beberapa pilihan untuk menentukan data mana yang ingin diedit mulai dari nama, merek, model, tahun produksi, jumlah unit serta  jumlah tersedia . Pilihan pengguna akan disimpan dalam variabel choice.

4. Mengubah Data Alat
switch-case: Berdasarkan nilai choice yang dipilih pengguna, program akan menjalankan blok kode yang sesuai.
Case 1 (edit nama) : Memperbaharui nama alat
Case 2 (edit merek) : Memperbaharui merek alat 
Case 3 (edit model) : Memperbarui model alat.
Case 4 ( edit tahun produksi) : Memperbarui tahun produksi 
Case 5 (edit jumlah unit ) : Memperbarui jumlah unit sekaligus Mengupdate jumlah tersedia .
Case 6 (edit jumlah tersedia) : Memperbarui jumlah tersedia.

5. Menampilkan Pesan Konfirmasi
Setelah Perubahan: Setelah data berhasil diubah, program akan menampilkan pesan konfirmasi kepada pengguna.

6. Menangani Kasus Alat Tidak Ditemukan
Jika Tidak Ditemukan: Jika setelah melakukan pencarian seluruh array, alat dengan ID yang diberikan tidak ditemukan, maka program akan menampilkan pesan kesalahan.

-> cara kerja fungsi user menu
1. Menampilkan Menu:
Fungsi ini akan menampilkan menu interaktif di layar, memberikan beberapa pilihan kepada pengguna.
Pilihan-pilihan yang tersedia adalah:
- Lihat Alat: Menampilkan daftar semua alat yang tersedia beserta detailnya.
- Pinjam Alat: Memungkinkan pengguna untuk memilih alat yang ingin dipinjam dan melakukan proses peminjaman.
- Lihat Pinjaman: Menampilkan riwayat peminjaman yang telah dilakukan oleh pengguna.
- Kembalikan Alat: Memungkinkan pengguna untuk mengembalikan alat yang telah dipinjam.
- Keluar: Mengakhiri sesi pengguna.

2. Menerima Input Pengguna:
Program akan meminta pengguna untuk memilih salah satu opsi dari menu yang ditampilkan.
Pilihan pengguna akan disimpan dalam variabel choice.

3. Memproses Pilihan Pengguna:
Menggunakan struktur switch-case, program akan mengevaluasi nilai choice dan menjalankan fungsi yang sesuai.
- Case 1 (Lihat Alat): Memanggil fungsi LihatAlat untuk menampilkan daftar alat.
- Case 2 (Pinjam Alat): Memanggil fungsi pinjamAlat untuk memproses permintaan peminjaman. Fungsi ini akan memeriksa ketersediaan alat, menambahkan data peminjaman ke dalam array pinjaman, dan mungkin juga mengurangi jumlah alat yang tersedia.
- Case 3 (Lihat Pinjaman): Memanggil fungsi lihatPinjaman untuk menampilkan daftar semua peminjaman yang telah dilakukan oleh pengguna saat ini.
- Case 4 (Kembalikan Alat): Memanggil fungsi kembalikanAlat untuk memproses pengembalian alat. Fungsi ini akan menghapus data peminjaman dari array pinjaman dan mungkin juga meningkatkan jumlah alat yang tersedia.
- case 5 : Keluar dari menu user.
- Default: Menampilkan pesan kesalahan jika pengguna memilih opsi yang tidak valid.

4. Mengulang Menu:
   Struktur do-while memastikan bahwa menu akan terus ditampilkan selama pengguna belum memilih opsi untuk keluar.
   
-> cara kerja fungsi lihat pinjaman:
1. Menampilkan Judul:
Fungsi ini akan mencetak judul yang menunjukkan daftar pinjaman untuk pengguna tertentu.

2. Melakukan Pencarian:
Fungsi ini akan melakukan dua kali perulangan bersarang:
- Perulangan pertama: Melakukan iterasi pada array pinjaman untuk mencari data peminjaman yang sesuai dengan username yang diberikan.
- Perulangan kedua: Jika ditemukan data peminjaman yang sesuai, fungsi ini akan mencari data alat yang sesuai dengan ID alat yang tercatat dalam data peminjaman.

3. Menampilkan Hasil:
Jika ditemukan data peminjaman yang sesuai, fungsi ini akan menampilkan detail alat yang dipinjam, termasuk ID alat, nama alat, merek, model, tahun produksi, dan jumlah yang tersedia.
Jika tidak ditemukan data peminjaman untuk pengguna tersebut, akan ditampilkan pesan bahwa tidak ada pinjaman yang ditemukan.

-> cara kerja fungsi muat akun:
1.	Membuka File : Fungsi ini dimulai dengan mencoba membuka file bernama "akun.txt" dalam mode baca ( "r"). Jika file tidak ditemukan, program akan menampilkan pesan kesalahan dan keluar dari program menggunakan exit(1).	
2. 	Inisialisasi Jumlah Akun : Variabel jumlahAkundiinisialisasi dengan nilai 0. Ini digunakan untuk menghitung jumlah akun yang berhasil dibaca dari file.
3.	Membaca Data Akun : Fungsi menggunakan loop whileuntuk membaca data dari file. Dengan menggunakan fscanf, fungsi ini membaca tiga string (username, password, dan role) untuk setiap akun yang ada di file. Data ini disimpan dalam struktur array Akunyang diberikan sebagai parameter.
4. 	Menghitung Jumlah Akun : Setiap kali data akun berhasil dibaca, nilai jumlahAkunakan ditingkatkan satu. Ini dilakukan dengan menggunakan (*jumlahAkun)++, yang berarti nilai yang ditunjuk oleh jumlahAkunakan bertambah satu.
5. 	Menutup File : Setelah semua data akun dibaca, file ditutup dengan fclose(file)untuk membebaskan sumber daya yang digunakan oleh file

-> cara kerja fungsi muat alat:
1. Membuka File: Fungsi mencoba membuka file alat.txt dalam mode baca ("r").Jika file tidak dapat dibuka (misalnya, file tidak ada), program akan mencetak pesan kesalahan dan keluar dengan exit(1).
2. Inisialisasi Jumlah Alat: Variabel jumlahAlat diinisialisasi dengan 0. Ini digunakan untuk menghitung jumlah alat yang berhasil dibaca dari file.
3. Membaca Data Alat: Fungsi menggunakan fscanf dalam loop while untuk membaca data dari file. Format yang digunakan adalah:
•	%u untuk id, tahunProduksi, jumlahUnit, dan jumlahTersedia (tipe unsigned int).
•	%s untuk nama, merek, dan model (string).
Data yang dibaca disimpan dalam elemen array alat yang sesuai dengan indeks *jumlahAlat.
4. Menghitung Jumlah Alat: Setiap kali data alat berhasil dibaca, nilai jumlahAlat akan ditingkatkan satu dengan (*jumlahAlat)++.
5. Menutup File:Setelah selesai membaca semua data, file ditutup dengan fclose(file).
6. Pemeriksaan jumlah alat: setelah menutup file, fungsi memeriksa apakah jumlahAlat masih 0. Jika iya, maka program akan mencetak pesan
   bahwa tidak ada alat yang ditemukan dalam file.

-> cara kerja fungsi lihat alat:
1. Menampilkan Judul: Fungsi dimulai dengan mencetak judul "Daftar Alat Laboratorium:" untuk memberi tahu pengguna bahwa daftar alat akan ditampilkan.
2. Pemeriksaan Jumlah Alat: Fungsi memeriksa apakah jumlahAlat sama dengan 0. Jika iya, maka akan mencetak pesan "Tidak ada alat yang tersedia." untuk memberi tahu pengguna bahwa tidak ada alat yang dapat ditampilkan.
3. Menampilkan Daftar Alat: Jika ada alat yang tersedia (jumlahAlat > 0), fungsi akan menggunakan loop for untuk iterasi melalui setiap alat dalam array alat.

-> cara kerja fungsi pinjam alat:
Fungsi ini digunakan untuk meminjam alat dengan ID tertentu.
- Pertama-tama fungsi ini akan memeriksa apakah alat dengan ID yang diberikan (id) ada dalam daftar alat (alat[]).
- Jika ID alat ditemukan, kemudian diperiksa apakah jumlah alat yang tersedia lebih besar dari 0 (alat[i].jumlahTersedia > 0). Jika alat tersedia, maka akan dilakukan proses peminjaman jumlah alat yang tersedia dengan dikurangi satu (alat[i].jumlahTersedia--).
- Informasi peminjaman akan ditambahkan ke dalam array pinjaman[], termasuk idAlat dan username yang meminjam alat tersebut.
- Jumlah pinjaman yang tercatat juga akan bertambah ((*jumlahPinjaman)++).
- Setelah peminjaman berhasil, fungsi SimpanPinjaman akan dipanggil untuk menyimpan data pinjaman ke dalam file pinjaman.txt.
- Fungsi akan memberi feedback ke pengguna apakah peminjaman berhasil atau tidak, dan program akan berakhir. Akan tetapi, jika Alat Tidak Tersedia, maka akan ditampilkan "Alat tidak tersedia untuk dipinjam." dan program akan berakhir.
-Jika ID alat tidak ditemukan dalam daftar alat, maka akan ditampilkan  "Alat dengan ID ... tidak ditemukan."

-> cara kerja fungsi data pinjaman:
Fungsi ini digunakan untuk memuat (membaca) data pinjaman dari file pinjaman.txt ke dalam array pinjaman[].
- Fungsi ini akan membuka file pinjaman.txt dibuka dalam mode 'r' (read/baca).
- Jika file gagal dibuka, maka pesan kesalahan akan ditampilkan dan program akan berhenti.
- Jika file berhasil dibuka, maka fungsi selanjutnya digunakan untuk membaca ID alat dan nama pengguna dari file.
- Pembacaan berlanjut hingga mencapai EOF (end of file/akhir dari file).
- Kemudian setiap kali data baru dibaca, ((*jumlahPinjaman)++) menambahkan jumlah pinjaman yang tercatat.
- Setelah selesai membaca, file ditutup dengan fclose(file).

-> cara kerja fungsi simpan pinjaman:
  Fungsi ini digunakan untuk menyimpan data pinjaman ke dalam file pinjaman.txt.
  - Pertama-tama file pinjaman.txt dibuka dengan mode 'w' (write/tulis).
  - Jika file gagal dibuka, pesan kesalahan akan ditampilkan dan program akan berhenti.
  - Kemudian fungsi ini akan menulis setiap pinjaman ke dalam file menggunakan fprintf(file, "%d %s\n", pinjaman[i].idAlat,     
    pinjaman[i].username).
  - Data yang ditulis adalah ID alat yang dipinjam dan nama pengguna yang meminjam, dan setiap entri dipisahkan oleh baris baru (\n).
  - Setelah selesai menulis, file ditutup dengan fclose(file).

-> cara kerja fungsi kembalikan alat:
1. Mencari Data Peminjaman:
Fungsi akan melakukan perulangan untuk memeriksa setiap data peminjaman.
Data peminjaman yang dicari harus memenuhi dua kondisi:
- ID alat pada data peminjaman harus sama dengan id yang diberikan.
- Username pada data peminjaman harus sama dengan username yang diberikan.
Jika ditemukan data peminjaman yang sesuai, proses penghapusan akan dilakukan.

2. Menghapus Data Peminjaman:
- Geser data: Ketika data yang ingin dihapus ditemukan, data-data di belakangnya akan digeser ke depan satu indeks. Hal ini dilakukan 
  dengan perulangan for yang dimulai dari indeks data yang akan dihapus hingga indeks sebelum elemen terakhir.
- Kurangi jumlah peminjaman: Nilai *jumlahPinjaman dikurangi 1 untuk menunjukkan bahwa jumlah data peminjaman telah berkurang.
- Beri pesan sukses: Sistem akan menampilkan pesan "Pengembalian alat berhasil."

3. Tidak Ditemukan:
Jika setelah melakukan pencarian tidak ditemukan data peminjaman yang sesuai, sistem akan menampilkan pesan "Peminjaman tidak ditemukan atau ID tidak cocok."


-> kegunaan program main.c
kagunaan program sistem peminjaman alat laboratorium:
- proses peminjaman dan pengembalian alat lab menjadi lebih cepat dan mudah.
- Data tentang alat dan peminjaman alat lab selalu terupdate dan akurat.
- Sistem dapat mencatat riwayat pengunaan alat lab, sehingga jika terjadi kerusakan, dapat diketahui siapa pengguna terakhirnya. 
- Pengguna dalat melihat secara real time ketersediaan alat lab yang ingin dipinjam.
- Dengan adanya sistem peminjaman alat lab, setiap alat yang dipinjam akan tercatat sehingga memudahkan dalam melacak keberadaan alat.

-> Cara Kerja Main.c
Program ini adalah sistem manajemen laboratorium yang memungkinkan pengguna untuk login dan mengakses menu sesuai peran mereka:
Admin: Bisa mengelola data alat (menambah, menghapus, mengedit alat).
User: Bisa meminjam alat dan melihat daftar alat.
Program membutuhkan username dan password yang dimasukkan langsung saat menjalankan program melalui terminal atau command line.
Di sini:
admin123 adalah username.
pass123 adalah password.
Program menggunakan fungsi login untuk memeriksa apakah username dan password cocok dengan data dalam file akun.txt.
Jika login berhasil:
Admin atau User akan diarahkan ke menu masing-masing.
Jika login gagal maka outputnya menjadi ''Login gagal. Silakan coba lagi.''
Setelah login berhasil, program memuat data alat laboratorium dari file menggunakan fungsi MuatAlat. Ini memastikan admin atau user dapat mengakses data terkini.

=> Jika pengguna adalah admin:
Program akan menampilkan menu admin menggunakan fungsi adminMenu.
Admin dapat:
1.Menambah alat baru.
2.Menghapus alat berdasarkan ID-nya.
3.Mengedit data alat.

=> Jika pengguna adalah user:
Program akan menampilkan menu user menggunakan fungsi userMenu.
User dapat:
1.Melihat daftar alat.
2.Meminjam alat.
3.Mengembalikan alat.
4.Melihat riwayat peminjaman.



=> kegunaan program kosa kata.c
program ini bertujuan untuk menyusun sebuah kosa kata dari sebuh teks yang terdapat dalam file input (dalam hal ini ada lirik lagu bahasa inggris) dengan adanya program ini memudahkan user untuk melihat kata demi kata yang telah dipisahkan ke dalam sebuh file output dengan format tertentu serta tidak ada kosa kata yan sama dicetak berulang kali.

-> cara kerja kosa-kata.c
1. Header
Header <studio.h> adalah salah satu header file standar dalam bahasa pemrograman C yang menyediakan fungsi-fungsi untuk melakukan input dan output (I/O).
Header <stdlib.h> adalah salah satu header file standar dalam bahasa pemrograman C yang menyediakan berbagai fungsi untuk melakukan operasi umum, seperti pengelolaan memori, konversi tipe data, dan kontrol program. 
Header <string.h> adalah header file standar dalam bahasa pemrograman C yang menyediakan fungsi-fungsi untuk memanipulasi string (array karakter) dan operasi terkait. 
Header <cytype.h> adalah header file standar dalam bahasa pemrograman C yang menyediakan fungsi-fungsi untuk menguji dan mengonversi karakter.

2. Define 
Disini terdapat dua define atau pendefinisian :
•	Define MAX_WORD 1000 menandakan kita akan membatasi hanya ada 1000 kata untuk array dalam program
•	Define MAX_WORD_LEGHT menandakan kita akan membatasi panjang sebuah kata denagn nilai 100

3. Fungsi mengubah string menjadi huruf kecil
Fungsi ini menggunakan perulangan for dimana setiap karakter akan diperiksa satu persatu dan mengubahnya menjadi huruf kecil  hingga akhir dari string
	
4. Fungsi Untuk Menghapus tanda baca dari kata 
Fungsi ini menggunakan perulangan for untuk mememriksa apakah karakter tersebut adalah huruf atau bukan, jika karakter tersebut adalah huruf maka akan dimasukkan kedalam variabel word dan terus memeriksa hingga akhir string. Namun jika ada karakter yang bukan huruf maka kita akan memastikan karakter tersebut yg dikecualikan dengan cara jika karakter tersebut adalah tanda penghubung, apostrof, dan titik (-,’,.) dan huruf setelahnya adalah sebuah huruf maka karakter tersebut akan dimasukkan juga kedalam variabel word.

5. Fungsi Utama
•	Membuka file “lirik.txt” untuk dibaca, jika file tidak ada maka akan keluar peringatan eror
•	Membaca judul dari file, if disisni mencoba untuk membaca satu baris dari file yg sudah dibuka sebelumnya (lirik.txt), “fgets” digunakan untuk membaca teks dari file dan akan menyimpan baris yang dibaca ke dalam variabel line, “sizeof(line)” memberi tau fungsi “fgets” sberapa banyak ruang yang tersedia dalam variable line untuk menyimpan teks, jika tidak ada lagi baris yang bisa dibaca maka akan mengembalikan NULL
•	Membuka file output (kosa_kata.word) untuk ditulis, jika terjadi kesalahan saat membuka file maka akan keluar peringatan eror dan langsung menutup file itu, namun jika file berhasil dibuka maka isi dari variable line akan di print ke fli output tersebut
•	Membaca setiap baris lirik, while disini mencoba untuk membaca satu baris dari file yg sudah dibuka sebelumnya (lirik.txt), “fgets” digunakan untuk membaca teks dari file dan akan menyimpan baris yang dibaca ke dalam variabel line, “sizeof(line)” memberi tau fungsi “fgets” sberapa banyak ruang yang tersedia dalam variable line untuk menyimpan teks, jika tidak ada lagi baris yang bisa dibaca maka akan mengembalikan NULL, lalu string didalam variable line dipecah menjadi per kata menggunakan fungsi “strtok” dengan spasi dan new line sebagai penandanya dan kata yang sudah terpecah disimpan dalam variabel kata 
•	Memeriksa apakah di dalam variabel kata ada isinya, jika iya maka string di dalam variabel kata akan di copy ke dalam variabel cleanedWord, lalu seluruh string di didalam cleanedWord ini akan menjalankan fungsi mengecilkan seluruh karakter dan memastikan karakter tersebut adalah sebuah huruf dan tanda baca yang dikecualikan.
•	Memeriksa apakah kata sudah ada dalam daftar, perulangan for digunakan untuk memeriksa perkata apakah kata di dalam variabel cleanedWord ada di dalam variabel words, jika sudah ada maka kata tersebut tidak dieksekusi lagi, fungsi ini digunakan untuk mencegah mencetak kata kata yang sama dua kali, namun jka kata tersebut belum berada di dalam variabel words maka akan di tambahkan kedalam daftar dengan syarat jika kata tersebut tidak kosong
•	Memindahkan seluruh isi variabel cleanedWord kedalam variabel baru (words) dengan mengalokasikan memori cleanedWord untuk variable words lalu ditambah satu untuk menyimpan \n di baris terakhir
•	Menuliskan kosa kata ke file output, for disini berguna untuk memindahkan kata satu persatu ke dalam kosa_kata.word ditambahkan sama dengan (=) dan new line setelah setiap kata, setelah semua kata sudah diprint ke dalam file output maka kita membebaskan memori  yang telah dialokasikan sebelumnya untuk menyimpan string yang ada di dalam array words menggunakan fungsi ”‘free”
•	Menutup seluruh file yg sudah dibuka (output dan input file) menggunakan fungsi fclose
•	Mencetak kata “kosa kata telah berhasi ditulis ke kosa-kata.word
•	Mengembalikan nilai nol sebagai tanda bahwa program berhasil dijalankan


