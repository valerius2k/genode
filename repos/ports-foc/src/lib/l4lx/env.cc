/*
 * \brief  Global environment for L4Linux support library
 * \author Stefan Kalkowski
 * \date   2011-03-17
 */

/*
 * Copyright (C) 2011-2013 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

/* Genode includes */
#include <base/env.h>
#include <base/log.h>
//#include <base/printf.h>
#include <base/quota_guard.h>
//#include <dataspace/client.h>

/* L4lx library includes */
#include <env.h>

#include "genode_env.h"

namespace Fiasco {
#include <l4/sys/consts.h>
}

using namespace Genode;


L4lx::Env* L4lx::Env::env()
{
	try {
		static L4lx::Env _env;
		return &_env;
	} catch (Out_of_ram) {
	//} catch(Ram_session::Quota_exceeded) {
		Genode::warning("heap size exceeds available ram!");
		//PWRN("heap size exceeds available ram!");
		return 0;
	}
}


L4lx::Env::Env() : _rm(&genode_alloc()) {

	/* Create an empty L4Linux specific region-map */
	_rm.add_range(0, ~0UL);

	/*
	 * The first page never gets used under Genode/Fiasco.OC
	 * to notice null-pointer dereference, so reserve it.
	 */
	_rm.alloc_addr(L4_PAGESIZE, 0);
}
