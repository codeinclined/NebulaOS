#ifndef __PORTS_H
#define __PORTS_H

#include "ktypes.h"

extern void outp(_uint16 port, _uint8 data);
extern void outpw(_uint16 port, _uint16 data);

extern _uint8  inp(_uint16 port);
extern _uint16 inpw(_uint16 port);

#endif

