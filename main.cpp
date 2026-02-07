#include <iostream>
#include <ctype.h>
#include <fstream>
using namespace std;

struct node
{
    int id; // ürünleri saklamak için tek yönlü bağlı liste oluşturdum
    string ad;
    float fiyat;
    node *next;
};

node *ekle(node *root, int id, string ad, float fiyat)
{
    node *temp = new (node);
    temp->id = id; // sondan ürün eklemek için ekle fonksiyonunu oluşturdum
    temp->ad = ad;
    temp->fiyat = fiyat;

    node *iter = root;

    while (iter->next != NULL)
        iter = iter->next;

    iter->next = temp;
    temp->next = NULL;

    return root;
}

void yazdir(node *root)
{
    while (root != NULL)
    { // tüm ürünleri yazdıran yazdir fonksiyonu
        std::cout << "Urun id: " << root->id << "\tUrun adi: " << root->ad << "\tUrun fiyati: " << root->fiyat << endl;
        root = root->next;
    }
}

node *sil(node *root, int id)
{

    node *iter = root;
    node *temp; // ürün silmek için sil fonksiyonunu oluşturdum
    if (id == root->id)
    {
        temp = root; // silinen ürünün başta olması bir istisna olduğu için bunu kontrol ettim
        root = root->next;
        free(temp);
    } // silinecek ürün başta değilse genelleştirilmiş silme fonksiyonunu yazdım

    while (iter->next != NULL && iter->next->id != id)
    {
        iter = iter->next;
    }
    if (iter->next == NULL)
    {
        std::cout << "Urun bulunamadi.";
        return root;
    }
    temp = iter->next;
    iter->next = temp->next;
    free(temp);

    return root;
}

node *guncelle(node *root, int id)
{
    node *iter = root;
    while (iter != NULL && iter->id != id)
    {
        iter = iter->next;
    } // id kontrolu yaparak ürün güncellemesi yapıyorum
    if (iter == NULL)
    { // eğer aranan id ile kayıtlı bir ürün yoksa bir uyarı mesajı gönderiyor.
        std::cout << "Guncellemek istediginiz urun bulunamadi.";
        return root;
    } // ürün mevcutsa ürünün bulunduğunu belirten bir mesaj ve ürün bilgilerini listeliyor
    std::cout << "Aradiginiz urun bulundu! Mevcut urun bilgileri: " << endl;
    std::cout << "Urun id: " << iter->id << "\tUrun adi: " << iter->ad << "\tUrun fiyati: " << iter->fiyat << endl;

    std::cout << "Urunde yapmak istediginiz guncellemeyi belirleyiniz: " << endl
              << "1-Ad degisikligi" << endl
              << "2-Fiyat degisikligi" << endl // kullanıcıya ürün üzeridne nasıl bir değişiklik yapmak istediğini sordum
              << "3-Id degisikligi" << endl;
    int secim;
    cin >> secim;

    switch (secim)
    {
    case 1:
        std::cout << "Ad degisikligi yapmak icin bir ad girin: ";
        cin >> iter->ad;
        std::cout << "Urun adi basariyla degistirildi!" << endl;
        break;
    case 2:
        std::cout << "Fiyat degisikligi yapmak icin bir fiyat girin: ";
        cin >> iter->fiyat;
        std::cout << "Urun fiyati basariyla degistirildi!" << endl;
        break;
    case 3:
        std::cout << "Id degisikligi yapmak icin bir Id girin: ";
        cin >> iter->id;
        std::cout << "Urun Id basariyla degistirildi!" << endl;
        break;
    }
    return root;
}

node *ara(node *root)
{
    int secim = 0;
    node *iter = root;
    std::cout << "Yapmak istediginiz arama turu: " << endl
              << "1-Id ile arama" << endl // kullanıcıya id ile mi yoksa ad ile mi arama yapmak istediğini sordum.
              << "2- Ad ile arama" << endl;
    cin >> secim;
    switch (secim)
    {
    case 1:
        int id; // id bazlı arama yapan bölüm
        std::cout << "Arama icin id girin: ";
        cin >> id;
        while (iter != NULL && iter->id != id)
        {
            iter = iter->next;
        }
        if (iter == NULL)
        {
            std::cout << "Aradiginiz urun bulunamadi";
            return root;
        }

        std::cout << "Aradiginiz urun stoklarda mevcuttur." << endl;
        return root;
        break;

    case 2:
        string ad;
        std::cout << "Arama icin ad girin: "; // ad bazlı arama yapan bölüm
        cin >> ad;
        while (iter != NULL && iter->ad != ad)
        {
            iter = iter->next;
        }
        if (iter == NULL)
        {
            std::cout << "Aradiginiz urun bulunamadi";
            return root;
        }

        std::cout << "Aradiginiz urun stoklarda mevcuttur. " << endl;
        return root;

        break;
    }
}

