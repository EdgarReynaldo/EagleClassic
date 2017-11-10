

#include <string>
using std::string;

#include <list>
using std::list;

#include <cstdio>

int main(int argc, char** argv) {

   if (argc != 3) {
      printf("Usage : %s object_directory/ file.d\n" , argv[0]);
      return 1;
   }

   string dir = argv[1];
   string dstr = argv[2];
   if (dir[dir.size() - 1] != '/') {dir += '/';}

   dstr = dir + dstr;

   FILE* f = fopen(dstr.c_str() , "r");
   if (!f) {
      printf("Could not open %s for reading!\n" , dstr.c_str());
      return 2;
   }

   char buf[4096];
   int count = 0;

//   count = fscanf(f , "%s:" , buf);// fails, includes the trailing ':'
   count = fscanf(f , "%[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890._]:" , buf);
   if (!count) {
      fclose(f);
      printf("Could not read object file name!\n");
      return 3;
   }
   string objstr = buf;
   if (!objstr.size()) {
      fclose(f);
      printf("Object file name's length is zero!\nbuf is '%s'\nobjstr is '%s'" , buf , objstr.c_str());
      return 4;
   }
   objstr = dir + objstr;

   list<string> depstrs;
   while (1) {
      count = fscanf(f , "%s" , buf);
      if ((count == 0) || (count == EOF)) {break;}
      if (string("\\") != string(buf)) {
         depstrs.push_back(string(buf));
      }
   }

   fclose(f);

   /// Remove duplicate dependencies from depstrs
/*
   int i = 0 , j = 0;
   for (list<string>::iterator it = depstrs.begin() ; it != depstrs.end() ; ++it) {
      j = i + 1;
      string s1 = *it;
      // 0 1 2
      list<string>::iterator it2 = it;
      ++it2;
      for ( ; it2 != depstrs.end() ; ) {
         printf("i,j = %i,%i\n" , i , j);
         // 1 2
         string s2 = *it2;
         printf("s1 = '%s' " , s1.c_str());
         printf("s2 = '%s'\n" , s2.c_str());
         if (s1 == s2) {
//         if (*it == *it2) {
            it2 = depstrs.erase(it2);
            printf("Erasing %i\n" , j);
         } else {
            ++it2;
            ++j;
         }
      }
      ++i;
   }
*/
   for (list<string>::iterator it = depstrs.begin() ; it != depstrs.end() ; ++it) {
      list<string>::iterator it2 = it;
      ++it2;
      for ( ; it2 != depstrs.end() ; ) {
         if (*it == *it2) {
            it2 = depstrs.erase(it2);
         } else {
            ++it2;
         }
      }
   }


//** DIAGNOSTIC output

   f = fopen(dstr.c_str() , "w");
   if (!f) {return 5;}

   FILE* fout = f;
///   FILE* fout = stdout;

   fprintf(fout , "%s %s :" , objstr.c_str() , dstr.c_str());
   for (list<string>::iterator it = depstrs.begin() ; it != depstrs.end() ; ++it) {
      fprintf(fout , " %s" , (*it).c_str());
   }
   fprintf(fout , "\n");
//*/
   fclose(f);

   return 0;
}

