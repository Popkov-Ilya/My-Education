# Заметки по Samba (smb)

**| База**

```bash
sudo apt install samba
sudo nano /etc/samba/smb.conf
```



**|	Конфиг**

```properties
interfaces = 192.168.1.0/24 eth0
[New Share]
    comment = A new share
    path = /home/kali/share
    browseable = yes
    read only = no
    guest ok = no
    valid users = kali
```



**| Настройка**

```bash
sudo systemctl restart smbd
sudo smbpasswd -a username
```



*Доступ через smb://192.168.1.ХХ*