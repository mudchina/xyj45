// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 24 1997

inherit ITEM;
inherit F_LIQUID;

void create()
{
   set_name("酒壶", ({"jiuhu", "hu"}));
   set_weight(100);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "一个装有白烧酒的酒壶。\n");
     set("unit", "个");
     set("value", 250);
     set("max_liquid", 12);
   }

   // because a container can contain different liquid
   // we set it to contain wine at the beginning
   set("liquid", ([
     "type": "alcohol",
     "name": "白烧酒",
     "remaining": 12,
     "drunk_apply": 20,
   ]));
}
