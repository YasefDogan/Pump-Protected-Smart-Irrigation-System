# Smart Irrigation System
Bu proje, toprak nemini iki basit kablo (prob) aracılığıyla ölçen, bitkilerinizi otomatik sulayan ve su kaynağı tükendiğinde pompayı korumaya alan akıllı bir Arduino sistemidir.

## Öne Çıkan Özellikler
Korozyon Önleyici Sistem: Sensör kablolarına sadece ölçüm anında güç vererek metal aşınmasını (oksitlenmeyi) minimize eder.

Fail-Safe (Güvenlik Kilidi): Eğer sistem 5 kez sulama yapmasına rağmen toprak hala kuruysa, suyun bittiğini algılar ve motorun yanmasını önlemek için sistemi kilitler.

L298N Entegrasyonu: Güçlü motor sürücü ile 6V mini dalgıç pompayı güvenle çalıştırır.

 ## 🛠 Donanım Bileşenleri
Arduino Uno

L298N Motor Sürücü Modülü

6V Mini Dalgıç Su Pompası

2 Adet Prob (Jumper kablo da kullanılabilir)

Buzzer veya LED (Hata ve çalışma bildirimi için)

## 🔌 Bağlantı Şeması (Wiring Guide)
Kablolamayı yaparken aşağıdaki rehberi takip edebilirsiniz:

### 1. Toprak Prob Bağlantısı
Sensör modülü kullanılmadığı durumlarda iki adet kabloyu toprağa batırarak ölçüm yapıyoruz:

Kablo 1 (Güç): Arduino Pin 4'e bağlanır (Sadece ölçüm anında pozitif (+) enerji verir).

Kablo 2 (Okuma): Arduino A0 pinine bağlanır (Toprak direncini ölçer).

Not: A0 pinine giden kablo ile GND arasına 10K Ohm bir direnç eklemek okumayı stabilize eder (Pull-down).

 ### 2. L298N Motor Sürücü Bağlantısı
12V Girişi: Arduino'nun 5V pinine bağlanır (Motorumuz 6V olduğu için 5V güç yeterli olacaktır. Eğer daha güçlü bir motor kullanacaksanız, motor sürücü ile Arduino'nun GND hatlarının ortak olduğundan emin olun).

GND Girişi: Arduino'nun GND pinine bağlanır.

IN1: Arduino Pin 12'ye bağlanır.

OUT1 & OUT2: 6V Mini Dalgıç Pompa'nın uçlarına bağlanır.

### 3. Bildirim Sistemi
Dahili LED: Arduino üzerindeki Pin 13 kullanılır.

Harici Bildirim: Ekstra bir LED veya buzzer takmak isterseniz, bu bileşeni Pin 13 ve GND arasına bağlayabilirsiniz.

# 💻 Kurulum ve Kullanım
Arduino IDE'yi açın.

Paylaşılan güncel kodu kopyalayıp yapıştırın.

esikDegeri değişkenini kendi toprağınızın kuruluğuna göre (0-1023 arası) test ederek güncelleyin.

Kodu Arduino'nuza yükleyin ve Seri Port Ekranı'nı (9600 baud) açarak sistemi izleyin.

 ## ⚠️ Önemli Uyarılar
Güç Kaynağı: Eğer pompanız çalışırken Arduino'yu resetliyorsa, L298N'e harici bir 6V-9V pil/adaptör bağlamanız gerekebilir. Bu durumda Arduino ve harici güç kaynağının GND uçlarını mutlaka birleştirin (Common Ground).

Kablo Uçları: Toprağa batırdığınız kabloların uçlarını biraz açın ve birbirlerine değmediklerinden emin olun
