/* Multiple versions of strncasecmp_l
   Copyright (C) 2013 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef NOT_IN_libc
# include <string.h>
# define strncasecmp_l __strncasecmp_l_ppc32
extern __typeof (__strncasecmp_l) __strncasecmp_l_ppc32 attribute_hidden;
extern __typeof (__strncasecmp_l) __strncasecmp_l_power7 attribute_hidden;
#endif

#include <string/strncase_l.c>
#undef strncasecmp_l

#ifndef NOT_IN_libc
# include <shlib-compat.h>
# include "init-arch.h"

/* Avoid DWARF definition DIE on ifunc symbol so that GDB can handle
   ifunc symbol properly.  */
extern __typeof (__strncasecmp_l) __libc_strncasecmp_l;
libc_ifunc (__libc_strncasecmp_l,
	     (hwcap & PPC_FEATURE_HAS_VSX)
             ? __strncasecmp_l_power7
             : __strncasecmp_l_ppc32);

weak_alias (__libc_strncasecmp_l, strncasecmp_l)
#endif