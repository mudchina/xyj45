// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit NPC;

void create()
{
  set_name("瘦店娘", ({"shou dianniang", "dianniang"}));
  set("gender", "女性");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 50);
  setup();
  carry_object("/d/obj/cloth/nichang")->wear();
}

void init ()
{
  remove_call_out ("messaging");
  call_out ("messaging",1+random(9),this_object());
}

void messaging (object who)
{
  if (random(2))
    command("sneer dianzhu");
  else
    command("slap dianzhu");
}
                
