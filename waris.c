
#include <stdio.h>
#include <stdbool.h>

#define IS_TRUE(x) ((x) >= 1)
#define IS_FALSE(x) ((x) == 0)

typedef struct{
    int Anak[2];
    int Orang_tua2[2];
    int Orang_tua[2];
    int Cucu_Dari_Laki[2];
    int Saudara_laki[3];
    int Saudara_perempuan[3];
    int Eyang[2];
    double Harta;
    float Ashabah;
    float KShabah;
} Keluarga;


void Harta(Keluarga *dt) {
    printf("Masukan Harta yang dimiliki: \n");
    scanf(" %lf", &dt->Harta);
}


void Anak(Keluarga *dt) {
    printf("Apakah ada anak laki-laki? '0' untuk tidak, '1' untuk ada\n");
    scanf(" %d", &dt->Anak[0]);

    printf("Berapakah jumlah anak Perempuan? '0' untuk tidak ada, 'jumlah' kalau ada\n");
    scanf(" %d", &dt->Anak[1]);
}


void OrangTua2(Keluarga *dt) {
    printf("Apakah ada Bapak? '0' untuk tidak, '1' untuk ada\n");
    scanf(" %d", &dt->Orang_tua2[0]);

    printf("Apakah ada Ibu? '0' untuk tidak, '1' untuk ada\n");
    scanf(" %d", &dt->Orang_tua2[1]);
}


void OrangTua(Keluarga *dt) {
    printf("Apakah ada Suami? '0' untuk tidak, '1' untuk ada\n");
    scanf("%d", &dt->Orang_tua[0]);

    printf("Apakah ada istri? '0' untuk tidak, '1' untuk ada\n");
    scanf("%d", &dt->Orang_tua[1]);
}


void CucuDariAnakLaki(Keluarga *dt) {
    printf("Apakah ada Cucu laki-laki dari anak laki-laki? '0' untuk tidak, '1' untuk ada\n");
    scanf("%d", &dt->Cucu_Dari_Laki[0]);

    printf("Berapakah jumlah Cucu perempuan dari anak laki? '0' untuk tidak ada, 'jumlah' kalau ada\n");
    scanf("%d", &dt->Cucu_Dari_Laki[1]);
}


void SaudaraLaki(Keluarga *dt) {
    printf("Apakah ada Saudara laki sekandung? '0' untuk tidak ada, '1' untuk ada\n");
    scanf("%d", &dt->Saudara_laki[0]);
    printf("Apakah ada Saudara laki sebapak? '0' untuk tidak ada, '1' untuk ada\n");
    scanf("%d", &dt->Saudara_laki[1]);
    printf("Berapa jumlah Saudara laki seibu? '0' untuk tidak ada, 'jumlah' kalau ada\n");
    scanf("%d", &dt->Saudara_laki[2]);
}


void SaudaraPerempuan(Keluarga *dt) {
    printf("Berapakah jumlah saudara perempuan sekandung? '0' untuk tidak ada, 'jumlah' kalau ada\n");
    scanf("%d", &dt->Saudara_perempuan[0]);
    printf("Berapakah jumlah saudara perempuan sebapak? '0' untuk tidak ada, 'jumlah' kalau ada\n");
    scanf("%d", &dt->Saudara_perempuan[1]);
    printf("Berapakah jumlah saudara perempuan seibu? '0' untuk tidak ada, 'jumlah' kalau ada\n");
    scanf("%d", &dt->Saudara_perempuan[2]);
}


void Eyang(Keluarga *dt) {
    printf("Apakah ada Kakek? '0' untuk tidak, '1' untuk ada\n");
    scanf("%d", &dt->Eyang[0]);
    printf("Apakah ada Nenek? '0' untuk tidak, '1' untuk ada\n");
    scanf("%d", &dt->Eyang[1]);
}


