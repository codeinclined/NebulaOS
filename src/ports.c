#include "kmemory.h"
#include "ktypes.h"

void outp(_uint16 port, _uint8 data)
{
  asm volatile 
  (
    "outb %0, %1"
    :
    :  "r" (data), "r" (port)
    :  "memory"
  );
}

void outpw(_uint16 port, _uint16 data)
{
  asm volatile 
  (
    "outw %0, %1"
    :
    :  "r" (data), "r" (port)
    :  "memory"
  );
}

void outpdw(_uint16 port, _uint32 data)
{
  asm volatile 
  (
    "outl %0, %1"
    :
    :  "r" (data), "r" (port)
    :  "memory"
  );
}

_uint8 inp(_uint16 port)
{
  _uint8 ret;
  
  asm volatile
  (
    "inb %0, %1"
    :  "=r" (ret)
    :  "r" (port)
    : "memory"
  );
  
  return ret;
}

_uint16 inpw(_uint16 port)
{
  _uint16 ret;
  
  asm volatile
  (
    "inw %1, %0"
    :  "=r" (ret)
    :  "r" (port)
    :  "memory"
  );
  
  return ret;
}

_uint32 inpdw(_uint16 port)
{
  _uint32 ret;
  
  asm volatile
  (
    "inl %1, %0"
    :  "=r" (ret)
    :  "r" (port)
    :  "memory"
  );
  
  return ret;
}

