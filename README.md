# **BOYER-MOORE ALGORİTMASI**

# 💻 Algoritma 

Boyer-Moore algoritması metin içindeki bir **deseni** (pattern, string) aramak için kullanılan verimli bir **arama** algoritmasıdır. 1977 yılında Robert S. Boyer ve J. Strother Moore tarafından büyük metinlerde 
arama işlemlerini **daha hızlı** yapabilmek için geliştirilmiştir. Sağdan sola doğru karakter karşılaştırması yapar ve eşleşme bulamadığında, **"bad character"** ve **"good suffix"** gibi sezgisel kurallar sayesinde desenin tamamını değil sadece gerekli kısmını kaydırarak işlem yapar.

# 📂 Kategori

* **Ana Kategori:**  
    
    * String Matching Algorithms (Dize Arama Algoritmaları)

* **Alt Alanlar:** 
   
    * Text Processing (Metin İşleme)

    * Heuristic Algorithms (Sezgisel Algoritmalar)

    * Pattern Matching (Desen Arama)

    * Search Algorithms (Arama Algoritmaları)

    * String Algorithms (Karakter Dizisi Algoritmaları)


# 🧠  Çözüm Yaklaşımı: 

Boyer-Moore algoritması, arama sürecinde gereksiz karşılaştırmaları azaltmak için iki temel sezgisel (heuristic) yaklaşım kullanır:

1. **Bad Character Heuristiği (Kötü Karakter Kuralı):** 
    
    Uyuşmazlık yaşanan karakter, desen içinde yer alıyorsa, desen bu karakterin son göründüğü konuma göre kaydırılır. Eğer karakter desende yoksa, desen tümüyle atlanır.

2. **Good Suffix Heuristiği (İyi Sonek Kuralı):**

    Desenin sağ tarafında eşleşen bir alt dizin (suffix) varsa, bu parçanın metin içindeki olası diğer eşleşmeleri kontrol edilir. Eşleşme bulunamazsa, desenin benzer yapısına göre kaydırma yapılır.

3. **Sağdan Sola Karşılaştırma:**

    Desen, metinle klasik algoritmalardan farklı olarak sağdan sola karşılaştırılır. Bu yöntem, uyuşmazlık durumlarında daha uzun kaydırmalar yapmayı mümkün kılar. Uyuşmazlıkları avantaja çevirerek daha az karşılaştırmayla daha hızlı arama yapar.

# ❓ Ne Zaman ve Neden Kullanılır?

### Ne zaman kullanılır?

1. **Metin çok uzunsa:**

    Arama yapılacak metin binlerce ya da milyonlarca karakter içeriyorsa Boyer-Moore diğer yöntemlerden çok daha hızlı çalışır.

2. **Aranan desen orta veya uzun boyuttaysa yani küçük değilse:**

    Aranacak desenin uzunluğu arttıkça algoritmanın sağladığı atlama avantajı daha belirgin hale gelir. 3 karakterlik desen yerine 8–20 karakterlik desenlerde çok daha verimlidir.

3. **Sabit (aynı) bir desen birden çok defa aranacaksa:**

    Algoritma, arama öncesi bazı tabloları (bad character ve good suffix) önceden hesaplar. Eğer aynı desen birden fazla farklı metin içinde aranacaksa, bu tablolar tekrar kullanılabilir.

4. **Gerçek zamanlı yanıt gerekli değilse ama verim önemliyse:**

    Örneğin bir dosyada arka planda metin eşleşmesi yapmak gerekiyorsa, ön hazırlık aşamaları biraz zaman alsa da genel arama süresi kısa olur.

### Neden kullanılır?

1. **Performans açısından çok avantajlıdır:**

    Karakter karşılaştırmalarını sağdan sola yapar ve uyuşmazlık durumunda desenin büyük bölümlerini atlayarak ilerler. Bu sayede klasik algoritmalardan (Naive, KMP vb.) çok daha az işlem yapar.

2. **Kötü durumu nadiren yaşanır:**
    
    En kötü durum teorik olarak O(n·m) olsa da pratikte bu çok nadiren görülür. Gerçek dünya verilerinde genelde O(n) seviyesinde çalışır.

