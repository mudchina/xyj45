// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// icy_cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
   set_name( HIC "吹雪残云衣" NOR, ({ "icy cloth", "cloth" }) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "件");
     set("value", 40000);
     set("material", "cloth");
     set("armor_prop/armor", 10);
     set("armor_prop/dodge", 5);
   }
   setup();
}
