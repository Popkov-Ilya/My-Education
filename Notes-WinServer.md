# Заметочки о Win Server

#### *Да кто этот ваш AD*

Сурс - https://habr.com/ru/company/ultravds/blog/480776/



**|	Непосредственная установка DC и повышение роли**

```powershell
Get-WindowsFeature
Install-WindowsFeature -Name AD-Domain-Services
$pass = Read-Host -AsSecureString
Install-ADDSForest -DomainName test.domain -SafeModeAdministratorPassword $pass
```



**|	Добавление юзверя (пользователя)**

```powershell
New-ADUser -Name BackdoorAdmin -UserPrincipalName BackdoorAdmin@test
Get-ADUser BackdoorAdmin
Set-ADUser -Identity BackdoorAdmin -Enabled $true -PasswordNotRequired $true
(Get-ADGroup -Server localhost -Filter *).name
Get-ADGroup -Server localhost -Filter {Name -Like "Administrators"}
$user = Get-ADUser BackdoorAdmin
Get-ADGroup -Server localhost -Filter {Name -Like "Administrators"} | Add-ADGroupMember -Members $user
Get-ADGroupMember -Identity Administrators
```



**| Windows Admin Center**

```powershell
(new-object System.Net.WebClient).DownloadFile("https://aka.ms/wacdownload", "WAC.msi")
msiexec /i <WindowsAdminCenterInstallerName>.msi /qn /L*v log.txt SME_PORT=<port> SSL_CERTIFICATE_OPTION=generate #важно, путь к msi без точки в начале
```



**| WinGet**

```powershell
winget install --id Git.Git -e --source winget # установит гит
```

