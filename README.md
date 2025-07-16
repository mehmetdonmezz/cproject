
# Get Next Line - C Dilinde Satır Okuma Fonksiyonu

**Bu projenin amacı, C dilinde bir dosyadan veya stdin'den satır satır veri okuma işlemini gerçekleştirecek bir fonksiyon yazmaktır. Bu proje, dosya okuma işlemlerine dair temel anlayışı geliştirirken, dinamik bellek yönetimi ve buffer yönetimi gibi konularda deneyim kazandırır.**

### Projenin Amacı:

* **Dinamik Bellek Yönetimi:** 
  Proje, her okunan satır için dinamik olarak hafıza ayırmayı gerektirir. Bu işlem, her satırın belleğe doğru şekilde yerleştirilmesi ve sonraki satırlarla karışmaması için yönetilmelidir.

* **Dosya I/O (Girdi/Çıktı) İşlemleri:**
  Dosya okuma ve yazma işlemleri öğrenilir. Kullanıcıdan veya dosyadan gelen verileri almak için uygun I/O fonksiyonları kullanılır.

* **Buffer Kullanımı:**
  Veriyi küçük parçalara (buffer) bölüp, her bir parçayı işleyerek veriyi satır satır okumak gereklidir. Bu, bellek yönetimini optimize etmeyi sağlar.

* **Get Next Line Fonksiyonu:**
  Fonksiyon, bir dosyadan veya stdin'den gelen verileri satır satır okur ve her satırı kullanıcıya geri döndürür. Satır okuma işlemi, her seferinde bir satırın bitimine kadar devam eder ve bir satır okunduğunda geri döner.

* **Modüler ve Temiz Kod Yapısı:**
  Fonksiyonlar tek bir sorumluluğa sahip olacak şekilde yazılır, okunabilirliği artıracak şekilde yapılandırılır.

* **Bellek Güvenliği ve Hata Yönetimi:**
  Bellek sızıntıları engellenir, kullanılan bellek doğru bir şekilde serbest bırakılır. Aynı zamanda, potansiyel hatalar için uygun kontrol mekanizmaları uygulanır.

* **Test ve Doğrulama:**
  Yazılan fonksiyonlar, farklı dosyalarla test edilerek doğrulukları kontrol edilir. Geliştirilen fonksiyon ile `read()` fonksiyonu arasında karşılaştırmalar yapılır.

### Desteklenen Özellikler:

* **`get_next_line(int fd, char **line)`**
  * Dosyadaki bir satırı okur ve bir `char*` dizisine yazdırır.
  * `fd`: Okunacak dosyanın dosya tanımlayıcısı.
  * `line`: Satırın depolanacağı karakter dizisinin adresi.

* **Dosya Sonu (EOF) ve Hata Durumları:**
  * Satır okuma işlemi tamamlandığında, fonksiyon satırın sonunu (EOF) algılar ve `NULL` döner.
  * Hata durumlarında uygun hata yönetimi yapılır.

* **Veri Okuma ve Buffer Yönetimi:**
  * Satır okuma işlemi, verinin sonuna kadar devam eder, ve her okunan parça doğru bir şekilde buffer'a aktarılır.

* **Daha Fazla Veri Okuma:**
  * Eğer satırda veri bitmediyse, fonksiyon devam eder ve yeni veri okur.

### Bonus Kısmı:

Bonus kısmında, `get_next_line` fonksiyonunun daha esnek hale getirilmesi beklenir. Aşağıdaki özelliklerin eklenmesi gerekmektedir:

* **Daha Fazla Dosya Tanımlayıcısı Desteği:**
  `get_next_line` fonksiyonu, sadece bir dosya tanımlayıcısından (fd) veri okumamalıdır. Bonus kısmı ile fonksiyon, birden fazla dosya tanımlayıcısına (fd) aynı anda hizmet verebilecek şekilde geliştirilebilir.

* **Buffer Boyutunun Dinamik Olarak Belirlenmesi:**
  Buffer boyutunun sabit olmaması gerekir. Kullanıcı tarafından belirtilen bir boyutla dinamik olarak buffer boyutunun belirlenmesi sağlanabilir.

* **Dosya Tanımlayıcıları Arasında Koşullu Okuma:**
  Bonus kısmında, fonksiyonun birden fazla dosya tanımlayıcısı ile eşzamanlı olarak çalışması sağlanmalıdır. Kullanıcı birden fazla dosya okuma işlemi yaparken her dosyadan sırasıyla veri alabilmelidir.

* **Hata Yönetiminin İyileştirilmesi:**
  Fonksiyon, hata durumlarını daha ayrıntılı şekilde ele alacak şekilde güncellenebilir. Her dosya tanımlayıcısı için hata kodları döndürülebilir.

* **EOF Durumunun Yönetilmesi:**
  Fonksiyonun EOF durumunu doğru şekilde yönetmesi ve bir dosyanın sonunda okuma işlemi bitmeden diğer dosyaya geçiş yapması sağlanmalıdır.

### Yardımcı Fonksiyonlar:

Proje, fonksiyonların doğru şekilde çalışabilmesi için aşağıdaki yardımcı fonksiyonlara sahip olacaktır:

* **`ft_strjoin`**:
  * İki karakter dizisini birleştirir. Bu yardımcı fonksiyon, okunan verilerin birleştirilmesi için kullanılır.

* **`ft_strdup`**:
  * Karakter dizisinin bir kopyasını oluşturur. Bu fonksiyon, okunan verilerin geçici olarak depolanması için kullanılabilir.

* **`ft_strlen`**:
  * Bir karakter dizisinin uzunluğunu hesaplar. Satır uzunluğunun hesaplanmasında ve bellek yönetiminde faydalıdır.

