#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <string_view>

namespace args 
{
  extern std::string_view flags[];

  enum ArgumentType {
    SPECIFIED_HEADER,
  };
}

#endif
