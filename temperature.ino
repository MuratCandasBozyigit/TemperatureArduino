#include <DHT.h>
#include <Tone.h>

#define DHTPIN 2           // DHT11 DATA pinini Arduino'nun dijital pin 2'ye bağladık
#define DHTTYPE DHT11       // Kullanılan sensör tipi (DHT11)

#define BUZZER_PIN 13
int buzzerFrequency = 100; // Daha tok bir ses için frekans (Hz)
bool buzzerActive = false;
// LED Pin Tanımlamaları
#define LED_Mavi_1 12
#define LED_Mavi_2 11
#define LED_Beyaz_1 10
#define LED_Beyaz_2 9
#define LED_Yesil_1 8
#define LED_Yesil_2 7
#define LED_Sari_1 6
#define LED_Sari_2 5
#define LED_Kirmizi_1 4
#define LED_Kirmizi_2 3

DHT dht(DHTPIN, DHTTYPE); // DHT sensörünü başlatıyoruz
bool buzzerCaldiMi = false;
void setup() {
  // Seri iletişimi başlatıyoruz
  Serial.begin(9600);
  dht.begin();  // DHT sensörünü başlatıyoruz
  //Buzzer
  pinMode(BUZZER_PIN, OUTPUT);
  // LED pinlerini çıkış olarak ayarlıyoruz
  pinMode(LED_Mavi_1, OUTPUT);
  pinMode(LED_Mavi_2, OUTPUT);
  pinMode(LED_Beyaz_1, OUTPUT);
  pinMode(LED_Beyaz_2, OUTPUT);
  pinMode(LED_Yesil_1, OUTPUT);
  pinMode(LED_Yesil_2, OUTPUT);
  pinMode(LED_Sari_1, OUTPUT);
  pinMode(LED_Sari_2, OUTPUT);
  pinMode(LED_Kirmizi_1, OUTPUT);
  pinMode(LED_Kirmizi_2, OUTPUT);

  // Başlangıç mesajı
  Serial.println("Sıcaklık ve Nem Ölçüm Uygulaması Başlatıldı!");
}

