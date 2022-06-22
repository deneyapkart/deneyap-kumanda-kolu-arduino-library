/*
 *   Kumanda Kolu örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   4 tane Kumanda kollarından X değerleri, Y değerleri ve buton durumlarını seri monitöre yazdırmaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır. 
 *
 *   Bu örnek Deneyap Kumanda Kolu için oluşturulmuştur
 *      ------>  www.....com <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-kumanda-kolu-arduino-library  <------ 
 *
*/
#include <Deneyap_KumandaKolu.h>                    // Deneyap_KumandaKolu.h kütüphanesi eklenmesi

Joystick KumandaKolu1;                              // 1. Kumanda kolu icin Class tanimlamasi
Joystick KumandaKolu2;                              // 2. Kumanda kolu icin Class tanimlamasi
Joystick KumandaKolu3;                              // 3. Kumanda kolu icin Class tanimlamasi
Joystick KumandaKolu4;                              // 4. Kumanda kolu icin Class tanimlamasi

void setup() {  
    Serial.begin(115200);                           // Seri haberleşme başlatılması 
    KumandaKolu2.begin(0x1A);    
    KumandaKolu1.begin(0x1B);                       // ADR1 kısa devre yapıldığındaki adres 0x1B
    KumandaKolu3.begin(0x1C);                       // ADR2 kısa devre yapıldığındaki adres 0x1C
    KumandaKolu4.begin(0x1D);                       // ADR1 ve ADR2 kısa devre yapıldığındaki adres 0x1D
}

void loop() {
    bool swState1 = KumandaKolu1.swRead();           // 1. Buton durumu  okunması
    Serial.print("1. Buton Durumu: ");
    Serial.print(swState1);                          // 1. Buton durumu seri monitöre yazılması

    uint16_t xValue1 = KumandaKolu1.xRead();         // 1. X eksen verisinin okunması
    Serial.print("\t1.X Eksen Verisi: ");
    Serial.print(xValue1);                           // 1. X eksen verisi seri monitöre yazılması

    uint16_t yValue1 = KumandaKolu1.yRead();         // 1. Y eksen verisinin okunması
    Serial.print("\t1. Y Eksen Verisi: ");
    Serial.println(yValue1);                         // 1. Y eksen verisi seri monitöre yazılması

    delay(10);
    
    bool swState2 = KumandaKolu2.swRead();
    Serial.print("2. Buton Durumu: ");
    Serial.print(swState2);

    uint16_t xValue2 = KumandaKolu2.xRead();
    Serial.print("\t2.X Eksen Verisi: ");
    Serial.print(xValue2);

    uint16_t yValue2 = KumandaKolu2.yRead();
    Serial.print("\t2. Y Eksen Verisi: ");
    Serial.println(yValue2);

    delay(10);
    
    bool swState3 = KumandaKolu3.swRead();
    Serial.print("3. Buton Durumu: ");
    Serial.print(swState3);

    uint16_t xValue3 = KumandaKolu3.xRead();
    Serial.print("\t3.X Eksen Verisi: ");
    Serial.print(xValue3);

    uint16_t yValue3 = KumandaKolu3.yRead();
    Serial.print("\t3. Y Eksen Verisi: ");
    Serial.println(yValue3);

    delay(10);
    
    bool swState4 = KumandaKolu4.swRead();
    Serial.print("4. Buton Durumu: ");
    Serial.print(swState4);

    uint16_t xValue4 = KumandaKolu4.xRead();
    Serial.print("\t4.X Eksen Verisi: ");
    Serial.print(xValue4);

    uint16_t yValue4 = KumandaKolu4.yRead();
    Serial.print("\t4. Y Eksen Verisi: ");
    Serial.println(yValue4);

    delay(100);
}
