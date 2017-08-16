#include <iostream>
#include <string>
#include <fstream>
#include <io.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#include "diff.h"
#include "optionsget.h"
using namespace std;


//读取路径下所有文件函数
 /*
  * getAllFiles
  * path,files---store file name
  * return NULL
  */
void getAllFiles(string path, vector<string>& files) {
    //文件句柄
    long hFile = 0;
    //文件信息
    struct _finddata_t fileinfo;  //很少用的文件信息读取结构
    string p;  //string类很有意思的一个赋值函数:assign()，有很多重载版本
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) != -1) {
        do {
            if ((fileinfo.attrib & _A_SUBDIR)) {  //比较文件类型是否是文件夹
                if (strcmp(fileinfo.name,".") != 0 && strcmp(fileinfo.name,"..") != 0) {
                    files.push_back(p.assign(path).append("\\").append(fileinfo.name));
                    getAllFiles(p.assign(path).append("\\").append(fileinfo.name), files);
                }
            } else {
                files.push_back(p.assign(path).append("\\").append(fileinfo.name));
            }
        } while (_findnext(hFile, &fileinfo) == 0);  //寻找下一个，成功返回0，否则-1
        _findclose(hFile);
    }
}



int main(int argc,char *argv[])
 {
    char *filepath;
    bool debug;
    filepath=optionsget(argc,argv,&debug);
    vector<string> files;
    getAllFiles(filepath,files);
    int size = files.size();
    int plan=0;
		int plan2=0;
    char *file1;
    char *file2;
    int tmpsize1=strlen(filepath);
    int tmpsize2;
    std::cout << "Bingo:" << '\n';
      while(plan<size-1)
      {
        plan2=0;
				while(plan2<size-1)
				{
					file1=(char*)files[plan].data();
	        file2=(char*)files[plan2].data();
	        if(diff(file1,file2)==1)
	        {
	          tmpsize2=files[plan].size();
	          std::cout << "[!]" << files[plan].substr(tmpsize1,tmpsize2) << " is same as " << files[plan2].substr(tmpsize1,tmpsize2) << '\n';
	        }
					plan2++;
				}

        plan=plan+1;
      }
      if(debug)
      {
          std::cout << "Your Input(PATH) is:" << '\n';
          std::cout << filepath << '\n' << '\n';
          std::cout << '\n';
          std::cout << "All your files:" << '\n';
          for (int i = 0; i < size; i++)
          {
            cout<< "[*] " <<files[i]<<endl;
          }
        }
         return 0;
 }
