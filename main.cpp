#include <iostream>
#include "errors.h"
#include "creator.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << err::error_texts[err::ARG_COUNT] << '\n';
    return 1;
  }

  std::string new_filename { argv[1] };
  new_filename.append(".h");
  hdrcr::CreationResult cr { hdrcr::CreationResult::FAILURE };
  try {
    hdrcr::HeaderCreator hc { new_filename }; 
    cr = hc.create_header();
  } catch (hdrcr::FileOpenException) {
    std::cerr << err::error_texts[err::FILE_ACCESS] << '\n';
  }

  if (cr == hdrcr::CreationResult::HEADER_EXISTS) {
    std::cerr << err::error_texts[err::HEADER_EXISTS] << '\n';
    return 1;
  };

  if (cr == hdrcr::CreationResult::FAILURE) {
    std::cerr << err::error_texts[err::FILE_ACCESS] << '\n';
    return 1;
  };

  return 0;
}