* **`ft_putchar_fd`**:
  * Bir karakteri belirtilen dosya tanımlayıcısına yazar. Çıktı üretme işlemi için `write()` fonksiyonunu kullanır.

* **`ft_strchr`**:
  * Bir karakter dizisinde belirtilen karakteri arar. Satır sonunu bulmak için kullanılır.

### Neyi Nerede ve Neden Kullandık?

Bu bölümde, projenin nasıl çalıştığını ve hangi fonksiyonların hangi durumlarda kullanıldığını açıklayacağız.

#### **`get_next_line` Fonksiyonu**
* **Nerede Kullanılır:** Dosya okuma işlemi yaparken, `get_next_line` fonksiyonu her seferinde bir satır okur.
* **Neden Kullanılır:** Bu fonksiyon, dosyadaki her satırı okumak için temel işlevi yerine getirir. Dosya okuma işlemi bitene kadar çalışır ve her seferinde satır okur.

#### **`ft_strjoin` Fonksiyonu**
* **Nerede Kullanılır:** Satırları birleştirirken, okunan veriler genellikle bir buffer'a eklenir ve eski verilerle birleştirilir.
* **Neden Kullanılır:** Bu fonksiyon, dinamik olarak okunan satırları birleştirmek ve tam satırları elde etmek için kullanılır.

#### **`ft_strdup` Fonksiyonu**
* **Nerede Kullanılır:** Okunan satırların bir kopyasının alınması gerektiğinde.
* **Neden Kullanılır:** Satır verileri bir buffer'da saklanırken, orijinal veri kaybolmadan işlenmelidir. `ft_strdup`, okunan satırların güvenli bir şekilde saklanmasına olanak tanır.

#### **`ft_strlen` Fonksiyonu**
* **Nerede Kullanılır:** Satır uzunluğunu hesaplamak gerektiğinde.
* **Neden Kullanılır:** Satırın sonuna gelindiğinde, karakter dizisinin uzunluğunun bilinmesi gerekir. Bu fonksiyon, karakter dizisinin uzunluğunu hesaplayarak doğru bellek yönetimini sağlar.

#### **`ft_putchar_fd` Fonksiyonu**
* **Nerede Kullanılır:** Çıktı işlemlerinde, veriyi çıktı olarak yazdırırken.
* **Neden Kullanılır:** Verileri ekrana veya dosyaya yazdırmak için düşük seviyeli `write()` fonksiyonu kullanılır. Bu fonksiyon, yazma işlemini güvenli ve etkili bir şekilde gerçekleştirir.

#### **`ft_strchr` Fonksiyonu**
* **Nerede Kullanılır:** Satırın sonunu bulmak ve veriyi parçalara ayırmak gerektiğinde.
* **Neden Kullanılır:** Satırların sonunu (`
`) tespit etmek ve okunan veriyi bölmek için gereklidir. Bu fonksiyon, bir karakter dizisinde belirtilen karakteri arar ve satır sonunun doğru şekilde tespit edilmesini sağlar.

### Dosya Yapısı 📁:

Proje aşağıdaki dosya yapısına sahiptir:

```
get_next_line/
│
├── get_next_line.c         # Ana fonksiyonun bulunduğu dosya. get_next_line() fonksiyonunu içerir.
├── get_next_line.h         # Header dosyası, fonksiyon prototipleri ve gerekli kütüphaneleri içerir.
├── utils.c                 # Yardımcı fonksiyonların bulunduğu dosya (ft_strjoin, ft_strdup, ft_strlen, vs.).
├── Makefile                # Projeyi derlemek için kullanılan makefile.
├── README.md               # Proje hakkında açıklamaları içeren dosya.
└── example.txt             # Test amaçlı kullanılan örnek dosya.
```

* **`get_next_line.c`**: Projenin ana fonksiyonu olan `get_next_line` fonksiyonunu içerir. Bu fonksiyon dosyadan satır okuma işlemini gerçekleştirir.
* **`get_next_line.h`**: Projede kullanılan fonksiyon prototiplerinin yer aldığı başlık dosyasıdır.
* **`utils.c`**: Yardımcı fonksiyonlar bu dosyada toplanmıştır. `ft_strjoin`, `ft_strdup`, `ft_strlen`, `ft_putchar_fd`, ve `ft_strchr` gibi fonksiyonlar burada bulunur.
* **`Makefile`**: Projeyi derlemek için kullanılan makefile dosyasıdır.
* **`example.txt`**: `get_next_line` fonksiyonunun test edilmesi için örnek bir dosya.

### Testler ve Örnek Kullanım:

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while (get_next_line(fd, &line) > 0) {
        printf("%s
", line);
        free(line);  // Bellek yönetimi
    }

    close(fd);
    return 0;
}
```

### Kurulum:

Projeyi yerel sisteminize klonlamak için aşağıdaki komutu kullanabilirsiniz:

```bash
git clone https://github.com/kullanici_adiniz/get_next_line.git
```

### Kullanım:

`get_next_line` fonksiyonu, bir dosya tanımlayıcısı alır ve her çağrıldığında bir satır okur. Satır okuma işlemi bittiğinde, fonksiyon sıfır döner veya `NULL` değerini döndürür.

```c
#include "get_next_line.h"
int fd = open("file.txt", O_RDONLY);
char *line;

while (get_next_line(fd, &line)) {
    // satır işlemleri
    free(line); // Bellek serbest bırakma
}
close(fd);
```

### Notlar:

* Dosya okuma işlemi, belirtilen dosyanın sonuna kadar devam eder.
* `get_next_line` fonksiyonu her satırda belleği doğru şekilde yönetir.
* Proje, bellekte sızıntılar yaşanmaması için dikkatli bir şekilde yazılmalıdır.

---

### Created by SUDE NAZ KARAYILDIRIM
