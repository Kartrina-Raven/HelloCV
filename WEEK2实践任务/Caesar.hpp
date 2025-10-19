#include<iostream>
#include<string>
#include<fstream>
class FileHandler;
class Menu;
class Crypto{
    private:
    std::string text;
    int key;
    public:
    Crypto(std::string text1,int key1):text(text1),key(key1){};
    std::string Encryption();
    std::string Decryption();
    friend class FileHandler;
    friend class Menu;
};

std::string Crypto::Encryption(){
    int len=text.size();
    for(int i=0;i<len;i++){
        if ('a'<=text[i]&&text[i]<='z')
        text[i]=(text[i]-'a'+key)%26+'a';
        else if ('A'<=text[i]&&text[i]<='Z')
        text[i]=(text[i]-'A'+key)%26+'A';
    }
    return text;
}

std::string Crypto::Decryption(){
    int len=text.size();
    for(int i=0;i<len;i++){
        if ('a'<=text[i]&&text[i]<='z')
        text[i]=(text[i]-'a'-key+26)%26+'a';
        else if ('A'<=text[i]&&text[i]<='Z')
        text[i]=(text[i]-'A'-key+26)%26+'A';
    }
    return text;
}

class FileHandler{
    public:
    void ReadAndSave_E(std::string n,int k);
    void ReadAndSave_D(std::string n,int k);
};

void FileHandler::ReadAndSave_E(std::string n,int k){
	std::ofstream outFile("encrypted.txt",std::ios::trunc);
	std::ifstream inFile(n);
	if (!inFile.is_open()) {
    std::cerr << "无法打开输入文件: "<<n<<std::endl;
    return;
    }
	std::string line;
	while (getline(inFile,line)){
		Crypto a(line,k);
		outFile<<a.Encryption()<<std::endl;
	}
    std::cout<<"加密结果已保存到："<<"encrypted.txt"<<std::endl;
	outFile.close();
}

void FileHandler::ReadAndSave_D(std::string n,int k){
	std::ofstream outFile("decrypted.txt",std::ios::trunc);
	std::ifstream inFile(n);
	if (!inFile.is_open()) {
    std::cerr << "无法打开输入文件: "<<n<<std::endl;
    return;
    }
	std::string line;
	while (getline(inFile,line)){
		Crypto a(line,k);
		outFile<<a.Decryption()<<std::endl;
	}
    std::cout<<"解密结果已保存到："<<"decrypted.txt"<<std::endl;
	outFile.close();
}

class Menu{
    public:
    void show();
    void Run(int choice);
};

void Menu::show(){
    std::cout<<"请输入你需要操作的对应序号：\n1：加密文本\n2：解密文本\n3：加密文件\n4：解密文件\n";
}

void Menu::Run(int choice){
    switch(choice){
        case 1:{
               std::cout<<"请输⼊要加密的⽂本：";
               std::string read;
               getline(std::cin,read);
               std::cout<<"请输⼊密钥：";
               int key;
               std::cin>>key;
               Crypto object(read,key);
               std::cout<<"加密结果："<<object.Encryption()<<std::endl;
               break;}
        case 2:{
               std::cout<<"请输⼊要解密的⽂本：";
               std::string read;
               getline(std::cin,read);
               std::cout<<"请输⼊密钥：";
               int key;
               std::cin>>key;
               Crypto object(read,key);
               std::cout<<"解密结果："<<object.Decryption()<<std::endl;
               break;}
        case 3:{
               std::cout<<"请输⼊要加密的文件路径：";
               std::string read;
               getline(std::cin,read);
               std::cout<<"请输⼊密钥：";
               int key;
               std::cin>>key;
               FileHandler file;
               file.ReadAndSave_E(read,key);
               break;}
        case 4:{
               std::cout<<"请输⼊要解密的文件路径：";
               std::string read;
               getline(std::cin,read);
               std::cout<<"请输⼊密钥：";
               int key;
               std::cin>>key;
               FileHandler file;
               file.ReadAndSave_D(read,key);
               break;}
        default:{
               std::cout<<"输入有误。\n";
               break;}
    }
}