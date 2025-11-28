#ifndef ERRORS_H
#define ERRORS_H

#include <array>
#include <string>

namespace err
{
  enum ErrorType {
    ARG_COUNT,
    ARG_INCORRECT,
    FILE_ACCESS,
    HEADER_EXISTS,
  };

  extern std::array<std::string, 4> error_texts;
};

#endif