3. **Karakter kümesi büyükse etkisi artar:**
    
    Büyük bir karakter setine sahip dillerde daha fazla atlama yapabilir. Bu da algoritmanın hızını artırır.

4. **Yaygın destek ve optimizasyonları mevcuttur:**
    
    Çeşitli programlama dillerinde ve kütüphanelerde optimize edilmiş sürümleri vardır. Böylece güvenle kullanılabilir.


# ⏱ Zaman ve Uzay Karmaşıklığı 

| Durum         | Zaman Karmaşıklığı | Açıklama |
|---------------|---------------------|----------|
| En iyi durum  | O(n / m)            | Desende eşleşme yoksa büyük adımlarla kayar. |
| Ortalama durum | O(n)                | Uyuşmazlıklarda verimli kaydırmalar yapılır. |
| En kötü durum | O(n * m)            | Tüm karakterler karşılaştırılırsa. |
| Uzay karmaşıklığı | O(k)            | 'bad character' tablosu için (k: karakter kümesi büyüklüğü). |

* `n`: metin uzunluğu  
* `m`: desen (pattern,string) uzunluğu  
* `k`: karakter kümesi büyüklüğü 

# ✅ Avantajları

* Bad character ve good suffix heuristikleri sayesinde çok sayıda karakteri atlayabilir ve karakter atlamaları sayesinde oldukça hızlıdır.

* Ortalama durum performansı çok iyidir: genellikle O(n).

* Büyük metinlerde yüksek performans gösterir.

# ❌ Dezavantajları

* Ön işleme süreci karmaşıktır.

* Kısa desenlerde veya küçük metinlerde performans verimi düşebilir.

* En kötü durumda O(n·m) karmaşıklığına düşebilir.
 
# 🪜 Çalışma Adımları

1. **Ön İşlem (Hazırlık)**

    Aramaya başlamadan önce desen (yani aranan kelime) üzerinde iki tablo hazırlanır:

    **Bad Character Tablosu (Kötü Karakter):** Desende geçen her karakterin en son göründüğü indeks kaydedilir. Amacı metindeki uyuşmayan karaktere göre deseni uygun miktarda kaydırabilmektir.

     **Good Suffix Tablosu (İyi Sonek):** Desenin sonunda eşleşen kısmı kullanarak daha uzun kaydırmalar yapılmasını sağlar. İsteğe bağlıdır ve daha karmaşık bir yapıya sahiptir.

2. **Arama Başlat (Karşılaştırma)**
    
    Metin üzerinde desenin uzunluğu kadar bir pencere açılır. Karakterler sağdan sola doğru yani desenin en son karakterinden başlanarak karşılaştırma yapılır.

3. **Eşleşme Kontrolü**

    Eğer tüm karakterler eşleşirse eşleşme bulunmuştur, indeks döndürülür. Eğer eşleşme yoksa uyuşmazlık olan karaktere göre kaydırma miktarı hesaplanır. Kötü karakter kuralına göre desen uyuşmayan karakterin son görüldüğü yere kaydırılır. İyi sonek varsa daha uzun bir kaydırma mümkünse o uygulanır.

4. **Deseni Kaydır ve Devam Et**

    Desen, metin üzerinde ileri doğru kaydırılır ve 2. adıma dönülür. Bu işlem metin bitene kadar tekrarlanır. Eşleşme bulunduğunda eşleşme indeksi döndürülür. Metin bittiğinde hâlâ eşleşme yoksa “Desen bulunamadı.” sonucu döndürülür.

# 🧪 Örnek

Boyer-Moore algoritmasını daha iyi anlamak için kısa bir örnek yapalım. Bu örnekte, ***"boyermoore"*** metni içinde ***"moore"*** desenini arayacağız.

Metin (text): boyermoore, Desen (pattern): moore


* İlk olarak metni ve deseni sağdan sola karşılaştırıyoruz. 'boyermoore' metninde en sağdaki karakterle desenin sağdaki karakterini karşılaştırırız.

* İlk karşılaştırma: 'e' (desenin son karakteri) ile 'o' (metnin karşılık gelen karakteri). Bu iki karakter farklı olduğu için, algoritma kaydırma yapar.

