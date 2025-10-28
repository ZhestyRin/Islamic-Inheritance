
Faraid Inheritance Calculator (C Program)

English Version

Overview
This program calculates the Islamic inheritance distribution (Faraid) based on user input about the deceased’s surviving relatives.
It applies simplified inheritance rules to determine each heir’s share (father, mother, spouse, children, etc.) according to Islamic law.

Features

* Calculates inheritance shares for:

  * Husband or wife
  * Father and mother
  * Sons and daughters
  * Grandchildren (from son)
  * Siblings (brothers and sisters)
  * Grandparents
    
* Uses structured programming with struct and modular functions.
* Written in pure C language, runs on any standard compiler.

Program Structure
The program consists of:

* Family struct: holds all family relationship data and total inheritance.
* Input functions: collect family information (for example InputChildren(), InputParents2()).
* Calculation functions: compute inheritance fractions according to Faraid.
* Main function: coordinates all input, calculation, and output.

How to Compile and Run

1. Save the program as faraid_calculator.c
2. Open a terminal and compile:
   
   gcc faraid_calculator.c -o faraid_calculator
   
4. Run the program:
   
   bash
   ./faraid_calculator
   
5. Follow the prompts (for example “Is the father alive?”, “How many daughters?”).
6. The program will display the calculated inheritance shares.

Example Usage


Enter total inheritance amount:
1200000
Is there a husband? 1
Is there a son? 1
How many daughters? 1


Output:
Husband receives: 300000
Father receives: 200000
Mother receives: 200000
Children receive: 500000 (distributed 2:1 between son and daughter)

Notes

* The calculation logic is simplified and intended for educational use only.
* Actual Faraid rulings may vary based on scholars and detailed family trees.

Requirements

* GCC, Clang, or any ANSI C compiler
* Basic understanding of terminal commands

---

Versi Bahasa Indonesia

Deskripsi
Program ini digunakan untuk menghitung pembagian warisan menurut hukum Islam (Faraid) berdasarkan data ahli waris yang masih hidup.
Program mengikuti ketentuan dasar faraid untuk menentukan bagian setiap ahli waris seperti ayah, ibu, suami, istri, anak, dan lainnya.

Fitur

* Menghitung bagian warisan untuk:

  * Suami atau istri
  * Ayah dan ibu
  * Anak laki-laki dan perempuan
  * Cucu dari anak laki-laki
  * Saudara kandung, seayah, dan seibu
  * Kakek dan nenek
    
* Menggunakan struct dan fungsi modular untuk perhitungan yang rapi.
* Ditulis dalam bahasa C murni, kompatibel di semua compiler standar.

Struktur Program
Program terdiri dari:

* Struktur Family: menyimpan data hubungan keluarga dan total harta.
* Fungsi input: mengisi data keluarga (contoh InputChildren(), InputParents2()).
* Fungsi perhitungan: menentukan bagian ahli waris sesuai hukum faraid.
* Fungsi main: mengatur input, perhitungan, dan hasil akhir.

Cara Kompilasi dan Jalankan

1. Simpan program dengan nama faraid_calculator.c
2. Buka terminal dan kompilasi:
   
   gcc faraid_calculator.c -o faraid_calculator
   
4. Jalankan program:
   
   ./faraid_calculator
   
6. Masukkan data yang diminta (contoh “Apakah ayah masih hidup?”, “Berapa anak perempuan?”).
7. Program akan menampilkan hasil pembagian warisan.

Contoh Penggunaan

Masukkan total harta warisan:
1200000
Apakah ada suami? 1
Apakah ada anak laki-laki? 1
Berapa anak perempuan? 1

Keluaran:
Suami mendapat: 300000
Ayah mendapat: 200000
Ibu mendapat: 200000
Anak-anak mendapat: 500000 (dibagi 2:1 antara laki-laki dan perempuan)

Catatan

* Program ini hanya untuk tujuan edukasi.
* Perhitungan faraid sebenarnya bisa berbeda tergantung kondisi keluarga dan fatwa ulama.

Persyaratan

* Compiler C (GCC, Clang, dan sebagainya)
* Pengetahuan dasar penggunaan terminal

