# CRL vs OCSP

Сурс - https://habr.com/ru/post/417521/

CRL (Certificate Revocation List) – проверяется наличие серийного номера сертификата в списке отзыва (обычно локально).

OCSP (Online Certificate Status Protocol) – сертификат отправляется на специализированный сервер, где проверяется его статус.



## CRL

```bash
# Скачиваем сертификат
echo -n | openssl s_client -connect revoked.badssl.com:443 -servername revoked.badssl.com 2>&1 | sed -ne '/-BEGIN CERTIFICATE-/,/-END CERTIFICATE-/p' > /tmp/revoked.badssl.com.crt

# Смотрим детали
openssl x509 -noout -text -in revoked.badssl.com.crt

# Скачиваем CRL
wget http://crl3.digicert.com/RapidSSLTLSDVRSAMixedSHA2562020CA-1.crl

# Выгружаем серийный номер сертификата
openssl x509 -in revoked.badssl.com.crt -noout -serial

# Проверяем на наличие
openssl crl -inform DER -text -in RapidSSLTLSDVRSAMixedSHA2562020CA-1.crl | grep "0D2E67A298853B9A5452E3A285A4572F"

```



## OCSP

```bash
# Скачать сертификат
echo -n | openssl s_client -connect revoked.badssl.com:443 -showcerts
# Записать в revoked.badssl.com, intermediate.crt
# Посмотреть ocsp центр
openssl x509 -in /tmp/revoked.badssl.com.crt -noout -ocsp_uri
# Непосредственно проверка
openssl ocsp -url http://ocsp.digicert.com -issuer /tmp/intermediate.crt -cert /tmp/revoked.badssl.com.crt -text
```

