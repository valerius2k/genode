/*
 * \brief  Block request
 * \author Norman Feske
 * \date   2018-12-17
 */

/*
 * Copyright (C) 2018 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU Affero General Public License version 3.
 */

#ifndef _INCLUDE__BLOCK__REQUEST_H_
#define _INCLUDE__BLOCK__REQUEST_H_

/* Genode includes */
#include <base/stdint.h>

namespace Block { struct Request; }


struct Block::Request
{
	enum class Operation : Genode::uint32_t { INVALID = 0, READ = 1, WRITE = 2, SYNC = 3 };
	enum class Success   : Genode::uint32_t { FALSE = 0, TRUE = 1 };

	Operation         operation;
	Success           success;
	Genode::uint64_t  block_number;
	Genode::uint64_t  offset;
	Genode::uint32_t  count;
	Genode::uint32_t  tag;

	bool operation_defined() const
	{
		return operation == Operation::READ
		    || operation == Operation::WRITE
		    || operation == Operation::SYNC;
	}

} __attribute__((packed));

#endif /* _INCLUDE__BLOCK__REQUEST_H_ */
