# Libft
### Selfmade c library with vectors and gpu multithreading
This library has started with this [assignment](/subject/libft.en.pdf), but development of it continued with further projects, because we are only allowed to use handwritten libraries in School 21

To use all of this library features or just part of them first of all compile it running ```make``` in the root of libft.

To use this library with all its features, include desired header in your file ```#include "libft.h"``` then during compilation specify path to headers ```-I libft/includes/``` and add ```libft/lib/libft.a``` to linking files.

For example assuming that you running following command from the root of your project and put libft in '''libft''' folder in the there too:

```clang -I libft/includes/ -o your_program libft/lib/libft.a main.c```

## Libft includes following modules:
### 1. **Standart** - libstd
Rewritten functions from C standard library and some other useful functions. 

To use only it ```#include "libstd.h"``` and link ```libft/lib/libstd.a```

### 2. liblist - functions to work with linked lists.

Includes functions to create, find, add, iterate over and remove nodes of linked lists.

To use only it ```#include "t_list.h"``` and link ```libft/lib/liblist.a```

### 3. libvector - functions to work with dynamic array or as it called in C++ vector

Includes functions to work with vector of ```void *``` and also vectors of ```char *```. Latest has prefix ```string_```.
There are bunch of structs in ```t_vec.h``` like ```t_uint2```, ```t_float3``` and ```t_ucol4```.
```t_ucol4``` is a union to handle 32 bit colors. There are functions to work with colors in this module too.

To use only it ```#include "t_vector.h"``` and link ```libft/lib/libvec.a```

### 4. libavl - functions to work with AVL binary trees

Includes functions to create new nodes of tree, to insert them into tree, search tree for specified key, max or min value
and freeing the tree. There is function ```ft_avltovec``` in this module which converts avl tree to sorted vector. This function implies that you are also using t_vec module of this library.

To use only it ```#include "btavl.h"``` and link ```libft/lib/libavl.a```

### 5. libprintf - selfmade implementation of printf function of ```<stdio.h>>```

In this module there are implementations of following functions ```ft_printf```, ```ft_sprintf```, ```ft_vprintf``` and ```ft_fdprintf``` which match the behavior of corresponding functions of ```<stdio.h>```

It's impossible to use only libprintf now, so it's obligatory to include ```libstd.a``` and ```libvec.a``` along with ``libprintf.a`` during linking process of compilation.

### 6. libmtrx - some functions to work with matrices

Implementation of these function is not optimized, but it's working.

To use only it ```#include "mtrx.h"``` and link ```libft/lib/libmtrx.a```

### 6. libmtrx - module to work with hash tables

Functions to work with hash tables creating them, adding elements, iterating over them, and freeing them.

To use only it ```#include "htable.h"``` and link ```libft/lib/libhtable.a```
