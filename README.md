# Header Creator
Simple utility to help with creating header files for C/C++.

# Features
- **1 solution for 1 problem**. All the utility does is create a header file with header guard for it.
- **Extracting name**. The utility names the header guard based on the specified file name. 

# Usage
## Simplest case
``` bash
hdrcr hero enemy
```

There are files as a result:
``` cpp
/* hero.h */
#ifndef HERO_H
#define HERO_H

#endif
```

``` cpp
/* enemy.h */
#ifndef ENEMY_H
#define ENEMY_H

#endif
```

## Specify directory
``` bash
hdrcr include/test_file
```

Result:
``` cpp
/* include/test_file.h */
#ifndef TEST_FILE_H
#define TEST_FILE_H

#endif
```
In this case, the specified directory must exist in advance.

## Specific macro name
``` bash
hdrcr -h HELL_WORLD_H hello_world
```

Result:
``` cpp
/* hello_world.h */
#ifndef HELL_WORLD_H
#define HELL_WORLD_H

#endif
```
