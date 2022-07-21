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

```
- name: Install Some Stuff
  hosts: all
  become: yes
  
  tasks:
  - name: Install Apache
    yum: name=httpd state=latest
    
  - name: Start Apache
    service: name=httpd state=started enabled=yes
```



### 