void BagianOrangTua(Keluarga dt, float *BagianSuami, float *BagianIstri, float *BagianBapak, float *BagianIbu) {
    float sisa = 0.0f;

    *BagianSuami = 0.0f;
    *BagianIstri = 0.0f;
    *BagianBapak = 0.0f;
    *BagianIbu = 0.0f;

    if ((dt.Orang_tua[0] == 1 && dt.Anak[0] == 0 && dt.Anak[1] == 0) || (dt.Cucu_Dari_Laki[0] == 0 && dt.Cucu_Dari_Laki[1] == 0)) {
        *BagianSuami = (1.0f / 2.0f) * dt.Harta;
    }
    else if ((dt.Orang_tua[0] == 1 && dt.Anak[0] == 1 && dt.Anak[1] == 1) || (dt.Cucu_Dari_Laki[0] == 1 && dt.Cucu_Dari_Laki[1] == 1)) {
        *BagianSuami = (1.0f / 4.0f) * dt.Harta;
    }

    if ((dt.Orang_tua[1] == 1 && dt.Anak[0] == 0 && dt.Anak[1] == 0) || (dt.Cucu_Dari_Laki[0] == 0 && dt.Cucu_Dari_Laki[1] == 0)) {
        *BagianIstri = (1.0f / 4.0f) * dt.Harta;
    }
    else if ((dt.Orang_tua[1] == 1 && dt.Anak[0] == 1 && dt.Anak[1] == 1) || (dt.Cucu_Dari_Laki[0] == 1 && dt.Cucu_Dari_Laki[1] == 1)) {
        *BagianIstri = (1.0f / 8.0f) * dt.Harta;
    }

    if ((dt.Orang_tua2[0] == 1 && dt.Anak[0] == 1 && dt.Anak[1] == 1) || (dt.Cucu_Dari_Laki[0] == 1 && dt.Cucu_Dari_Laki[1] == 1)) {
        *BagianBapak = (1.0f / 6.0f) * dt.Harta;
    }

    if ((dt.Orang_tua2[1] == 1 && dt.Anak[0] == 1 && dt.Anak[1] == 1) || (dt.Cucu_Dari_Laki[0] == 1 && dt.Cucu_Dari_Laki[1] == 1) || dt.Saudara_laki[0] >= 2 || dt.Saudara_laki[1] >= 2 || dt.Saudara_laki[2] >= 2 || dt.Saudara_perempuan[0] >= 2 || dt.Saudara_perempuan[1] >= 2 || dt.Saudara_perempuan[2] >= 2) {
        *BagianIbu = (1.0f / 6.0f) * dt.Harta;
    }
    else if ((dt.Orang_tua2[1] == 1 && dt.Anak[0] == 0 && dt.Anak[1] == 0) || (dt.Cucu_Dari_Laki[0] == 0 && dt.Cucu_Dari_Laki[1] == 0) || dt.Saudara_laki[0] == 0 || dt.Saudara_laki[1] == 0 || dt.Saudara_laki[2] == 0 || dt.Saudara_perempuan[0] == 0 || dt.Saudara_perempuan[1] == 0 || dt.Saudara_perempuan[2] == 0) {
        *BagianIbu = (1.0f / 3.0f) * dt.Harta;
    }

    if (dt.Orang_tua[1] == 0 && dt.Orang_tua[0] == 1 && dt.Orang_tua2[1] == 1 && dt.Orang_tua2[0] == 1 && dt.Anak[0] == 1 && dt.Anak[1] >= 1) {
        *BagianSuami = (1.0f / 2.0f) * dt.Harta;
        *BagianIbu = (1.0f / 3.0f) * *BagianSuami;
        sisa = *BagianSuami - *BagianIbu;
        *BagianBapak = sisa;
    }
    else if (dt.Orang_tua[0] == 0 && dt.Orang_tua[1] == 1 && dt.Orang_tua2[0] == 1 && dt.Orang_tua2[1] == 1 && dt.Anak[0] == 1 && dt.Anak[1] >= 1) {
        *BagianIstri = (1.0f / 4.0f) * dt.Harta;
        sisa = dt.Harta - *BagianIstri;
        *BagianIbu = (1.0f / 3.0f) * sisa;
        *BagianBapak = sisa - *BagianIbu;
    }
}


void BagianCucuDariAnakLaki(Keluarga dt, float *BagianCucuLaki, float *BagianCucuPerempuan) {
    *BagianCucuLaki = 0.0f;
    *BagianCucuPerempuan = 0.0f;

    if (dt.Cucu_Dari_Laki[1] == 1 && dt.Anak[0] == 0 && dt.Anak[1] == 0) {
        *BagianCucuPerempuan = (1.0f / 2.0f) * dt.Harta;
    }
    else if (dt.Cucu_Dari_Laki[1] >= 2 && dt.Anak[0] == 0 && dt.Anak[1] == 0) {
        *BagianCucuPerempuan = (2.0f / 3.0f) * dt.Harta;
    }
    else if (dt.Cucu_Dari_Laki[1] >= 1 && dt.Anak[1] == 1 && dt.Anak[0] == 0) {
        *BagianCucuPerempuan = (1.0f / 6.0f) * dt.Harta;
    }
    else if ((dt.Cucu_Dari_Laki[1] == 1 && dt.Anak[0] == 1) || (dt.Anak[1] >= 2)) {
        *BagianCucuPerempuan = 0.0f;
    }
}


