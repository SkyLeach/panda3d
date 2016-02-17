/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file vector_uchar.cxx
 * @author drose
 * @date 2000-05-10
 */

#include "vector_uchar.h"

#define EXPCL EXPCL_PANDAEXPRESS
#define EXPTP EXPTP_PANDAEXPRESS
#define TYPE unsigned char
#define NAME vector_uchar

#include "vector_src.cxx"

// Tell GCC that we'll take care of the instantiation explicitly here.
#ifdef __GNUC__
#pragma implementation
#endif
