// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("殷开山", ({ "yin kaishan", "yin", "kaishan" }));
        set("title", "大总管");
        set("gender", "男性");
        set("age", 70);
        set("str", 20);
        set("dex", 20);
        set("long", "他就是当朝大总管殷开山，举手投足之间，不怒自威。\n");
        set("combat_exp", 80000);
        set("attitude", "friendly");
   set("force_factor", 10);
        set_skill("unarmed", 80);
        set_skill("dodge",80);
        set_skill("parry", 80);
   set("max_kee", 700);
   set("max_sen", 700);
        set("force", 500); 
        set("max_force", 500);

        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("silver", 20);

}

int accept_object(object who,object ob)
{
   int val;
   val = ob->value();
   if( !val )
                return notify_fail("殷开山笑道：我是不会收的，你拿回去吧！\n");
   if (val < 5000) {
   write("殷开山笑道：国子监每月柴油需五十两白银！\n");
   return 0;
   }
        who->set("guozi/paid", 1);
        call_out("destroy", 1, ob);
        return 1;
}

void destroy(object ob)
{
        destruct(ob);
        return;
}

