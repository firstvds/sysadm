#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

char ch;

void usage()
{
 std::cout << "#Ave caesar! \n\nusage: \n [~]dec mode file_name key \n  mode: dec,enc\n  key - ineger value [1-25] \n\ndecypted/encrypted file will be in same directory\n\n";
};

void enc(std::string c,int key)
{
 std::ifstream i(c.c_str()); 
 std::ofstream o("./encr");
 while(i && i.get(ch))
 {
  if(std::isalpha(ch))
  {
   if(ch+key>'z')
    ch=('a'-1)+(ch+key-'z');
   else
   ch+=key;
  };
  o.put(ch);
 };
};

void dec(std::string c,int key)
{
 std::ifstream i(c.c_str()); 
 std::ofstream o("./decr");
 while(i && i.get(ch))
 {
  if(std::isalpha(ch))
  {
   if(ch-key<'a')
    ch='z'-('a'-(ch-key+1));
   else
    ch-=key;
  };
  o.put(ch);
 };
};

int main(int argc, char* argv[])
{
 if(atoi(argv[3])>25 || atoi(argv[3])<1)
  std::cout << "Illegal key" << std::endl;
 if(argc<4 || argc >4)
  usage(); 
 else
 {
  if(strcmp(argv[1],"dec")==0)
   dec(argv[2],atoi(argv[3]));
  else if(strcmp(argv[1],"enc")==0)
   enc(argv[2],atoi(argv[3]));
  else 
   usage();
 };
 return 0;
}
