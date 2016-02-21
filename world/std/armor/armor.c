// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// armor.c

#include <armor.h>

inherit EQUIP;

void setup()
{
   if( clonep(this_object()) ) return;

   set("armor_type", TYPE_ARMOR);
   if( !query("armor_apply/dodge")
   &&   weight() > 3000 )
     set("armor_prop/dodge", - weight() / 3000 );
}
