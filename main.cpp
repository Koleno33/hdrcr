#include <iostream>
#include <vector>
#include "errors.h"
#include "creator.h"
#include "arguments.h"

using s_vector = std::vector<std::string>;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << err::error_texts[err::ARG_COUNT] << '\n';
    return 1;
  }

  s_vector filenames { };
  std::string header { };

  for (int i = 1; i < argc; ++i) {
    if (argv[i] == args::flags[args::SPECIFIED_HEADER]) {
      if (i + 1 < argc) {
        ++i;
        header = argv[i];
      }
      else {
        std::cerr << err::error_texts[err::ARG_INCORRECT] << '\n';
        return 1;
      }
    } else {
      filenames.emplace_back(std::string{ argv[i] } + ".h");
    }
  }
  
  if (filenames.empty()) {
    std::cerr << err::error_texts[err::ARG_NO_HEADER] << '\n';
    return 1;
  }

  hdrcr::HeaderCreator hc { }; 
  hdrcr::CreationResult cr { hdrcr::CreationResult::FAILURE };
  for (std::string_view filename : filenames) {
    try {
      hc.change_file(filename, header);
      cr = hc.create_header();
    } catch (hdrcr::FileOpenException) {
      std::cerr << err::error_texts[err::FILE_ACCESS] << '\n';
      return 1;
    }

    if (cr == hdrcr::CreationResult::HEADER_EXISTS) {
      std::cerr << err::error_texts[err::HEADER_EXISTS] << '\n';
      return 1;
    };

    if (cr == hdrcr::CreationResult::FAILURE) {
      std::cerr << err::error_texts[err::FILE_ACCESS] << '\n';
      return 1;
    };
  }

  return 0;
}
