# C++ Store Inventory Management System 🛒

Bu proje, **Veri Yapıları** dersi kapsamında C++ kullanılarak geliştirilmiş, **Tek Yönlü Bağlı Liste (Singly Linked List)** tabanlı bir stok takip otomasyonudur. Dinamik bellek yönetimi kullanılarak ürün ekleme, silme, güncelleme ve raporlama işlemleri gerçekleştirilir.

## 🚀 Özellikler

Bu sistem, statik diziler yerine dinamik bağlı liste yapısı kullanarak bellek verimliliği sağlar.
* **CRUD İşlemleri:** Ürün Ekleme, Silme, Güncelleme ve Listeleme.
* **Sıralama Algoritmaları:** Ürünleri fiyatlarına göre (Insertion Sort mantığıyla) sıralama.
* **İstatistiksel Analiz:** En ucuz/pahalı ürün bulma, toplam stok maliyeti hesaplama.
* **Dosya İşlemleri (File I/O):** Stok durumunu `urunler.txt` dosyasına kalıcı olarak kaydetme.
* **Toplu İşlem:** Tüm ürünlere %10 zam yapma gibi toplu güncelleme fonksiyonları.

## 🛠 Teknik Detaylar

* **Veri Yapısı:** Singly Linked List (`struct node`)
* **Bellek Yönetimi:** `new` ve `delete` operatörleri ile manuel bellek yönetimi.
* **Algoritmalar:** Linear Search (Arama), Traversing (Dolaşma), Sorting.

## 💻 Kullanım

Program çalıştırıldığında kullanıcıya interaktif bir menü sunar:

```text
1- Urun Kaydet
2- Urun Sil
3- Urun Guncelle
...
7- Urunleri Kucukten Buyuge Sirala
13- Dosyaya Yazdir