node *araVeYazdir(node *root)
{
    int secim = 0;
    node *iter = root;
    std::cout << "Yapmak istediginiz arama turu: " << endl
              << "1-Id ile arama" << endl
              << "2- Ad ile arama" << endl;
    cin >> secim;
    switch (secim)
    {
    case 1:
        int id;
        std::cout << "Arama icin id girin: ";
        cin >> id;
        while (iter != NULL && iter->id != id)
        {
            iter = iter->next;
        }
        if (iter == NULL)
        {
            std::cout << "Aradiginiz urun bulunamadi";
            return root;
        }

        std::cout << "Aradiginiz urun bulundu! Mevcut urun bilgileri: " << endl;
        std::cout << "Urun id: " << iter->id << "\tUrun adi: " << iter->ad << "\tUrun fiyati: " << iter->fiyat << endl;
        return root;

        break;

    case 2:
        string ad;
        std::cout << "Arama icin ad girin: ";
        cin >> ad;
        while (iter != NULL && iter->ad != ad)
        {
            iter = iter->next;
        }
        if (iter == NULL)
        {
            std::cout << "Aradiginiz urun bulunamadi";
            return root;
        }

        std::cout << "Aradiginiz urun bulundu! Mevcut urun bilgileri: " << endl;
        std::cout << "Urun id: " << iter->id << "\tUrun adi: " << iter->ad << "\tUrun fiyati: " << iter->fiyat << endl;
        return root;

        break;
    }
}

node *siraliEkle(node *root, int id, string ad, float fiyat)
{

    node *temp = new (node);
    temp->fiyat = fiyat;
    temp->id = id;
    temp->ad = ad;
    // listeye eklenecek ürünleri küçükten büyüğe ekleyen fonksiyon.
    if (root == NULL)
    { // liste boşta doğrudan ekleme yapıyor.

        temp->next = NULL;
        return temp;
    }

    if (fiyat < root->fiyat)
    { // eklenecek ürün fiyatı ilk üründen daha düşükse en başa ekleme yapıyor
        temp->next = root;
        return temp;
    }

    node *iter = root;
    while (iter->next != NULL && fiyat < iter->next->fiyat)
    { // diğer şartlarda ise yeni ürünü fiyatı kendisinden daha
      // yüksek olan ilk üründen bir önceye yerleştiriyor
        iter = iter->next;
    }

    temp->next = iter->next;
    iter->next = temp;
    return root;
}

node *urunleriSirala(node *root)
{
    node *liste = NULL;
    node *iter = root; // listedeki urunleri fiyatlarına gore siralayan kod bloğu
    while (iter->next != NULL)
    {
        liste = siraliEkle(liste, iter->id, iter->ad, iter->fiyat);
        iter = iter->next;
    }
    return liste;
}

void maliyetHesapla(node *root)
{
    float maliyet = 0;
    while (root != NULL)
    {
        maliyet += root->fiyat;
        root = root->next;
    }

    std::cout << "Toplam urun maliyeti: " << maliyet << endl;
}

node *zamYap(node *root)
{
    node *iter = root;
    int fiyat = 0;
    while (iter != NULL)
    { // listedeki tüm ürünleri ddolaşıp mevcut fiyatlarına 10% ekleme yapan kod bloğu
        fiyat = iter->fiyat;

        iter->fiyat = fiyat + (fiyat / 10);

        iter = iter->next;
    }
    std::cout << "Urunlere 10% zam yapildi!";
    return root;
}

void minBul(node *root)
{

    float min = root->fiyat;
    node *iter = root;
    // listedeki tüm ürünleri dolaşıp minimum değeri bulan kod bloğu
    while (iter->next != NULL)
    {

        if (iter->fiyat < min)
            min = iter->fiyat;

        iter = iter->next;
    }

    std::cout << "Minimum maliyete sahip urun maliyeti: " << min;
}

void maxBul(node *root)
{
    float max = root->fiyat;
    node *iter = root; // listedeki tüm ürünleri dolaşığp maksimum değeri bulan kod bloğu
    while (iter->next != NULL)
    {
        if (iter->fiyat > max)
            ;
        max = iter->fiyat;
        iter = iter->next;
    }
    std::cout << "Maksimum maliyete sahip urun maliyeti: " << max;
}

