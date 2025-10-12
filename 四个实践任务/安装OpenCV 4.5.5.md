<font style="color:#DF2A3F;">1.先从官网上下载对应的文件并解压</font>![](https://cdn.nlark.com/yuque/0/2025/png/61442626/1759843210882-0238724a-3847-4b5b-b811-a70ab03d5fe0.png)

<font style="color:#DF2A3F;"></font>

<font style="color:#DF2A3F;">2.在解压后的文件中新建一个build文件夹，在这个文件夹中打开终端执行cmake，完成后执行安装</font>

![](https://cdn.nlark.com/yuque/0/2025/png/61442626/1759843246748-14aeb156-c1ee-4745-bea4-cd7880ffaf1e.png)



![](https://cdn.nlark.com/yuque/0/2025/png/61442626/1759843252600-24dd3aed-7c6c-450d-ae40-cfb1ededaf58.png)

<font style="color:#DF2A3F;"></font>

<font style="color:#DF2A3F;">3.按照网上的教程进行环境配置：</font>

<font style="color:#DF2A3F;">在</font><font style="color:#DF2A3F;">opencv4.conf文件中加上</font>

<font style="color:#DF2A3F;">/usr/local/lib</font>

<font style="color:#DF2A3F;"></font>

<font style="color:#DF2A3F;">在bash.bashrc文件中加上PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig</font>

<font style="color:#DF2A3F;">export PKG_CONFIG_PATH</font>

<font style="color:#DF2A3F;"></font>

<font style="color:#DF2A3F;">（期间卡了两次，分别要安装vim和安装mlocate解决）</font>



<font style="color:#DF2A3F;">4.最后随便找张图运行测试一下是否能正常运行，终端正常输出版本号并且弹出对应图像！！！</font>

![](https://cdn.nlark.com/yuque/0/2025/png/61442626/1759843265244-ba51a64d-3bf7-47c5-9103-49d75b71513d.png)

