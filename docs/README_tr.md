# Deneyap Kumanda Kolu Arduino Kütüphanesi

***** Fotoğraf eklenecek ****

Deneyap Kumanda Kolu için Arduino kütüphanesidir.

## :mag_right:Özellikler 
- `Ürün ID` **M26**, **mpv1.0**
- `MCU` STM8S003F3
- `Ağırlık`
- `Modul Boyutları` 
- `I2C Adres` 0x1A, 0x1B, 0x1C, 0x1D

| Adres |  | 
| :---  | :---     |
| 0x1A | varsayılan adres |
| 0x1B | ADR1 kısa devre yapıldığındaki adres |
| 0x1C | ADR2 kısa devre yapıldığındaki adres |
| 0x1D | ADR1 ve ADR2 kısa devre yapıldığındaki adres |

## :closed_book:Dokümanlar
Deneyap Kumanda Kolu

[Arduino Kütüphanesi Nasıl İndirilir](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Kumanda Kolu
Bu Arduino kütüphanesi Deneyap Kumanda Kolunun I2C çevre birimi ile kullanılmasını sağlar. Arduino ile uyumlu, I2C çevre birimine sahip herhangi bir geliştirme kartı ile bu kütüphaneyi projelerinizde kullanabilirsiniz.

## :globe_with_meridians:Repo İçeriği
- `/docs` README_tr.md ve ürün fotoğrafları
- `/examples` .ino uzantılı örnek uygulamalar
- `/src` kütüphane için .cpp ve .h uzantılı dosyalar
- `keywords.txt` Arduino IDE'de vurgulanacak anahtar kelimeler
- `library.properties` Arduino yöneticisi için genel kütüphane özellikleri

## Sürüm Geçmişi
1.0.0 - ilk sürüm

## :rocket:Donanım Bağlantıları
- Deneyap Kumanda Kolu ile kullanılan geliştirme kartı I2C kablosu ile bağlanabilir
- veya jumper kablolar ile 3V3, GND, SDA ve SCL bağlantıları yapılabilir.

|Kumanda Kolu | Fonksiyon	| Kart pinleri | 
| :---        | :---      	 |   :---  |
| 3.3V        | Güç   		| 3.3V      | 
| GND         | Toprak  	| GND       | 
| SDA         | I2C Data 	 | SDA pini | 
| SCL         | I2C Clock 	| SCL pini | 
| SWIM		  | Debug 		| bağlantı yok | 
| RES 		  | Debug 		| bağlantı yok | 
| X           | X Ekseni 	|herhangi bir Analog pini|
| Y 		  | Y Ekseni 	|herhangi bir Analog pini|
| SW 		  | Buton 	|herhangi bir GPIO pini|
| NC 		  | bağlantı yok	| |

## Lisans Bilgisi 
Lisans bilgileri için [LICENSE](https://github.com/deneyapkart/deneyap-kumanda-kolu-arduino-library/blob/master/LICENSE) dosyasını inceleyin.