void loop() {
  // Sensörden sıcaklık ve nem değerlerini alıyoruz
  float h = dht.readHumidity();    // Nem değeri
  float t = dht.readTemperature(); // Sıcaklık değeri (Celsius)

  // Okuma başarısız olursa hata mesajı yazdırıyoruz
  if (isnan(h) || isnan(t)) {
    Serial.println("DHT11 sensörü okunamadı!");
    return;
  }

  // Sıcaklık ve nem değerlerini seri port üzerinden yazdırıyoruz
  Serial.println("=========================");
  Serial.print("Alınan Sıcaklık: ");
  Serial.print(t);
  Serial.println(" *C");
  Serial.print("Alınan Nem: ");
  Serial.print(h);
  Serial.println(" %");
  Serial.println("=========================");

  // Tüm LED'leri kapatıyoruz
  turnOffLEDs();

  // LED'leri kontrol ediyoruz
  if (t >= 0 && t < 2.5) {
    digitalWrite(LED_Mavi_2, LOW);
    digitalWrite(LED_Beyaz_1, LOW);
    digitalWrite(LED_Beyaz_2, LOW);
    digitalWrite(LED_Yesil_1, LOW);
    digitalWrite(LED_Yesil_2, LOW);
    digitalWrite(LED_Sari_1, LOW);
    digitalWrite(LED_Sari_2, LOW);
    digitalWrite(LED_Kirmizi_1, LOW);
    digitalWrite(LED_Kirmizi_2, LOW);
    digitalWrite(LED_Mavi_1, HIGH);
     digitalWrite(BUZZER_PIN, HIGH); // Buzzer'ı çalıştır
    delay(500);                     // 500ms boyunca buzzer açık
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer'ı kapat
    buzzerCaldiMi = true;           // Bayrağı işaretle
    Serial.println("Buzzer bir kere çaldı!");
     buzzerCaldiMi = false;   
    Serial.println("LED Durumu: Mavi 1 Yandı");
  }
  else if (t >= 2.5 && t < 5) {
    digitalWrite(LED_Mavi_1, LOW);
    digitalWrite(LED_Beyaz_1, LOW);
    digitalWrite(LED_Beyaz_2, LOW);
    digitalWrite(LED_Yesil_1, LOW);
    digitalWrite(LED_Yesil_2, LOW);
    digitalWrite(LED_Sari_1, LOW);
    digitalWrite(LED_Sari_2, LOW);
    digitalWrite(LED_Kirmizi_1, LOW);
    digitalWrite(LED_Kirmizi_2, LOW);
    digitalWrite(LED_Mavi_2, HIGH); digitalWrite(BUZZER_PIN, HIGH); // Buzzer'ı çalıştır
    delay(500);                     // 500ms boyunca buzzer açık
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer'ı kapat
    buzzerCaldiMi = true;           // Bayrağı işaretle
    Serial.println("Buzzer bir kere çaldı!");
    Serial.println("LED Durumu: Mavi 2 Yandı");
  }
  else if (t >= 5 && t < 7.5) {
    digitalWrite(LED_Beyaz_1, LOW);
    digitalWrite(LED_Beyaz_2, LOW);
    digitalWrite(LED_Yesil_1, LOW);
    digitalWrite(LED_Yesil_2, LOW);
    digitalWrite(LED_Sari_1, LOW);
    digitalWrite(LED_Sari_2, LOW);
    digitalWrite(LED_Kirmizi_1, LOW);
    digitalWrite(LED_Kirmizi_2, LOW);
    digitalWrite(LED_Mavi_1, HIGH);
    digitalWrite(LED_Mavi_2, HIGH); digitalWrite(BUZZER_PIN, HIGH); // Buzzer'ı çalıştır
    delay(500);                     // 500ms boyunca buzzer açık
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer'ı kapat
    buzzerCaldiMi = true;           // Bayrağı işaretle
    Serial.println("Buzzer bir kere çaldı!");
    Serial.println("LED Durumu: Mavi 1 ve Mavi 2 Yandı");
  }
  else if (t >= 7.5 && t < 10) {
    digitalWrite(LED_Mavi_1, LOW);
    digitalWrite(LED_Mavi_2, LOW);
    digitalWrite(LED_Beyaz_2, LOW);
    digitalWrite(LED_Yesil_1, LOW);
    digitalWrite(LED_Yesil_2, LOW);
    digitalWrite(LED_Sari_1, LOW);
    digitalWrite(LED_Sari_2, LOW);
    digitalWrite(LED_Kirmizi_1, LOW);
    digitalWrite(LED_Kirmizi_2, LOW);
    digitalWrite(LED_Beyaz_1, HIGH); digitalWrite(BUZZER_PIN, HIGH); // Buzzer'ı çalıştır
    delay(500);                     // 500ms boyunca buzzer açık
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer'ı kapat
    buzzerCaldiMi = true;           // Bayrağı işaretle
    Serial.println("Buzzer bir kere çaldı!");
    Serial.println("LED Durumu: Beyaz 1 Yandı");
  }
  else if (t >= 10 && t < 12.5) {
    digitalWrite(LED_Mavi_1, LOW);
    digitalWrite(LED_Mavi_2, LOW);
    digitalWrite(LED_Beyaz_1, LOW);
    digitalWrite(LED_Yesil_1, LOW);
    digitalWrite(LED_Yesil_2, LOW);
    digitalWrite(LED_Sari_1, LOW);
    digitalWrite(LED_Sari_2, LOW);
    digitalWrite(LED_Kirmizi_1, LOW);
    digitalWrite(LED_Kirmizi_2, LOW);
    digitalWrite(LED_Beyaz_2, HIGH); digitalWrite(BUZZER_PIN, HIGH); // Buzzer'ı çalıştır
    delay(500);                     // 500ms boyunca buzzer açık
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer'ı kapat
    buzzerCaldiMi = true;           // Bayrağı işaretle
    Serial.println("Buzzer bir kere çaldı!");
    Serial.println("LED Durumu: Beyaz 2 Yandı");
  }
  else if (t >= 12.5 && t < 15) {
     digitalWrite(LED_Mavi_1, LOW);
    digitalWrite(LED_Mavi_2, LOW);
    digitalWrite(LED_Yesil_1, LOW);
    digitalWrite(LED_Yesil_2, LOW);
    digitalWrite(LED_Sari_1, LOW);
    digitalWrite(LED_Sari_2, LOW);
    digitalWrite(LED_Kirmizi_1, LOW);
    digitalWrite(LED_Kirmizi_2, LOW);
    digitalWrite(LED_Beyaz_1, HIGH);
    digitalWrite(LED_Beyaz_2, HIGH); digitalWrite(BUZZER_PIN, HIGH); // Buzzer'ı çalıştır
    delay(500);                     // 500ms boyunca buzzer açık
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer'ı kapat
    buzzerCaldiMi = true;           // Bayrağı işaretle
    Serial.println("Buzzer bir kere çaldı!");
    Serial.println("LED Durumu: Beyaz 1 ve Beyaz 2 Yandı");
  }
  else if (t >= 15 && t < 17.5) {
     digitalWrite(LED_Mavi_1, LOW);
    digitalWrite(LED_Mavi_2, LOW);
    digitalWrite(LED_Beyaz_1, LOW);
    digitalWrite(LED_Beyaz_2, LOW);
    digitalWrite(LED_Yesil_2, LOW);
    digitalWrite(LED_Sari_1, LOW);
    digitalWrite(LED_Sari_2, LOW);
    digitalWrite(LED_Kirmizi_1, LOW);
    digitalWrite(LED_Kirmizi_2, LOW);
    digitalWrite(LED_Yesil_1, HIGH); digitalWrite(BUZZER_PIN, HIGH); // Buzzer'ı çalıştır
    delay(500);                     // 500ms boyunca buzzer açık
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer'ı kapat
    buzzerCaldiMi = true;           // Bayrağı işaretle
    Serial.println("Buzzer bir kere çaldı!");
    Serial.println("LED Durumu: Yeşil 1 Yandı");
  }
  else if (t >= 17.5 && t < 25) {
     digitalWrite(LED_Mavi_1, LOW);
      digitalWrite(LED_Mavi_2, LOW);
      digitalWrite(LED_Beyaz_1, LOW);
      digitalWrite(LED_Beyaz_2, LOW);
      digitalWrite(LED_Yesil_1, LOW);

      digitalWrite(LED_Sari_1, LOW);
      digitalWrite(LED_Sari_2, LOW);
      digitalWrite(LED_Kirmizi_1, LOW);
      digitalWrite(LED_Kirmizi_2, LOW);
    digitalWrite(LED_Yesil_2, HIGH); digitalWrite(BUZZER_PIN, HIGH); // Buzzer'ı çalıştır
    delay(500);                     // 500ms boyunca buzzer açık
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer'ı kapat
    buzzerCaldiMi = true;           // Bayrağı işaretle
    Serial.println("Buzzer bir kere çaldı!");
    Serial.println("LED Durumu: Yeşil 2 Yandı");
  }
  else if (t >= 25 && t< 27.5) {
     digitalWrite(LED_Mavi_1, LOW);
      digitalWrite(LED_Mavi_2, LOW);
      digitalWrite(LED_Beyaz_1, LOW);
      digitalWrite(LED_Beyaz_2, LOW);
      digitalWrite(LED_Yesil_1, HIGH);
      digitalWrite(LED_Yesil_2, HIGH);
      digitalWrite(LED_Sari_1, LOW);
      digitalWrite(LED_Sari_2, LOW);
    digitalWrite(LED_Kirmizi_1, LOW);
      digitalWrite(LED_Kirmizi_2, LOW);
     digitalWrite(BUZZER_PIN, HIGH); // Buzzer'ı çalıştır
    delay(500);                     // 500ms boyunca buzzer açık
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer'ı kapat
   buzzerCaldiMi = true;           // Bayrağı işaretle
    Serial.println("Buzzer bir kere çaldı!");
     buzzerCaldiMi = false;            // Bayrağı işaretle
    Serial.println("LED Durumu:Yeşil1  ve Yeşil 2 Yandı");
  }
    else if (t >= 27.5 && t < 30) {
      digitalWrite(LED_Mavi_1, LOW);
    digitalWrite(LED_Mavi_2, LOW);
    digitalWrite(LED_Beyaz_1, LOW);
    digitalWrite(LED_Beyaz_2, LOW);
    digitalWrite(LED_Yesil_1, LOW);
    digitalWrite(LED_Yesil_2, LOW);
    digitalWrite(LED_Sari_1, LOW);
    digitalWrite(LED_Sari_2, LOW);
    digitalWrite(LED_Kirmizi_1, HIGH);
    digitalWrite(LED_Kirmizi_2, LOW); digitalWrite(BUZZER_PIN, HIGH); // Buzzer'ı çalıştır
    delay(500);                     // 500ms boyunca buzzer açık
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer'ı kapat
    buzzerCaldiMi = true;           // Bayrağı işaretle
    Serial.println("Buzzer bir kere çaldı!");
    Serial.println("LED Durumu:Kırmızı 1 Yandı");
  }
    else if (t >= 30 && t< 32.5) {
      digitalWrite(LED_Mavi_1, LOW);
      digitalWrite(LED_Mavi_2, LOW);
      digitalWrite(LED_Beyaz_1, LOW);
      digitalWrite(LED_Beyaz_2, LOW);
      digitalWrite(LED_Yesil_1, LOW);
      digitalWrite(LED_Yesil_2, LOW);
      digitalWrite(LED_Sari_1, LOW);
      digitalWrite(LED_Sari_2, LOW);
      digitalWrite(LED_Kirmizi_1, LOW);
      digitalWrite(LED_Kirmizi_2, HIGH); digitalWrite(BUZZER_PIN, HIGH); // Buzzer'ı çalıştır
    delay(500);                     // 500ms boyunca buzzer açık
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer'ı kapat
    buzzerCaldiMi = true;           // Bayrağı işaretle
    Serial.println("Buzzer bir kere çaldı!");
      Serial.println("LED Durumu:Kırmızı 2 Yandı");
  }
   else if (t >= 32.5 ) {
      digitalWrite(LED_Mavi_1, LOW);
      digitalWrite(LED_Mavi_2, LOW);
      digitalWrite(LED_Beyaz_1, LOW);
      digitalWrite(LED_Beyaz_2, LOW);
      digitalWrite(LED_Yesil_1, LOW);
      digitalWrite(LED_Yesil_2, LOW);
      digitalWrite(LED_Sari_1, LOW);
      digitalWrite(LED_Sari_2, LOW);
      digitalWrite(LED_Kirmizi_1, HIGH);
      digitalWrite(LED_Kirmizi_2, HIGH); digitalWrite(BUZZER_PIN, HIGH); // Buzzer'ı çalıştır
    delay(500);                     // 500ms boyunca buzzer açık
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer'ı kapat
    buzzerCaldiMi = true;           // Bayrağı işaretle
    Serial.println("Buzzer bir kere çaldı!");
      Serial.println("LED Durumu:Kırmızı 1 ve Kırmızı 2 Yandı");
  }

  delay(2000);  // 2 saniye bekleyerek döngüyü tekrar başlatıyoruz
}

void turnOffLEDs() {
  // Tüm LED'leri kapatıyoruz
  digitalWrite(LED_Mavi_1, LOW);
  digitalWrite(LED_Mavi_2, LOW);
  digitalWrite(LED_Beyaz_1, LOW);
  digitalWrite(LED_Beyaz_2, LOW);
  digitalWrite(LED_Yesil_1, LOW);
  digitalWrite(LED_Yesil_2, LOW);
  digitalWrite(LED_Sari_1, LOW);
  digitalWrite(LED_Sari_2, LOW);
  digitalWrite(LED_Kirmizi_1, LOW);
  digitalWrite(LED_Kirmizi_2, LOW);
}
