# ProjekUAS
ProjekUas Praktikum Pemrograman

Kelompok 5
Anggota:
1.Muhammad Isra' Aulia_2408107010006
2.Syakila Naira_2408107010034
3. Annisa Haura Dhiya_2408107010030
4. Rahmatul Uliya_2408107010012
5. Naila Hafizha_2408107010026
6.Jazil Nazvi Khalilullah_2408107010113

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
