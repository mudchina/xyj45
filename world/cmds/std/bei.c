// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// buy.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   object ob;
   string str;
   if( !arg)
     return notify_fail("No arg!\n");

   if(!(ob=present(arg, me)))
     return notify_fail("You don't have it!\n");
   
   if( (string)ob->query("skill_type") != "sword" )
     return notify_fail("Need to wield sword!\n");

   me->set_temp("weapon_second", ob);
   ob->set("equipped", "second_wield");
   
                   if( !stringp(str = ob->query("wield_msg")) )
                        str = "$N装备$n作武器。\n";
                   message_vision(str, me, ob);

   return 1;

}
int help(object me)
{
   write( @HELP
指令格式: buy <something> from <someone>

这一指令让你可以从某些人身上买到物品。
HELP
   );
   return 1;
}
