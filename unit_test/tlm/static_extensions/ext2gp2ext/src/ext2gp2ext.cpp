/*****************************************************************************

  The following code is derived, directly or indirectly, from the SystemC
  source code Copyright (c) 1996-2007 by all Contributors.
  All Rights reserved.

  The contents of this file are subject to the restrictions and limitations
  set forth in the SystemC Open Source License Version 2.4 (the "License");
  You may not use this file except in compliance with such restrictions and
  limitations. You may obtain instructions on how to receive a copy of the
  License at http://www.systemc.org/. Software distributed by Contributors
  under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
  ANY KIND, either express or implied. See the License for the specific
  language governing rights and limitations under the License.

 *****************************************************************************/

#include "tlm.h"

#include "SimpleLTMaster_ext.h"
#include "SimpleBus.h"
#include "SimpleLTSlave_ext.h"
#include "extension_adaptors.h"


int sc_main(int argc, char* argv[])
{
  SimpleLTMaster_ext master("master1", 10, 0x0);
  adapt_ext2gp<32>   bridge1("bridge1");
  SimpleBus<1,1>     bus("bus");
  adapt_gp2ext<32>   bridge2("bridge2");
  SimpleLTSlave_ext  slave("slave1");

  master.socket(bridge1.slave_socket);
  bridge1.master_socket(bus.slave_socket[0]);
  bus.master_socket[0](bridge2.slave_socket);
  bridge2.master_socket(slave.socket);

  sc_core::sc_start();

  return 0;
}
