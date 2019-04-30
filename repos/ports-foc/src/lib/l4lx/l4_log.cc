/*
 * \brief  L4Re functions needed by L4Linux.
 * \author Stefan Kalkowski
 * \date   2011-04-17
 */

/*
 * Copyright (C) 2011-2013 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

/* Genode includes */
//#include <base/printf.h>
#include <base/snprintf.h>
#include <base/log.h>
#include <util/string.h>

#include <linux.h>

namespace Fiasco {
#include <l4/log/log.h>
#include <l4/sys/kdebug.h>
}

using namespace Fiasco;

extern "C" {

	void LOG_printf(const char *format, ...)
	{
		Linux::Irq_guard guard;

		va_list list;

		va_start(list, format);

		char buf[1024];
		char *s = (char *)buf;
		int len;

		Genode::String_console sc(buf, sizeof(buf));

		sc.vprintf(format, list);

		len = Genode::strlen((const char *)s);

		// strip a line feed at the end
		if (s[len - 1] == '\n')
		{
			s[len - 1] = '\0';
		}

		// output it
		Genode::log(Genode::Cstring(s));

		//Genode::vprintf(format, list);
		va_end(list);
	}


	void LOG_vprintf(const char *format, va_list list)
	{
		Linux::Irq_guard guard;

		char buf[1024];
		char *s = (char *)buf;
		int len;

		Genode::String_console sc(buf, sizeof(buf));

		sc.vprintf(format, list);

		len = Genode::strlen((const char *)s);

		// strip a line feed at the end
		if (s[len - 1] == '\n')
		{
			s[len - 1] = '\0';
		}

		// output it
		Genode::log(Genode::Cstring(s));
		//Genode::vprintf(format, list);
	}


	void LOG_flush(void) {}

}
