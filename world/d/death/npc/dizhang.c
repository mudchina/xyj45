// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//puti.c
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("地藏王菩萨", ({"dizang pusa", "pusa"}));
  set("long", "面如朱玉，大耳垂肩，一脸肃静．
他便是主管阴曹地府，天下鬼魂的地藏王菩萨．\n");
  set("gender", "男性");
  set("class", "youling");
  set("age", 70);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("per", 30);
  set("str", 30);
  set("int", 30+random(5));
  set("max_kee", 3000);
  set("max_gin", 2500);
  set("max_sen", 2000);

  set("force", 3500);
  set("max_force", 2000);
  set("force_factor", 120);
  set("max_mana", 2500);
  set("mana", 2000);
  set("mana_factor", 120);

  set("combat_exp", 2000000);

  set_skill("unarmed", 150);
  set_skill("whip", 180);
  set_skill("hellfire-whip", 200);
  set_skill("dodge", 180);
  set_skill("parry", 150);
  set_skill("literate", 130);
  set_skill("spells", 180);
  set_skill("force", 180);
  set_skill("tonsillit", 130);
  set_skill("ghost-steps", 180);
  set_skill("gouhunshu", 150);
  set_skill("jinghun-zhang", 150);
  set_skill("kusang-bang", 180);

  map_skill("force", "tonsillit");
  map_skill("unarmed", "jinghun-zhang");
  map_skill("dodge", "ghost-steps");
  map_skill("spells", "gouhunshu");
  map_skill("parry", "hellfire-whip");
  map_skill("whip", "hellfire-whip");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: cast_spell, "gouhun" :),
//     (: perform_action, "whip", "three" :),
        }) );
  set("nk_gain", 600);
   
  set_temp("apply/armor", 50);
  set_temp("apply/dodge", 50);

  
  create_family("阎罗地府", 1, "你好");
  setup();
  
  carry_object("/d/obj/cloth/baipao")->wear();
  carry_object("/d/obj/weapon/whip/longsuo")->wield();
}

void attempt_apprentice(object ob, object me)
{
  if ( (string)ob->query("family/family_name")=="阎罗地府") {
    if (((int)ob->query("combat_exp") < 350000 )) {
      command("say " + RANK_D->query_rude(ob) + "这点三脚猫的把式也敢到我这里丢人现眼？");
      return;
    }
    command("grin");
    command("say 很好，" + RANK_D->query_respect(ob) +
       "多加努力，他日必定有成。\n");
    command("recruit " + ob->query("id") );
    return;
  }
  command("shake");
  command("say " + RANK_D->query_respect(ob) +
     "还是先去学些基础功夫吧！\n");
  return;
}


