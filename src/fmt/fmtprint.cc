// Copyright 2010 Google Inc.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//      http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ------------------------------------------------------------------------

/*
 * The authors of this software are Rob Pike and Ken Thompson.
 *              Copyright (c) 2002 by Lucent Technologies.
 * Permission to use, copy, modify, and distribute this software for any
 * purpose without fee is hereby granted, provided that this entire notice
 * is included in all copies of any software which is or includes a copy
 * or modification of this software and in all copies of the supporting
 * documentation for such software.
 * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTY.  IN PARTICULAR, NEITHER THE AUTHORS NOR LUCENT TECHNOLOGIES MAKE ANY
 * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
 * OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 */
#include <stdarg.h>
#include <string.h>
#include "fmt/fmt.h"
#include "fmt/fmtdef.h"

namespace Fmt {

/*
 * format a string into the output buffer
 * designed for formats which themselves call fmt,
 * but ignore any width flags
 */
 /* TODO(r): These are weird. Why can't I call fmtvprint? And then,
  * why do these guys save oldargs?
  */

int
Formatter::fmtprint(State *f, const char *fmt, ...)
{
	va_list args, *oldargs;
	int n;

	f->flags = 0;
	f->width = 0;
	f->prec = 0;
	va_start(args, fmt);
	oldargs = f->args;
	f->args = &args;
	n = dofmt(this, f, fmt);
	va_end(args);
	f->args = oldargs;
	f->flags = 0;
	f->width = 0;
	f->prec = 0;
	if(n >= 0)
		return 0;
	return n;
}

int
fmtprint(State *f, const char *fmt, ...)
{
	va_list args, *oldargs;
	int n;

	f->flags = 0;
	f->width = 0;
	f->prec = 0;
	va_start(args, fmt);
	oldargs = f->args;
	f->args = &args;
	n = dofmt(&_stdfmt, f, fmt);
	va_end(args);
	f->args = oldargs;
	f->flags = 0;
	f->width = 0;
	f->prec = 0;
	if(n >= 0)
		return 0;
	return n;
}

}  /* end namespace Fmt */
