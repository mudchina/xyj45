// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// longear.c
// 1996/12/06 by cglaem

inherit NPC;

string send_mail();
string receive_mail();

void create()
{
   set_name("顺风耳", ({ "longear", "youchai","chai" }) );
   set("title", "邮差");
   set("gender", "男性" );
   set("age", 30);
   set("long",
     "前玉皇大帝亲信。因为偷听玉皇大帝跟嫦娥调情而被罚为邮差。\n");
   set("combat_exp", 8000);
   set("attitude", "friendly");
   set("inquiry", ([
                        "name":"连我你都不认识？大名鼎鼎的顺风耳就是我。", 
     "here" : "鬼知道这是什么地方！我只负责收信发信。",
                        "嫦娥" : "唉...可惜只闻其声未见其人。",
                        "玉皇大帝" : "你别提他！一提我就有气...只许州官放火，不许百姓点灯。",
     "发信" : (: send_mail :),
     "收信" : (: receive_mail :),
     "信件" : (: receive_mail :),
     "信" : (: receive_mail :),
     "mail" : "您讲的是外国话吧？我听不懂耶~~~~~~~~",
   ]) );
   set_skill("literate", 70);
   set_skill("dodge", 50);
   set_skill("unarmed", 40);
   set("per", 15);
            set("max_kee", 500);
            set("max_gin", 100);
            set("max_sen", 300);
            set("force", 150);
            set("max_force", 300);
            set("force_factor", 0);
   setup();
   add_money("coin", 70);
   carry_object("/d/ourhome/obj/linen")->wear();
}

string send_mail()
{
   object mbox;

   if( this_player()->query_temp("mbox_ob") )
     return "你的信箱还在吧？用信箱就可以寄信了。\n";
   if( !environment()
   ||   base_name(environment()) != query("startroom") )
     return "等一下到大石头来找我吧。\n";
   seteuid(getuid());
   mbox = new(MAILBOX_OB);
   mbox->move(this_player());
   return "哦... 要寄信是吗？这是你的信箱，寄信的方法信箱上有说明。\n";
}

string receive_mail()
{
   object mbox;

   if( this_player()->query_temp("mbox_ob") )
     return "你的信箱还在吧？你所有的信都在里面。\n";
   if( !environment()
   ||   base_name(environment()) != query("startroom") )
     return "等一下到大石头来找我吧。\n";
   seteuid(getuid());
   mbox = new(MAILBOX_OB);
   mbox->move(this_player());
   return "好，待我找找....有了，你的信箱在这，慢慢看吧，不打搅你了。\n";
}
