#include "optionsget.h"
//获取参数的函数
 /*
  * optionsget
  * argc , *argv  --para in main()
  * return filepath
  */
char* optionsget(int argc,char *argv[],bool *debug)
{
  char ch;
  char *filepath;
  while ((ch = getopt(argc,argv,"p:d"))!=-1)
  {
    switch(ch)
    {
    case 'p':
       filepath=optarg;
        break;
   case 'd':
     *debug=true;
     std::cout << "Debug Model" << '\n';
     break;
    default:
      std::cout << "Your Options are ilegal.You can just use [-p PATH] [-d]." << '\n';
        break;
    }
  }
  return filepath;
}
