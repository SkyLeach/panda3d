/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file namable.h
 * @author drose
 * @date 1999-01-15
 */

#ifndef NAMABLE_H
#define NAMABLE_H

#include "pandabase.h"

#include "typedObject.h"
#include <string>

/**
 * A base class for all things which can have a name.  The name is either
 * empty or nonempty, but it is never NULL.
 */
class EXPCL_PANDAEXPRESS Namable : public MemoryBase {
PUBLISHED:
  INLINE explicit Namable(const string &initial_name = "");
  INLINE Namable(const Namable &copy);
  INLINE Namable &operator = (const Namable &other);

#ifdef USE_MOVE_SEMANTICS
  INLINE Namable &operator = (Namable &&other) NOEXCEPT;
#endif

  INLINE void set_name(const string &name);
  INLINE void clear_name();
  INLINE bool has_name() const;
  INLINE const string &get_name() const;
  MAKE_PROPERTY(name, get_name, set_name);

  // In the absence of any definition to the contrary, outputting a Namable
  // will write out its name.
  INLINE void output(ostream &out) const;

private:
  string _name;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    register_type(_type_handle, "Namable");
  }

private:
  static TypeHandle _type_handle;
};

INLINE ostream &operator << (ostream &out, const Namable &n);

/**
 * An STL function object for sorting an array of pointers to Namables into
 * order by name.  Returns true if the objects are in sorted order, false
 * otherwise.
 */
class NamableOrderByName {
public:
  INLINE bool operator ()(const Namable *n1, const Namable *n2) const;
};

#include "namable.I"

#endif
