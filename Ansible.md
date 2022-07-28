# Ansible

### INSTALL

```bash
# master
apt-add-repository ppa:ansible/ansible
apt update -y
apt install ansible -y
ansible --version
ansible-doc -l # все команды ansible

# hosts
apt install openssh-server -y
ufw allow ssh
apt install python -y
```



### INVENNTORY

```properties
# /etc/ansible/hosts

#ungrouped (все без группы)
10.0.50.2
myserver ansible_host=10.50.0.4 # именнованный узел без группы

[group1]
host2.test

[group2]
host3.test:2200

[groups:children] # Родительская группа
group1
group2

# если группы all нет - то все хосты в группах и без будут в all
[all]
host[2:3].test ansible_user=ignat # группировка хостов

[groups:vars]
ansible_user = root # переменная для всех узлов группы (перебьет переменные группы all)
```

```bash
ansible-inventory --list # отображает хосты в виде дерева
ansible-inventory --graph # то же самое примерно
```



### AD-HOC

```bash
ansible -m ping all
ansible -m shell -a 'free -m' host2.test
ansible -m setup group1 # информация о сервере в виде переменных

ansible -m copy -a "src=local.file dest=/home mode=777" -b all # копирует файл с сервера на удаленные хосты
ansible -m file -a "path=/home/local.file state=absent" -b all # удалил файл
ansible -m get_url -a "url=https://10.0.0.21 dest=/home" -b all # скачать файл

ansible -m apt -a "name=httpd state=installed" -b all # установил httpd
ansible -m apt -a "name=httpd state=removed" -b all # удалил httpd

ansible -m service -a "name=httpd state=started enabled=yes" -b # запустил сервер
```



### GROUP_VARS

```bash
mkdir group_vars
nano group_vars/group_name.yaml
```

```yaml
# учти, что если в inventory используется "=", здесь нужно использовать ":"
ansible_user: ignat
```



### PLAYBOOK

```yaml
- name: Name of the Playbook
  hosts: all
  tasks:
  - name: This is basic connectivity test task
    ping:
```

```bash
ansible-playbook -i inventory.yaml basic.yaml
```

```yaml
- hosts: dev # hosts можно не писать и указывать прямо при вызове
  tasks:
    - name: Create a file
      shell: touch test.txt
      args:
        chdir: /home/ignat/ # переход в директорию до выполнения действия
        creates: test.txt # отменяет действие, если файл уже создан
```

```yaml
- name: Install Some Stuff
  hosts: all
  become: yes
  
  vars:
    message1: Privet
    secret: secret
  
  tasks:
  - name: Install Apache
    yum: name=httpd state=latest
    
  - name: Start Apache
    service: name=httpd state=started enabled=yes
    
  - name: Print Variable
    debug:
      var: message1 # выведет сообщение Privet на всех серверах
    
  - set_fact: full_message="{{ message1 }}{{ secret }}"
  
  - shell: uptime
  register: results # сохранит значение uptime в переменной results
    
  - debug:
      msg: "Sekretnoe slovo {{ full_message }} {{ results.stdout }}" # выведет full_message и stdout из uptime
      
  - debug:
      var: ansible_distribution # стандартные переменные    
```



```yaml
---
- name: install Apache
  hosts: all
  become: yes
  
  vars:
    source_file: ./MyWebSite/index.html
    destin_file: /var/www/html
    
  tasks:
  - name: Check OS
    debug: var=ansible_os_family

  - block:
      - name: INstal aapache web server for RH
        yum: mane=httpd state=latest
        
      - name: Copy file
        copy: src={{ source_file }} dest={{ destin_file }} mode=0555
        notify: Restart Apache RedHat   
        
      - name: Start service
        service: name=httpd state=started enabled=yes
    when: ansible_os_family == "RedHat"
    
    
  - block:
      - name: INstal aapache web server for RH
        yum: mane=apache2 state=latest
        
      - name: Copy file
        copy: src={{ source_file }} dest={{ destin_file }} mode=0555
        notify: Restart Apache Debian   
        
      - name: Start service
        service: name=apache2 state=started enabled=yes
    when: ansible_os_family == "Debian"
    
    
    
  handlers:
  - name: Restart Apache RedHat
    service: name=httpd state=restarted
  - name: Restart Apache Debian
    service: name=apache2 state=restarted
```

