/* * Akıllı Sulama Sistemi
 * Bu kod, toprağın nemini ölçer, gerekirse sular ve olası suyun bitme ihtimaline karşı sistemi kilitler.
 */

// --- PİN TANIMLAMALARI ---
const int sensorGucPin = 4; // Sensörün VCC (+) ucuna bağlanır (Oksitlenmeyi önlemek için) 
const int sensorPin = A0;   // Sensörün Sinyal (S) ucuna bağlanır
// 4 ve A0 arasında herhangi iki kabloyu da kullanabilirsınız ama pek tavsiye edilmez.
const int motorPin = 12;    // Röle veya Motor Sürücü girişi
const int ledPin = 13;      // Durum LED'i (Arduino üzerindeki dahili LED)

// --- AYARLAR VE EŞİK DEĞERLERİ ---
int esikDegeri = 900;       // Kuru toprak değeri (Deneyerek optimize edilmelidir: 0-1023)
const int maxDeneme = 5;    // Kaç başarısız sulamadan sonra sistem kilitlensin?

int hataSayaci = 0;         
bool sistemKilitli = false;


void setup() {
  pinMode(sensorGucPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  // Başlangıçta her şeyi kapalı tutulur
  digitalWrite(sensorGucPin, LOW); 
  digitalWrite(motorPin, LOW);
  
  Serial.begin(9600);
  Serial.println("Motor Surucu ve LED Uyari Sistemi Hazir.");
}

void loop() {
  // --- HATA DURUMU (SİSTEM KİLİTLİ) ---
  if (sistemKilitli) {
    Serial.println("!!! HATA: Su bitmis olabilir. Sistem kilitlendi!");
    // Hata uyarısı: LED çok hızlı yanıp söner
    digitalWrite(ledPin, HIGH); delay(100);
    digitalWrite(ledPin, LOW);  delay(100);
    return; 
  }

  // --- ÖLÇÜM AŞAMASI ---
  digitalWrite(sensorGucPin, HIGH); 
  delay(50);                        
  sensorDegeri = analogRead(sensorPin); 
  digitalWrite(sensorGucPin, LOW);  // Korozyonu önlemek için gücü kes

  Serial.print("Nem Degeri: ");
  Serial.println(sensorDegeri);

  // --- KARAR MEKANİZMASI --- // kablo yerine sensor kullanılıyorsa < işaretinin > işareti ile değiştirilmesi gerekebilir
  if (sensorDegeri < esikDegeri) {
    hataSayaci++; 
    Serial.print("Toprak Kuru! Deneme: ");
   Serial.println(hataSayaci);

    if (hataSayaci >= maxDeneme) {
      sistemKilitli = true; 
      digitalWrite(motorPin, LOW); // Güvenlik için motoru kapat
    } else {
      // SULAMA BAŞLAT
      Serial.println("Pompa Calisiyor...");
      digitalWrite(ledPin, HIGH);   // Sulama yaparken LED sabit yanar // buzer takacaksanız burayı devre dısı birakmak isteyebilirsiniz
      digitalWrite(motorPin, HIGH); 
      delay(5000);                  // 5 saniye su ver
      
      digitalWrite(motorPin, LOW);  
      digitalWrite(ledPin, LOW);
      Serial.println("Sulama durdu, emilme bekleniyor...");
      delay(15000);                 // 15 saniye  ektra bekle su emilsin
    }
  } 
  else {
    // Toprak ıslaksa her şey yolunda
    hataSayaci = 0; 
    Serial.println("Toprak nemli, bekleme moduna geciliyor.");
    
    // Normal çalışma uyarısı: LED bir kez kısa yanıp söner
    digitalWrite(ledPin, HIGH); delay(200); digitalWrite(ledPin, LOW); // buzer takacaksanız burayı devre dısı birakmak isteyebilirsiniz
  }

  // 30 saniye ana bekleme
  if (!sistemKilitli) {
    delay(60000); 
  }
}