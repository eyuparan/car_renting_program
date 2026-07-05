#include <stdio.h>

    #include <stdlib.h>

    #include <string.h>

    #include <conio.h>

// Şifreyi yıldızlı yapmak (getch) için gerekli

typedef struct

{

    char marka[30];

    char aciklama[100];

    int saatlik_kira;

}

Araba;

int main()

{
    char kullanici_adi[30];

    char sifre[20];

    char ch;

    int i = 0;

    printf("==================================================\n");

    printf("        ARABA KIRALAMA SISTEMI - KAYIT            \n");

    printf("==================================================\n");

    printf("Kullanici adi giriniz: ");

    scanf("%s", kullanici_adi);

    // Buffer temizleme (scanf'ten sonra fgets kullanırken sorun olmasın diye)

    while ((getchar()) != '\n');

    // 1. EKLEME: Gelişmiş Şifre Maskeleme (****)

    printf("Sifre giriniz: ");

    while (1)

    {

        ch = getch();

       // Klavyeden tuşu oku ama ekrana basma

        if (ch == 13) {

       // 13, Enter tuşunun ASCII kodudur

            sifre[i] = '\0';

            break;
    }

       // 8, Backspace (Silme) tuşudur

        else if (ch == 8) {

            if (i > 0) {

                i--;

                printf("\b \b");
            // Ekrandan bir karakter siler

            }

        }

        else if (i < 19) {

            // Şifre sınırını aşmasın

            sifre[i++] = ch;

            printf("*");

        // Karakter yerine yıldız bas

        }

    }

    printf("\n\nKaydoldunuz! Hos geldiniz, %s.\n", kullanici_adi);

    Araba filomuz[6] = {

        {"Mercedes-Benz", "Konfor, prestij ve ust duzey guvenlik arayanlar icin ideal.", 3000},

        {"BMW",           "Dinamik surus keyfi, yuksek performans ve sportiflik odakli.", 2500},

        {"Renault",       "Yuksek yakit tasarrufu, pratiklik ve sehir ici kolay kullanim.", 2000},

        {"Honda",         "Motor sorunsuzlugu, surus dinamizmi ve teknolojik donanim.", 2250},

        {"Skoda",         "Genis ic hacim, aileler icin ideal bagaj kapasitesi.", 2150},

        {"Citroen",       "Sir disi tasarim, yuksek suspansiyon konforu.", 2050}


    };

    int secim;

    // 2. EKLEME: Ana Menü Döngüsü (Program kullanıcı çıkana kadar kapanmaz)

    int ortak_benzin = 100;

         printf("1 saatlik ortak benzin fiyati:%d\n",ortak_benzin);


    while(1) {

        printf("\n==================================================\n");

        printf("        ARAC FILOMUZ VE MARKA TANITIMLARI          \n");

        printf("==================================================\n");

        for(int i = 0; i < 6; i++) {

            printf("%d) %s\n   - %s (Saatlik: %d TL)\n\n", i + 1, filomuz[i].marka, filomuz[i].aciklama, filomuz[i].saatlik_kira);

        }

        printf("0) Sistemden Cikis Yap\n");

        printf("==================================================\n");

        printf("Yapmak istediginiz islemi seciniz: ");

        scanf("%d", &secim);

        if(secim == 0) {

            printf("\nSistemden guvenli cikis yapildi. Iyi gunler dileriz!\n");

            break; // Döngüden çıkar ve programı bitir

        }

        if(secim < 1 || secim > 6) {

            printf("\n[HATA] Gecersiz secim! Lutfen tekrar deneyin.\n");

            continue;

        // Döngünün başına döner

        }

        int secilen_index = secim - 1;

        printf("\nSecilen Arac: %s\n", filomuz[secilen_index].marka);

        int arac_kira_saati;

        printf("Araci kac saat kiralamak istersiniz?: ");

        scanf("%d", &arac_kira_saati);


        int toplam_maliyet = arac_kira_saati * (filomuz[secilen_index].saatlik_kira + ortak_benzin);

        printf("\n--- FATURA DETAYI ---\n");

        printf("Arac: %s\n", filomuz[secilen_index].marka);

        printf("Sure: %d saat\n", arac_kira_saati);

        printf("TOTAL MALIYET: %d TL\n", toplam_maliyet);

        printf("---------------------\n");

        // Puanlama Sistemi

        int arac_puani;

        printf("\n--- ARAC PUANLAMA SISTEMI ---\n");

        printf("Kiraladiginiz araci nasil buldunuz? (1-5): ");

        scanf("%d", &arac_puani);

        if (arac_puani == 5)

        printf("Harika! Araci cok begendiginize sevindik.\n");

        else if (arac_puani == 4)

       printf("Guzel! Geri bildiriminiz icin tesekkur ederiz.\n");

        else if (arac_puani == 3)

        printf("Ortalama bir deneyim olmus.\n");

        else

        printf("Geri bildiriminiz kaydedildi.\n");

        // 3. EKLEME: Gelişmiş Geri Dönüş (Boşluk bırakarak normal cümle yazılabilir)

        char geri_donut[200];

        while ((getchar()) != '\n');

         // Buffer temizliği

        printf("\n--- GERI DONUT KUTUSU ---\n");

        printf("Oneri veya sikayetinizi normal bir cumle olarak yazabilirsiniz:\n> ");

        fgets(geri_donut, sizeof(geri_donut), stdin);

        // fgets sonundaki newline (\n) karakterini temizleme

        geri_donut[strcspn(geri_donut, "\n")] = 0;

        printf("\nFikriniz sistemimize kaydedildi: \"%s\"\n", geri_donut);

        printf("\nIslem tamamlandi! Ana menuye yonlendiriliyorsunuz...\n");

    }

    return 0;

}