void BagianSaudaraLaki(Keluarga dt, float *SaudaraLakiSeibu, float *SaudaraLakiSekandung, float *SaudaraLakiSebapak) {
    *SaudaraLakiSeibu = 0.0f;
    *SaudaraLakiSekandung = 0.0f;
    *SaudaraLakiSebapak = 0.0f;

    if (dt.Saudara_laki[2] == 1 && dt.Anak[0] == 0 && dt.Anak[1] == 0 && dt.Cucu_Dari_Laki[0] == 0 && dt.Cucu_Dari_Laki[1] == 0 && dt.Orang_tua2[0] == 0 && dt.Eyang[0] == 0) {
        *SaudaraLakiSeibu = (1.0f / 6.0f) * dt.Harta;
    }
    else if (dt.Saudara_laki[2] >= 2 && dt.Anak[0] == 0 && dt.Anak[1] == 0 && dt.Cucu_Dari_Laki[0] == 0 && dt.Cucu_Dari_Laki[1] == 0 && dt.Orang_tua2[0] == 0 && dt.Eyang[0] == 0) {
        *SaudaraLakiSeibu = (1.0f / 3.0f) * dt.Harta;
    }

    if ((dt.Saudara_laki[2] >= 1 && dt.Anak[0] == 1) || (dt.Anak[1] >= 1 && dt.Cucu_Dari_Laki[0] == 1) || (dt.Cucu_Dari_Laki[1] >= 1 && dt.Orang_tua2[0] == 1) || (dt.Eyang[0] == 1)) {
        *SaudaraLakiSeibu = 0.0f;
    }
}


void BagianSaudaraPerempuan(Keluarga dt, float *SaudaraPereSeibu, float *SaudaraPereSebapak, float *SaudaraPereSekandung) {
    *SaudaraPereSeibu = 0.0f;
    *SaudaraPereSebapak = 0.0f;
    *SaudaraPereSekandung = 0.0f;

    if (dt.Saudara_perempuan[2] == 1 && dt.Anak[0] == 0 && dt.Anak[1] == 0 && dt.Cucu_Dari_Laki[0] == 0 && dt.Cucu_Dari_Laki[1] == 0 && dt.Orang_tua2[0] == 0 && dt.Eyang[0] == 0) {
        *SaudaraPereSeibu = (1.0f / 6.0f) * dt.Harta;
    }
    else if (dt.Saudara_perempuan[2] >= 2 && dt.Anak[0] == 0 && dt.Anak[1] == 0 && dt.Cucu_Dari_Laki[0] == 0 && dt.Cucu_Dari_Laki[1] == 0 && dt.Orang_tua2[0] == 0 && dt.Eyang[0] == 0) {
        *SaudaraPereSeibu = (1.0f / 3.0f) * dt.Harta;
    }

    if ((dt.Saudara_perempuan[2] >= 1 && dt.Anak[0] == 1) || (dt.Anak[1] >= 1 && dt.Cucu_Dari_Laki[0] == 1) || (dt.Cucu_Dari_Laki[1] >= 1 && dt.Orang_tua2[0] == 1) || (dt.Eyang[0] == 1)) {
        *SaudaraPereSeibu = 0.0f;
    }

    if (dt.Saudara_perempuan[1] == 1 && dt.Anak[1] == 0 && dt.Cucu_Dari_Laki[1] == 0 && dt.Saudara_perempuan[0] == 0) {
        *SaudaraPereSebapak = (1.0f / 2.0f) * dt.Harta;
    }
    else if (dt.Saudara_perempuan[1] >= 2 && dt.Anak[1] == 0 && dt.Cucu_Dari_Laki[1] == 0 && dt.Saudara_perempuan[0] == 0) {
        *SaudaraPereSebapak = (2.0f / 3.0f) * dt.Harta;
    }
    else if (dt.Saudara_perempuan[1] == 1 && dt.Saudara_perempuan[0] == 1 && dt.Anak[1] == 0 && dt.Cucu_Dari_Laki[1] == 0) {
        *SaudaraPereSebapak = (1.0f / 6.0f) * dt.Harta;
    }

    if (dt.Orang_tua2[0] == 1 || dt.Anak[0] >= 1 || dt.Cucu_Dari_Laki[0] >= 1) {
        *SaudaraPereSebapak = 0.0f;
    }

    if (dt.Saudara_perempuan[0] == 1 && dt.Saudara_laki[0] == 0 && dt.Orang_tua2[0] == 0 && dt.Anak[0] == 0 && dt.Cucu_Dari_Laki[0] == 0) {
        *SaudaraPereSekandung = (1.0f / 2.0f) * dt.Harta;
    }
    else if (dt.Saudara_perempuan[0] >= 2 && dt.Saudara_laki[0] == 0 && dt.Orang_tua2[0] == 0 && dt.Anak[0] == 0 && dt.Cucu_Dari_Laki[0] == 0) {
        *SaudaraPereSekandung = (2.0f / 3.0f) * dt.Harta;
    }

    if (dt.Saudara_perempuan[0] >= 1 || dt.Orang_tua2[0] == 1 || dt.Anak[0] >= 1 || dt.Cucu_Dari_Laki[0] >= 1) {
        *SaudaraPereSekandung = 0.0f;
    }
}


