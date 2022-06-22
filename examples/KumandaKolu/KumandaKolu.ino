/*
 *   Kumanda Kolu örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Komanda kolunun X değeri, Y değeri ve buton durumu seri monitöre yazdırmaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır. 
 *
 *   Bu örnek Deneyap Kumanda Kolu için oluşturulmuştur
 *      ------>  www.....com <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-kumanda-kolu-arduino-library  <------ 
 *
*/
#include <Deneyap_KumandaKolu.h>                    // Deneyap_KumandaKolu.h kütüphanesi eklenmesi

Joystick KumandaKolu;                               // Kumanda kolu icin Class tanimlamasi

void setup() {  
    Serial.begin(115200);                           // Seri haberleşme başlatılması     
    if(!KumandaKolu.begin(0x1A)){                   // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatıldı
       delay(3000);
       Serial.println("I2C bağlantısı başarısız "); // I2C bağlantısı başarısız olursa seri terminale yazdırıldı
       while(1);
    }
}

void loop() {
    bool swState = KumandaKolu.swRead();           // Buton durumu okundu
    Serial.print("Buton Durumu: ");
    Serial.print(swState);                         // Buton durumu seri monitöre yazıldı

    uint16_t xValue = KumandaKolu.xRead();         // X eksen verisi okundu
    Serial.print("\t X Eksen Verisi: ");
    Serial.print(xValue);                          // X eksen verisi seri monitöre yazıldı

    uint16_t yValue = KumandaKolu.yRead();         // Y eksen verisi okundu
    Serial.print("\tY Eksen Verisi: ");
    Serial.println(yValue);                        // Y eksen verisi seri monitöre yazıldı

    delay(100);
}
