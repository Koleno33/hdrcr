#include "errors.h"

namespace err
{
  std::array<std::string, 4> error_texts {
    "Argument error: Number of arguments is invalid.",
    "Argument error: Argument can\'t be found.",
    "File access error: Can\'t create file.",
    "Header error: Header file already exists.",
  };
}

