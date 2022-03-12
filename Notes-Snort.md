# Заметки Snort

Сурс - https://youtu.be/a92lIYcqzkg

```bash
sudo apt install snort #все просто
mkdir log # здесь будут алерты
touch /etc/snort/rules/custom.rules
# плюс надо добавить include $RULE_PATH/custom.rules в конфиг
sudo snort -l ./log -b -c /etc/snort/snort.conf # запуск
sudo snort -l ./log -b -c /etc/snort/snort.conf -r test.pcap
```



|	Создание правил

```bash
sudo nano /etc/snort/rules/custom.rules
```

```properties
alert tcp any any -> any any (msg:"Test Rule"; content:"vk.com"; classtype:trojan-activity; sid:999995; rev:1;)
```

