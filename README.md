# Header Creator
Simple utility to help with creating header files for C/C++.

# Features
- **1 solution for 1 problem**. All the utility does is create a header file with header guard for it.
- **Extracting name**. The utility names the header guard based on the specified file name. 

# Usage
Example:
``` bash
hdrcr hero
```

There is a file as a result:
``` cpp
/* hero.h */
# ifndef HERO_H
# define HERO_H

# endif
```