void HitungBagianNenek(Keluarga dt, float *BagianNenek) {
    *BagianNenek = 0.0f;
    if (dt.Eyang[1] >= 1) {
        *BagianNenek = (1.0f / 6.0f) * dt.Harta;
    }
}


void HitungBagianKakek(Keluarga dt, float *BagianKakek) {
    if (dt.Orang_tua[0] == 1) {
        *BagianKakek = 0.0f;
        return;
    }

    if (dt.Anak[0] > 0 || dt.Anak[1] > 0) {
        *BagianKakek = (1.0f / 6.0f) * dt.Harta;
        return;
    }

    *BagianKakek = 0.0f; // akan diproses di ashobah jika perlu
}


void Anak_Anak(Keluarga dt, float *BagianAnakPerempuan) {
    *BagianAnakPerempuan = 0.0f;

    if (dt.Anak[0] >= 1 && dt.Anak[1] >= 1) {
        int totalBagian = (dt.Anak[0] * 2) + dt.Anak[1];
        float satuBagian = dt.Harta / (float)totalBagian;
        *BagianAnakPerempuan = satuBagian * dt.Anak[1];
    }
    else if (dt.Anak[1] == 1 && dt.Anak[0] == 0) {
        *BagianAnakPerempuan = (1.0f / 2.0f) * dt.Harta;
    }
    else if (dt.Anak[1] >= 2 && dt.Anak[0] == 0) {
        *BagianAnakPerempuan = (2.0f / 3.0f) * dt.Harta;
    }
}


void Ashobah(Keluarga dt, float *BagianBapak, float *BagianKakek, float *BagianSuami, float *BagianIstri, float *BagianCucuLaki, float *BagianCucuPerempuan, float *BagianIbu, float *SaudaraLakiSeibu, float *SaudaraLakiSekandung, float *SaudaraLakiSebapak, float *SaudaraPereSeibu, float *SaudaraPereSekandung, float *SaudaraPereSebapak, float *BagianNenek, float *BagianAnakPerempuan) {
    float sisa = (float)dt.Harta - (*BagianIbu + *BagianNenek + *BagianSuami + *BagianIstri + *BagianAnakPerempuan + *SaudaraLakiSeibu + *SaudaraPereSeibu + *BagianCucuPerempuan + *SaudaraPereSekandung + *SaudaraPereSebapak + *BagianBapak);

    if (dt.Anak[0] >= 1) {
        int totalBagian = (dt.Anak[0] * 2) + dt.Anak[1];
        float satuBagian = sisa / (float)totalBagian;

        *BagianKakek = 0.0f;
        *SaudaraLakiSeibu = 0.0f;
        *SaudaraLakiSekandung = 0.0f;
        *SaudaraLakiSebapak = 0.0f;

        printf("=== ASHABAH (ANAK LAKI-LAKI) ===\n");
        printf("Setiap anak laki-laki mendapat: %.2f\n", satuBagian * 2.0f);
        printf("Total anak perempuan sebelumnya sudah dihitung.\n");
        return;
    }

    if (dt.Eyang[0] == 1) {
        *BagianKakek += sisa; // Kakek mengambil semua sisa
        printf("=== ASHABAH (KAKEK) ===\n");
        printf("Kakek mengambil seluruh sisa: %.2f\n", sisa);
        return;
    }

    if (dt.Saudara_laki[0] >= 1 || dt.Saudara_laki[1] >= 1 || dt.Saudara_laki[2] >= 1) {
        int jumlahSaudara = dt.Saudara_laki[0] + dt.Saudara_laki[1] + dt.Saudara_laki[2];
        if (jumlahSaudara > 0) {
            float satuBagian = sisa / (float)jumlahSaudara;
            *SaudaraLakiSeibu += satuBagian * dt.Saudara_laki[2];
            *SaudaraLakiSekandung += satuBagian * dt.Saudara_laki[0];
            *SaudaraLakiSebapak += satuBagian * dt.Saudara_laki[1];

            printf("=== ASHABAH (SAUDARA LAKI-LAKI) ===\n");
            printf("Setiap saudara laki-laki mendapat sesuai kelompoknya\n");
            return;
        }
    }

    printf("Tidak ada ahli waris ashobah yang berhak mengambil sisa.\n");
}


