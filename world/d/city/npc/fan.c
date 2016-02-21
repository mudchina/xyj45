// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("范青屏", ({"fan qingping", "fan"}));
        set("age", 72);
        set("gender", "男性");
        set("long",
"范老拳师壮年时也是响当当的英雄，现在虽老了，手脚利落却不输当年．\n");
   set("title", "拳盖三省");
        set("attitude", "friendly");
   set("max_kee", 800);
   set("max_sen", 700);
        set("combat_exp", 100000);
        set("shen_type", 1);
   set("max_force", 300);
   set("force", 300);
   set("force_factor", 15);
        set_skill("unarmed", 100);
   set_skill("changquan", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
   map_skill("unarmed", "changquan");
   set("chat_chance",1);
        set("chat_msg", ({
        "范青屏叹道：腿脚不利落了，也没人去给我提笼小二的包子来。\n",
}));
   setup();
        carry_object("/d/obj/cloth/choupao")->wear();
   carry_object("/d/obj/book/quanjing");
}

int accept_object(object who,object ob)
{
        if (ob->query("id")=="zhurou bao"){
   command("say 嘿嘿，老二这包子是越做越小了。\n");
   command("say 不过还是要谢谢你呀！\n");
   command("give jing to " + who->query("id"));
   return 1;
   }
   return 0;
}


