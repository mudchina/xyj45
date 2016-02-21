// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// item.c

#include <dbase.h>
#include <move.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;

void setup()
{
   seteuid(getuid());
}