int main() {
    Keluarga dt = {0};



printf("                -----PROGRAM WARISAN METODE ISLAM-----             \n");


    Harta(&dt);
    Anak(&dt);
    CucuDariAnakLaki(&dt);
    OrangTua(&dt);
    OrangTua2(&dt);
    SaudaraLaki(&dt);
    SaudaraPerempuan(&dt);
    Eyang(&dt);


    float BagianSuami = 0.0f, BagianIstri = 0.0f, BagianBapak = 0.0f, BagianIbu = 0.0f;
    float BagianCucuLaki = 0.0f, BagianCucuPerempuan = 0.0f;
    float SaudaraLakiSeibu = 0.0f, SaudaraLakiSekandung = 0.0f, SaudaraLakiSebapak = 0.0f;
    float SaudaraPereSeibu = 0.0f, SaudaraPereSekandung = 0.0f, SaudaraPereSebapak = 0.0f;
    float BagianNenek = 0.0f, BagianKakek = 0.0f, BagianAnakPerempuan = 0.0f;

    
    BagianOrangTua(dt, &BagianSuami, &BagianIstri, &BagianBapak, &BagianIbu);
    BagianCucuDariAnakLaki(dt, &BagianCucuLaki, &BagianCucuPerempuan);
    BagianSaudaraLaki(dt, &SaudaraLakiSeibu, &SaudaraLakiSekandung, &SaudaraLakiSebapak);
    BagianSaudaraPerempuan(dt, &SaudaraPereSeibu, &SaudaraPereSebapak, &SaudaraPereSekandung);
    HitungBagianNenek(dt, &BagianNenek);
    HitungBagianKakek(dt, &BagianKakek);
    Anak_Anak(dt, &BagianAnakPerempuan);


    Ashobah(dt, &BagianBapak, &BagianKakek, &BagianSuami, &BagianIstri, &BagianCucuLaki, &BagianCucuPerempuan, &BagianIbu, &SaudaraLakiSeibu, &SaudaraLakiSekandung, &SaudaraLakiSebapak, &SaudaraPereSeibu, &SaudaraPereSekandung, &SaudaraPereSebapak, &BagianNenek, &BagianAnakPerempuan);

    
    printf("\n--- HASIL PERHITUNGAN BAGIAN WARIS ---\n");
    printf("Total harta: %.2f\n", dt.Harta);
    printf("Bagian Suami: %.2f\n", BagianSuami);
    printf("Bagian Istri: %.2f\n", BagianIstri);
    printf("Bagian Bapak: %.2f\n", BagianBapak);
    printf("Bagian Ibu: %.2f\n", BagianIbu);
    printf("Bagian Kakek: %.2f\n", BagianKakek);
    printf("Bagian Nenek: %.2f\n", BagianNenek);
    printf("Bagian Cucu Laki: %.2f\n", BagianCucuLaki);
    printf("Bagian Cucu Perempuan: %.2f\n", BagianCucuPerempuan);
    printf("Bagian Anak Perempuan (total): %.2f\n", BagianAnakPerempuan);
    printf("Saudara Laki - Seibu: %.2f, Sekandung: %.2f, Sebapak: %.2f\n", SaudaraLakiSeibu, SaudaraLakiSekandung, SaudaraLakiSebapak);
    printf("Saudara Perempuan - Seibu: %.2f, Sekandung: %.2f, Sebapak: %.2f\n", SaudaraPereSeibu, SaudaraPereSekandung, SaudaraPereSebapak);

    return 0;
}