void urunSayisi(node *root)
{
    int sayac = 0; // listedeki urunleri bulan kod bloğu
    while (root != NULL)
    {
        sayac++;
        root = root->next;
    }

    std::cout << "Stokta bulunan toplam urun sayisi: " << sayac;
}

void dosyayaYazdir(node *root)
{
    fstream dosya("urunler.txt", ios::out);
    if (!dosya)
    {
        cerr << "Dosya acilamadi!";
        exit(EXIT_FAILURE);
    } // listedeki urunleri dolasip sirasiyla dosyaya yazdıran kod bloğu
    else
    {
        while (root != NULL)
        {
            dosya << "Urun id: " << root->id << "\tUrun adi: " << root->ad << "\tUrun fiyati: " << root->fiyat << endl;
            root = root->next;
        }
    }

    std::cout << "Urun stogu basariyla urunler.txt dosyasina yazdirildi!";
}

int main()
{

    node *urun = new (node);
    urun->ad = "Bilgisayar";
    urun->id = 1;
    urun->fiyat = 35000; // baslangıc icin listeye eklenmis urunler
    urun->next = NULL;
    urun = ekle(urun, 2, "Gozluk", 200);
    urun = ekle(urun, 3, "Canta", 300);
    urun = ekle(urun, 4, "Telefon", 15000);
    urun = ekle(urun, 5, "Defter", 50);

    int secim = 0;

    std::cout << "Tek yonlu bagli liste yapisi ile magazaya yeni gelen urunlerin tutuldugu urun takip listesine hosgeldiniz." << endl;
    while (secim != 15)
    {
        std::cout << "1-Urun Kaydet" << endl;
        std::cout << "2-Urun sil" << endl;
        std::cout << "3-Urun guncelle" << endl;
        std::cout << "4-Listede urun ara" << endl;
        std::cout << "5-Listede aranan urunun ozelliklerini yazdir" << endl;
        std::cout << "6-Tum Urunleri yazdir" << endl;
        std::cout << "7-Listede yer alan urunleri kucukten buyuge sirala" << endl; // 15 degeri girilene kadar programı devam ettiren while dongusu
        std::cout << "8-Yer alan tum urunlerin toplam maliyetini hesapla" << endl;
        std::cout << "9-Listede yer alan tum urunlere 10% zam yap" << endl;
        std::cout << "10-Minimum maliyete sahip ürünün maliyetini yazdır" << endl;
        std::cout << "11-Maksimum maliyete sahip ürünün maliyetini yazdır" << endl;
        std::cout << "12-Toplam urun sayisini bul" << endl;
        std::cout << "13-Tum urunleri dosyaya yazdir" << endl;
        std::cout << "14-Dosyadan urunleri oku" << endl;
        std::cout << "15-Cikis" << endl;
        std::cout << "Bir islem secin:";
        cin >> secim;

        string ad = "temp";
        int id = 0;
        float fiyat = 0;

        switch (secim)
        {
        case 1:

            std::cout << "ID:";
            cin >> id;
            std::cout << "Urun adi: "; // yapılan secime gore uygun fonksiyonları cagıran switch bloklari
            cin >> ad;
            std::cout << "Urun fiyati: ";
            cin >> fiyat;
            urun = ekle(urun, id, ad, fiyat);
            cout << "Urun eklendi!";
            break;

        case 2:
            std::cout << "Silmek istediginiz urunun ID'sini girin:";

            cin >> id;
            urun = sil(urun, id);
            break;

        case 3:
            std::cout << "Guncellemek istediginiz urun ID'sini girin: ";

            cin >> id;
            urun = guncelle(urun, id);
            break;

        case 4:
            urun = ara(urun);
            break;

        case 5:
            urun = araVeYazdir(urun);
            break;

        case 6:
            yazdir(urun);
            break;

        case 7:
            urun = urunleriSirala(urun);
            break;

        case 8:
            maliyetHesapla(urun);
            break;

        case 9:
            urun = zamYap(urun);
            break;

        case 10:
            minBul(urun);
            break;

        case 11:
            maxBul(urun);
            break;

        case 12:
            urunSayisi(urun);
            break;

        case 13:
            dosyayaYazdir(urun);
            break;

        default:
            std::cout << "Lutfen gecerli bir secim yapin.";
        }

        std::cout << endl
                  << endl;
    }

    /*urun = urunleriSirala(urun);
    yazdir(urun);
    urun=zamYap(urun);
    std::cout << endl << endl << endl;
    dosyayaYazdir(urun);
    */
}
