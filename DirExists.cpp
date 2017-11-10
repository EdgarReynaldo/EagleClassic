

#include <cstdlib>
#include <cstdio>

int main(int argc , char** argv) {

   if (argc != 2) {
      return 1;
   }

   char command[4096];
   sprintf(command , "cd %s" , argv[1]);

   bool exists = !(system(command));
//   printf("cd x returns %i\n" , system("cd x"));// returns 1 on Windows, returns 256 on OpenSUSE
//   printf("cd build returns %i\n" , system("cd build"));// returns 0

   if (exists) {printf("Exists\n");} else {printf("Does not exist\n");}

   return 0;
}
