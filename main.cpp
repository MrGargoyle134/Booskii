#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <cstdio>
#include <cstdlib>

#include <windows.h>

int main(int argc, char* argv[])
{
    system("cls");
    if(argc < 2) std::printf("Usage: %s <filename>", argv[0]);

    // Open main file
   std::ifstream main_file(argv[1]);
   std::vector<std::string> files;

   if(main_file)
   {
      std::string line;

      while(getline(main_file, line))
      {
         files.push_back(line);
      }
   }
   else { std::cerr << "ERROR: can't open the file \"" << argv[1] << "\"." << std::endl; return -1; }

   main_file.close();

   char choice;

   for(unsigned int i = 0; i < files.size(); ++i)
   {
       std::ifstream page(files[i]);

          if(page)
          {
                std::string line2;

                while(getline(page, line2))
                {
                    std::cout << line2 << std::endl;
                }
          }
          else { std::cerr << "ERROR: can't open the file \"" << files[i] << "\"." << std::endl; return -1; }

        std::printf("\n\x1B[P+ENTER]      (page %d/%d)      \x1A[N+ENTER]\n", i+1, files.size());

        std::cin >> choice;
       if(choice == 'N');
       else if(choice == 'P' && i > 0) i-=2;
       else if(choice == 'S')
       {
           unsigned int page_number;
           std::cout << "Page: "; std::cin >> page_number;
           if(page_number <= files.size()) i = page_number - 2;
       }

       system("cls");
   }
   return 0;
}
