// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit NPC;
void create()
{
  set_name("恶龙", ({"dragon"}));
  set("gender", "男性");
  set("long", "一条张牙舞爪的恶龙，样子十分可怕。\n");
  set("attitude", "aggressive");
  set("combat_exp", 50000+random(1000000));
  set("age", 100);
  set("per", 100);
  set("str", 30);
  set("int", 30);
  set("cor", 30);
  set("cps", 30);
  set("con", 30);
  set("max_kee", 500+random(1500));
  set("max_sen", 1000);
  set("force", 1000);
  set("max_force", 1000);
  set("max_mana", 600);
  set("mana",600);   
  set_skill("spells", 100);
  set_skill("force",100);
  set_skill("parry", 50+random(150));
  set_skill("dodge", 50+random(150));
  set_skill("unarmed", 50+random(150));
  set_skill("dragonstep", 50+random(150));
  set_skill("dragonfight", 50+random(150));
  map_skill("dodge", "dragonstep");
  map_skill("unarmed", "dragonfight");


  setup();
}

void die()
{
    object rope;
    string rp="/d/obj/fabao/kunxian-suo.c";

    if( rp->in_mud() )
    {
   rope = new(rp->query("replace_file"));
    }
    else
   rope = new(rp);
    if( environment() ) {
   message("vision", "一阵红光闪过，恶龙落在地上。定睛一看，原来恶龙已经遁去，地上只留下一条红索。\n", environment());
    }
    rope->move(environment(this_object()));
    destruct(this_object());
}
