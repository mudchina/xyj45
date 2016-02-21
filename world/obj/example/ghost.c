// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// ghost.c

inherit NPC;

void create()
{
   set_name("孤魂野鬼", ({ "wandering ghost", "ghost" }) );
   set("age", 45);
   
   set("str", 24);
   set("cor", 26);

   set("env/wimpy", 70);
   set_temp("apply/attack", 10);
   set_temp("apply/armor", 3);

   setup();
}

int is_ghost() { return 1; }
