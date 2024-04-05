# 1. 添加http的端口监听



```
cd /etc/nginx
```

==结果:==

```
conf.d   fastcgi_params  koi-win  modules-available  nginx.conf  scgi_params  sites-enabled  uwsgi_params
fastcgi.conf  koi-utf  mime.types  modules-enabled    proxy_params  sites-available  snippets   win-utf
```

打开nginx配置文件  nginx.conf

```
vim nginx.conf
```

==结果==

在http 下配置监听端口 listen 80;

<img src="/Users/dianhongyang/Desktop/学习/nginx/nginx.doc.assets/截屏2024-04-01 14.28.12.png" alt="截屏2024-04-01 14.28.12" style="zoom:45%;" />:



> [!CAUTION]
>
> 可能出现打不开nginx网站 
>
> 解决方案
>
> ```
> 添加 80 段端口配置
> firewall-cmd --zone=public --add-port=80/tcp --permanent
> 
> 重启防火墙
> systemctl restart firewalld.service
> 
> ```
>
> 

