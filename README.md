# Drone Uçuş Simülasyonu (C++)

## Genel Bakış

Bu proje, temel uçuş kurallarını ve fiziksel kısıtları dikkate alan basit bir **drone simülasyonudur**. Kullanıcıdan alınan girişlere göre drone’un hareketi, pil tüketimi ve uçuş güvenliği kontrol edilir.

Kod, nesne yönelimli programlama (OOP) yaklaşımıyla yazılmıştır ve bir `Drone` sınıfı etrafında yapılandırılmıştır.

---

## Özellikler

* Drone hız kontrolü (arttırma / azaltma)
* 3 eksende hareket (X, Y, Z)
* Pil tüketimi simülasyonu
* Yük (payload) kontrolü
* Uçuş izni doğrulaması
* Güvenlik sınırları:

  * Maksimum yük
  * Minimum pil seviyesi
  * Yükseklik limitleri
  * X/Z koordinat sınırları
* Konsol tabanlı kontrol paneli

---

## Kullanılan Kavramlar

* Sınıf (class) yapısı
* Encapsulation (veri + fonksiyon)
* Koşul yapıları (`if`, `switch`)
* Döngüler (`while`, `do-while`)
* Basit sistem simülasyonu

---

## Program Akışı

### 1. Başlangıç

Kullanıcıdan aşağıdaki veriler alınır:

* Taşınan yük (gram)
* Uçuş izni (0 / 1)
* Pil yüzdesi (0–100)

Her girişten sonra sistem güvenlik kontrolü yapılır.

---

### 2. Ana Döngü

Program, uçuş güvenli olduğu sürece çalışır:

* Hareket etme
* Hız değiştirme
* Drone durumunu görüntüleme
* Ekran temizleme
* Programdan çıkış

---

## Uçuş Güvenliği Kuralları

Aşağıdaki koşullardan herhangi biri sağlanmazsa uçuş durdurulur:

* Yük > 500 gram → uçuş iptal
* Pil < %30 → güvensiz
* Yükseklik > 200 → radar dışı
* Yükseklik < 20 → güvensiz
* X/Z koordinatları sınır dışı → uçuş iptal
* Uçuş izni yok → uçuş iptal

---

## Pil Hesaplama Mantığı (Pseudocode)

Aşağıdaki algoritma, teorik pil tüketimini tanımlar:

```
BAŞLA

Yük oku
Hız oku
Yükseklik oku

pilTüketimi = (hız / 10) * 5   // tamsayı bölme
kalanPil = 100 - pilTüketimi

eğer yük > 500 ise
    "Ağır yük, uçamaz!"

değilse eğer kalanPil < 30 ise
    "Pil seviyesi düşük, uçuş güvensiz!"

değilse eğer yükseklik > 200 ise
    "Radar dışı!"

değilse eğer yükseklik < 20 ise
    "Yükseklik güvensiz!"

değilse
    "Uçuş güvenli! Kalan pil: %" + kalanPil

BİTİR
```

> Not: Gerçek kodda pil tüketimi hareket sırasında dinamik olarak (`kalanPil -= hiz`) azaltılmaktadır.

---

## Sınıf Yapısı

### `Drone` Sınıfı

Temel değişkenler:

* `hiz`, `Maxhiz`
* `x, y, z` (konum)
* `kalanPil`
* `yuk`, `maxYuk`
* `ucusIzni`

### Önemli Fonksiyonlar

* `hiz_arttir()` → hız artırır
* `hiz_azalt()` → hız azaltır
* `hareket(char yon)` → drone hareketi
* `ucus_izni_kontrol()` → tüm güvenlik kontrolleri
* `durum_goster()` → sistem durumu
* `erken_kontrol()` → başlangıç güvenlik kontrolü

---

## Çalıştırma

### Derleme

```bash
g++ drone.cpp -o drone
```

### Çalıştırma

```bash
./drone
```

---

## Platform Notları

* `system("cls")` ve `system("pause")` → Windows’a özeldir
* Linux/Mac için:

  * `cls` yerine `clear`
  * `pause` yerine `cin.get()`

---

## Sınırlamalar

* Fiziksel model basitleştirilmiştir
* Gerçekçi aerodinamik hesaplama yok
* Pil tüketimi lineer ve basittir
* Sensör verisi simüle edilmiştir

---

## Geliştirme Önerileri

* Gerçekçi pil modeli eklenebilir
* GPS simülasyonu eklenebilir
* Otonom uçuş algoritması (PID kontrol)
* Grafik arayüz (GUI)
* Dosya loglama sistemi
* Çoklu drone desteği

---

## Amaç

Bu proje, C++ ile:

* OOP mantığını öğrenmek
* Simülasyon geliştirme pratiği kazanmak
* Koşul ve kontrol mekanizmalarını pekiştirmek

için tasarlanmıştır.
