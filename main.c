/******************************************************************************
* Copyright (c) 2024-present JC Wang. All rights reserved
*
*   https://github.com/sonic-ng/sonic-sysdb
*
* This Source Code Form is subject to the terms of the Apache License 2.0
* You can obtain a copy at http://www.apache.org/licenses/LICENSE-2.0
******************************************************************************/

#include <crossdb.h>

int main (int argc, char **argv)
{
	xdb_res_t	*pRes;
	xdb_row_t	*pRow;

	xdb_conn_t	*pConn = xdb_open (argc > 1 ? argv[1] : ":memory:");
	XDB_CHECK (NULL != pConn, printf ("failed to create DB\n"); return -1;);

	pRes = xdb_exec (pConn, "CREATE DATABASE config ENGINE = MEMORY");
	pRes = xdb_exec (pConn, "USE config");
	pRes = xdb_exec (pConn, "SOURCE '/sonic-ng/schema/config/config.sql'");
	pRes = xdb_exec (pConn, "SOURCE 'init.sql'");

	pRes = xdb_exec (pConn, "CREATE DATABASE appl ENGINE = MEMORY");
	pRes = xdb_exec (pConn, "USE appl");
	pRes = xdb_exec (pConn, "SOURCE '/sonic-ng/schema/appl/appl.sql'");

	pRes = xdb_exec (pConn, "CREATE SERVER sysdb");

	xdb_exec (pConn, "SHELL PROMPT='SysDB> '");

	return 0;
}