* Bad character rule'a göre, desenin 'e' karakterinin bulunduğu yerde metinde uyuşmazlık olmuşsa, 'e' karakteri metinde yer alan son 'o' karakterine kadar kaydırılır.

* Sonuç olarak, desen 'moore' bulunduğu yerde metinde boyermoore'ün içinde, 5. indeks  konumunda yer alır.

# 👩🏻‍💻 Kullanım Alanları

1. ✍🏻 Metin Editörleri ve IDE'ler: Visual Studio Code, Sublime Text, Notepad++, IntelliJ IDEA vb. kullanıcının girdiği bir kelime ya da karakter dizisinin belgede hızlıca bulunması için kullanılır.

    Örnek: Bir programcı, kod dosyasında "main" kelimesini aradığında binlerce satır arasında saniyeler içinde eşleşme bulunur.

2. 🔎 Arama Motoru Arka Planı:
Google, Yandex, Bing gibi büyük arama sistemlerinin iç bileşenlerinde Web sayfaları veya metin belgeleri içinde sorgu kelimelerini hızlıca bulmak için kullanılır. 

    Örnek: Arama motorunun indekslediği milyarlarca belge arasında "boyer moore" geçen içerikleri bulmak.

3. 🧬 Biyoinformatik:
DNA/RNA dizileri üzerinde yapılan veri analizlerinde genetik sekanslar arasında belirli motiflerin veya genlerin aranmasında kullanılır.
    
    Örnek: Bir araştırmacı, DNA dizisinde "ATCGGTA" gibi bir nükleotid dizisini ararken.

4. 📝 Plagiarism Tespiti:
Turnitin, iThenticate gibi intihal tespit sistemlerinde bir metnin başka bir metinle ne kadar benzerlik taşıdığını hızlıca belirlemek için kullanılır
     
     Örnek: Bir öğrencinin ödevinde geçen cümlelerin daha önce yayınlanmış belgelerde geçip geçmediğini kontrol etmek için kullanılabilir.

5. 💬  Chatbot ve Mesajlaşma Uygulamaları:
WhatsApp, Telegram, Slack botları, müşteri hizmeti asistanlarında kullanıcının mesajında belirli anahtar kelimelerin bulunup, yanıtlanması için kullanılır.

    Örnek: Kullanıcı "sipariş durumu" yazdığında sistemin bu deseni fark edip "Sipariş takibi için lütfen numaranızı girin" demesi.

6. 🧾  Log Analizi ve Güvenlik Sistemleri:
SIEM sistemleri (Splunk, ELK stack)'nde log dosyalarında belirli hata mesajları, saldırı imzaları veya şüpheli aktiviteleri tespit etmekte kullanılır. 
    
    Örnek: Bir log dosyasında "unauthorized access" ifadesi arandığında, Boyer-Moore gibi hızlı arama algoritmaları kullanılır.

# 🔍 Kaynakça

* ŞEKER, Ş. E. (2009, Mayıs 19). *Boyer-Moore Dizgi Arama Algoritması (Boyer-Moore String Search).* Bilgisayar Kavramları. 
https://bilgisayarkavramlari.com/2009/05/19/boyer-moore-dizgi-arama-algoritmasi-boyer-moore-string-search/

* GeeksforGeeks. (n.d.). *Boyer Moore Algorithm for Pattern Searching. GeeksforGeeks.* Retrieved May 14, 2025, from https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/

* Wikipedia contributors. (n.d.). *Boyer–Moore string-search algorithm.* Wikipedia. Retrieved May 14, 2025, from https://en.m.wikipedia.org/wiki/Boyer%E2%80%93Moore_string-search_algorithm

* TutorialsPoint. (n.d.). *Boyer-Moore Algorithm. TutorialsPoint.* Retrieved May 14, 2025, from https://www.tutorialspoint.com/data_structures_algorithms/boyer_moore_algorithm.htm

* OpenAI. (2025). *ChatGPT (gpt-4.0-turbo)* [Large language model]. Retrieved May 14, 2025, from https://chat.openai.com/