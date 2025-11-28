#ifndef CREATOR_H
#define CREATOR_H

#include <fstream>
#include <string>
#include <string_view>

namespace hdrcr 
{
  class FileOpenException { };

  enum class CreationResult {
    SUCCESS,
    HEADER_EXISTS,
    FAILURE,
  };

  class HeaderCreator {
  private:
    std::string _filename { };
    std::string _header;
    std::ofstream _out;

    bool header_exists();

  public:
    HeaderCreator(std::string_view filename, std::string_view header="");
    ~HeaderCreator();
    CreationResult create_header();
  };
}

#endif
