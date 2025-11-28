#include "creator.h"
#include <cctype>

namespace hdrcr
{
  std::string get_header_str(std::string_view filename) {
    std::string result { filename };

    /* replace spaces and dots with _ and make uppercase */
    for (size_t i = 0; i < result.length(); ++i) {
      if (result[i] == ' ' || result[i] == '.') {
        result[i] = '_';
      } else {
        result[i] = std::toupper(result[i]);
      }
    }

    return result;
  }

  HeaderCreator::HeaderCreator(std::string_view filename, std::string_view header)
      : _filename(filename), _header(header) {
    _out = std::ofstream { _filename, std::ios::app };
    if (!_out) {
      throw FileOpenException();
    }
  }

  HeaderCreator::~HeaderCreator() {
    _out.close();
    _filename = "";
    _header = "";
  }

  bool HeaderCreator::header_exists() {
    std::ifstream in { _filename };
    if (!in) {
      return true;
    }

    char t;
    /* try to read one char */
    if (in.get(t)) {
      in.close();
      return true;
    }
    in.close();
    return false;
  }

  CreationResult HeaderCreator::create_header() {
    if (header_exists()) {
      return CreationResult::HEADER_EXISTS;
    }

    if (_header.empty()) {
      /* more complicated logic for checking filename and generating header */
      _header = get_header_str(_filename);
    } 
    
    _out << "#ifndef " << _header << '\n';
    _out << "#define " << _header << "\n\n";

    _out << "#endif";

    return CreationResult::SUCCESS;
  }
}

