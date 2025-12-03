#include "errors.h"

namespace err
{
  std::array<std::string, 6> error_texts {
    "Argument error: Incorrect number of arguments.",
    "Argument error: Argument can\'t be found.",
    "Argument error: Incorrect argument.",
    "Argument error: No file name specified to create.",
    "File access error: Can\'t create file.",
    "Header error: Header file already exists.",
  };
}

