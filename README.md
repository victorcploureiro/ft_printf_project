<p align="center">
  The goal of this project is pretty straightforward. You will recode printf().<br>
  You will mainly learn about using a variable number of arguments. How cool is that??<br>
  It is actually pretty cool :)
</p>

#  Project

This is the third project of the common core at 42 São Paulo. The objective of this project is recode the function **printf**.<br>
The **printf** is a very useful function with a lot of string manipulations.

# Documentation

#### NAME:

ft_printf - formatted output conversion

#### SYNOPSIS:

```c
// MANDATORY: Only supports convertions flags: %c, %s, %d, %i, %u, %p, %x, %X and %%
#include "ft_printf.h"
```

```c
int  ft_printf(const char *fmt, ...);
```

#### DESCRIPTION:

**ft_printf** write output to stdout, the standard output stream.

**ft_printf** write the output under the control of a format string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of stdarg) are converted for output.

#### Format of the format string

The format string is a character string, beginning and ending in its initial shift state, if any.  The format string is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.  Each conversion specification is introduced by the character %, and ends with a conversion specifier.

## How to use it?

Clone this repository:

```shell
git clone https://github.com/victorcploureiro/ft_printf.git ft_printf
```

Then compile the files as following:

#### Mandatory:

Formats just the percentage flags: %c, %s, %d, %i, %u, %p, %x, %X, %%.

```shell
make
```

#### Compiling:

Compile the archive _libftprintf.a_ with your _main_.

```shell
cc -Wall -Wextra -Werror main.c libftprintf.a
```

> [!WARNING]
> Don't forget to include in your main the prototype of the **ft_printf**.
