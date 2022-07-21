# Ansible

### INSTALL

```bash
# master
apt-add-repository ppa:ansible/ansible
apt update -y
apt install ansible -y
ansible --version

# hosts
apt install openssh-server -y
ufw allow ssh
apt install python -y
```



### HOSTS

```properties
# /etcc/ansible/hosts
[group1]
host2.test

[group2]
host3.test:2200

[all]
host[2-3].test ansible_user=ignat
```



### TEST

```bash
ansible -m ping all
ansible -m shell -a 'free -m' host2.test
```



### PLAYBOOK

```yaml
- hosts: all
  tasks:
  - name: This is basic connectivity test
    ping:
```

```bash
ansible-playbook -i hosts basic.yaml
```

```yaml
- hosts: dev
  tasks:
    - name: Create a file
      shell: touch test.txt
      args:
        chdir: /home/ignat/
        creates: test.txt
```

