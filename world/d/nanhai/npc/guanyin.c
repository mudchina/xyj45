// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// guanyin.c 观音菩萨
// By Dream Dec. 19, 1996

inherit NPC;
inherit F_MASTER;

int do_drop(object, object);

void create()
{
   set_name("观音菩萨", ({ "guanyin pusa", "guanyin", "pusa" }));
   set("title", "救苦救难大慈大悲");
   set("long", @LONG
理圆四德，智满金身。眉如小月，眼似双星。兰心欣紫竹，
蕙性爱得藤。她就是落伽山上慈悲主，潮音洞里活观音。
LONG);
   set("gender", "女性");
   set("age", 35);
   set("attitude", "peaceful");
   set("rank_info/self", "贫僧");
   set("rank_info/respect", "菩萨娘娘");
   set("class", "bonze");
           set("str",24);
   set("per",100);//means no rong-mao description.
   set("max_kee", 5000);
   set("max_gin", 5000);
   set("max_sen", 5000);
   set("force", 4000);
   set("max_force", 2000);
   set("force_factor", 145);
   set("max_mana", 3000);
   set("mana", 6000);
   set("mana_factor", 150);
   set("combat_exp", 2000000);
   set_skill("literate", 150);
   set_skill("spells", 200);
   set_skill("buddhism", 200);
   set_skill("unarmed", 150);
   set_skill("jienan-zhi", 150);
   set_skill("dodge", 180);
   set_skill("lotusmove", 160);
   set_skill("parry", 150);
   set_skill("force", 180);
   set_skill("lotusforce", 180);
   set_skill("staff", 150);
   set_skill("lunhui-zhang", 180);
   set_skill("spear", 150);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
   }) );
   //hehe, since guanyin was killed several times
   //let's use cast bighammer to protect her...weiqi:)
   create_family("南海普陀山", 1, "菩萨");

   setup();
   carry_object("/d/nanhai/obj/jiasha")->wear();
   carry_object("/d/nanhai/obj/nine-ring")->wield();
}

void attempt_apprentice(object ob)
{
   if (!((string)ob->query("bonze/class") =="bonze" )) {
     command("say 我佛门神通广大，" + RANK_D->query_respect(ob) + "欲成正果，先入我门。\n");
     write("看样子观音菩萨对你未剃度出家颇为不快。\n");
     return;
   }   
   if (((int)ob->query_skill("buddhism", 1) < 80 )) {
     command("say " + RANK_D->query_respect(ob) + "不在佛法上苦修，恐怕难成正果。\n");
     return;
   }
   command("pat " + ob->query("id") );
   command("say 好！这才是我佛门的好弟子。只要多加努力，定可早成正果。\n");

   command("recruit " + ob->query("id") );
   return;   
}
void die()
{
   int i;
   string file;
   object *inv;

        if( environment() ) {
        message("sound", "\n\n观音菩萨摇头叹道：刚离迷障，又入魔障，世间疾苦，何人度之！\n\n", environment());
        command("sigh");
        message("sound", "\n观音菩萨驾祥云，登彩雾，径往西方去了。。。\n\n", environment());
        inv = all_inventory(this_object());
   for(i=0; i<sizeof(inv); i++) {
     if (inv[i]->query("no_drop")) continue;
     do_drop(this_object(), inv[i]);
//     if (stringp(file = find_command("drop")) && 
//        call_other(file, "do_drop", this_object(), inv[i])) ;
   }
   }

   destruct(this_object());
}

int do_drop(object me, object obj) {
  if (obj->move(environment(me))) {
      //d_mana>0 is for "bian". mon 11/05/97
      if((obj->query_temp("d_mana"))>0) {
            if( obj->query_temp("is_living")==1 )
                 message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
            else {
                 message_vision( sprintf("$N丢下一%s$n。\n",
                 undefinedp(obj->query_temp("unit"))?
                    "个":obj->query_temp("unit")
                         ), me, obj );
           }
      } else {
           if( obj->is_character() )
                  message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
           else {
             message_vision( sprintf("$N丢下一%s$n。\n", obj->query("unit")),
                     me, obj );
             if( !obj->query("value") && !obj->value() ) {
                tell_object(me,"因为这样东西并不值钱，所以人们并不会注意到它的存在
        。\n");
                destruct(obj);
             }
           }
      }
      return 1;
  }
  return 0;
}


void unconcious()
{
   die();
}

