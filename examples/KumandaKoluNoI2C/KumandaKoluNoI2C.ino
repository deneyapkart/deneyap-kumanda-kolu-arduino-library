/*
 *   I2C haberleşme protokolü kullanılmadan Kumanda Kolu örneği,
 *
 *   Komanda kolunun X değeri, Y değeri ve buton durumu seri monitöre yazdırmaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır. 
 *   Bu örnek I2C haberleşme protokolü kullanılmadan yazılmıştır. 
 *
 *   Bu örnek Deneyap Kumanda Kolu için oluşturulmuştur
 *      ------>  www.....com <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-kumanda-kolu-arduino-library  <------ 
 *
*/
#define Xdegeri A0
#define Ydegeri A1
#define Buton D0

void setup() {  
    Serial.begin(115200);                          // Seri haberleşme başlatılması     
}

void loop() {
    bool butonDurumu = digitalRead(Buton);         // Buton durumu okundu
    Serial.print("Buton Durumu: ");
    Serial.print(butonDurumu);                     // Buton durumu seri monitöre yazıldı

    int XeksenDurumu = analogRead(Xdegeri);        // X eksen verisi okundu
    Serial.print("\t X Eksen Verisi: ");
    Serial.print(XeksenDurumu);                    // X eksen verisi seri monitöre yazıldı

    int YeksenDurumu = analogRead(Ydegeri);        // Y eksen verisi okundu
    Serial.print("\t Y Eksen Verisi: ");
    Serial.println(YeksenDurumu);                  // Y eksen verisi seri monitöre yazıldı

    delay(100);
}
