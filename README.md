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
Pompadan Suyu Aktaracak Hortum (Ben 8mm kullandım.) 

su depolayacah herhangi bir şey (Şişe vs kullanabilirsiniz)

2 Adet Prob (Jumper kablo da kullanılabilir)

5 ila 12 volt Güç Adaptörü

Opsiyonel
- 10k direnç( Bu okumalarda işinizi cok daha kolaylastıracak yapılmasını şiddetle tavsiye ederim.)

- Buzzer  (Hata ve çalışma bildirimi için)


## 🔌 Bağlantı Şeması (Wiring Guide)
Kablolamayı yaparken aşağıdaki rehberi takip edebilirsiniz:

### 1. Toprak Prob Bağlantısı
Sensör modülü kullanılmadığı durumlarda iki adet kabloyu toprağa batırarak ölçüm yapıyoruz:

Kablo 1 (Güç): Arduino Pin 4'e bağlanır (Sadece ölçüm anında pozitif (+) enerji verir).

Kablo 2 (Okuma): Arduino A0 pinine bağlanır (Toprak direncini ölçer).

Not: A0 pinine giden kablo ile GND arasına 10K Ohm bir direnç eklemek okumayı stabilize eder (Pull-down).

 ### 2. L298N Motor Sürücü Bağlantısı
12V Girişi: Arduino'nun 5V pinine bağlanır (Motorumuz 6V olduğu için 5V güç yeterli olacaktır. )
Not: Eğer daha güçlü bir motor kullanacaksanız, motor sürücü ile Arduino'nun GND hatlarının ortak olduğundan emin olun.

GND Girişi: Arduino'nun GND pinine bağlanır.

IN1: Arduino Pin 12'ye bağlanır.

OUT1 & OUT2: 6V Mini Dalgıç Pompa'nın uçlarına bağlanır.

### 3. Bildirim Sistemi
Dahili LED: Arduino üzerindeki led Pin 13 kullanır.

Harici Bildirim: Ekstra bir LED veya buzzer takmak isterseniz, bu bileşeni Pin 13 ve GND arasına bağlayabilirsiniz.

# 💻 Kurulum ve Kullanım
Arduino IDE'yi açın.

Paylaşılan güncel kodu kopyalayıp yapıştırın.

esikDegeri değişkenini kendi toprağınızın kuruluğuna göre (0-1023 arası) test ederek güncelleyin.

Kodu Arduino'nuza yükleyin ve Seri Port Ekranı'nı (9600 baud) açarak sistemi izleyin.

### Örnek Görsel
---------------



<img width="527" height="689" alt="image" src="https://github.com/user-attachments/assets/b2e45b73-0872-40c6-97e2-673cb8fb9e11" />



 ## ⚠️ Önemli Uyarılar

###  Önemli Güvenlik Uyarısı: Sifon Etkisini Önleme
Hortum Yerleşimi Hakkında Kritik Not: Sulama yapacağınız hortumun (su çıkış ucunun), su kaynağındaki (su kovası/deposu) su seviyesinden mutlaka daha yukarıda olduğundan emin olun.

Neden? Eğer hortumun ucu su seviyesinden aşağıda kalırsa, pompa durduğunda bile "sifon etkisi" nedeniyle su kendiliğinden akmaya devam eder. Bu durum, su deponuzun tamamen boşalmasına ve bitkinizin saksısının suyla dolup taşmasına (su baskınına) neden olabilir.

Çözüm: Hortumun bitkiye su damlatan ucunu, su kaynağındaki en yüksek su seviyesinden daha yüksek bir noktaya sabitleyin.
----------------------------------------------------------------------------

 
Güç Kaynağı: Eğer pompanız çalışırken Arduino'yu resetliyorsa, L298N'e harici bir 6V-9V pil/adaptör bağlamanız gerekebilir. Bu durumda Arduino ve harici güç kaynağının GND uçlarını mutlaka birleştirin (Common Ground).
-----------------------------------------------------

Kablo Uçları: Toprağa batırdığınız kabloların uçlarını biraz açın ve birbirlerine değmediklerinden emin olun
