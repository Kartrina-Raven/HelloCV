1.安装git

sudo apt install git

![](https://cdn.nlark.com/yuque/0/2025/png/61442626/1760153838635-0f44244b-c327-4ce2-a15d-856310997419.png)



2.配置用户名和邮箱地址

 git config --global user.name "Your Name"

 git config --global user.email "email@example.com"

![](https://cdn.nlark.com/yuque/0/2025/png/61442626/1760153971561-0479d89e-0269-460a-9504-8d604073741c.png)



3.创建一个git仓库

在目标文件中 git init

![](https://cdn.nlark.com/yuque/0/2025/png/61442626/1760154030863-86454923-9c22-4a9f-8ec2-029f17f5f475.png)



4.尝试连接GitHub仓库但是失败了，因为没有配置ssh所以先配置![](https://cdn.nlark.com/yuque/0/2025/png/61442626/1760154066470-fff17255-a2f3-4cfa-8c52-1f8603ede4a7.png)



5.首先打开.ssh文件，显示“没有这个文件”，所以要先自行创建一个，然后再设置ssh

![](https://cdn.nlark.com/yuque/0/2025/png/61442626/1760154566767-04daa82a-a5c3-4567-87ea-7830cdbd7031.png)

![](https://cdn.nlark.com/yuque/0/2025/png/61442626/1760154347706-e5721167-9eee-414c-9697-5f1dd1870577.png)



6.打开公钥文件将其内容复制到GitHub网站的对应位置并保存

![](https://cdn.nlark.com/yuque/0/2025/png/61442626/1760154360836-4607d594-8508-4f74-b07e-8b4f00173811.png)



7.最后克隆一下GitHub仓库，git仓库中出现了对应文件

git clone 对应的ssh

![](https://cdn.nlark.com/yuque/0/2025/png/61442626/1760154369316-2fc764d5-fa4e-45b1-a245-df399637618b.png)



8.接下来远程连接github仓库

git remote add origin 对应的ssh

git branch -M main

git push -u origin main

![](https://cdn.nlark.com/yuque/0/2025/png/61442626/1760243484498-4e6f2ae5-a23a-4100-9198-ff9aafa02b08.png)

这里推送被拒绝，在输入git pull origin main之后还是不行，于是就强制推送了，输入git push -u origin main --force

![](https://cdn.nlark.com/yuque/0/2025/png/61442626/1760243487956-3fd5d3f1-524b-428c-a6c9-cde82c91c90e.png)

最后输出Everything up-to-date,完成了

