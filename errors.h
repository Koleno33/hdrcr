#ifndef ERRORS_H
#define ERRORS_H

#include <array>
#include <string>

namespace err
{
  enum ErrorType {
    ARG_COUNT,
    ARG_NOT_FOUND,
    ARG_INCORRECT,
    ARG_NO_HEADER,
    FILE_ACCESS,
    HEADER_EXISTS,
  };

  extern std::array<std::string, 6> error_texts;
};

#endif
