#include <iostream>

#include <filesystem>



void fileSystemTest()

{

  std::filesystem::path filePath{R"(/home/cathy/C_program/someFile.txt)"};

  if(filePath.has_filename())

  {

    std::cout << filePath.filename() << std::endl;

  }

  for(const auto& filePathElement : filePath)

  {

    std::cout << filePathElement << std::endl;

  }

}



void showContentOfDirectory()

{

  std::filesystem::path directoryPath{R"(/home/cathy/C_program)"};

  

  for(auto it = std::filesystem::directory_iterator(directoryPath); it != std::filesystem::directory_iterator(); it++)

  {

    std::cout << *it << std::endl;

  }

  std::cout << "-----------------------------------------------------" << std::endl;



  std::cout << "files in this directory: " << std::endl;

  for(auto it = std::filesystem::directory_iterator(directoryPath); it != std::filesystem::directory_iterator(); it++)

  {

    std::cout << (*it).path().filename() << ' ';

  }

  std::cout << std::endl;

  

  std::error_code errorCode;

  std::filesystem::space_info spaceInfo = std::filesystem::space(directoryPath, errorCode);

  std::cout << "disk capacity:" << spaceInfo.capacity << std::endl;

  std::cout << "free space:" << spaceInfo.free << std::endl;

}



int main()

{

  fileSystemTest();

  std::cout << "-----------------------------------------------------" << std::endl;

  showContentOfDirectory();

 

  return 0;

}



// references:

// https://en.cppreference.com/w/cpp/filesystem

// https://en.cppreference.com/w/cpp/filesystem/path/has_path

// https://en.cppreference.com/w/cpp/filesystem/directory_iterator

// https://en.cppreference.com/w/cpp/filesystem/directory_entry

// https://en.cppreference.com/w/cpp/filesystem/space_info

// https://stackoverflow.com/questions/64155365/is-stdfilesystemdirectory-iterator-really-an-iterator

// compile: g++ --std=c++17 fileSystem.cpp -o fileSystem

// run: ./fileSystem
