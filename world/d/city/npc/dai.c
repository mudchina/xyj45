// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
string send_mail();
string receive_mail();

void create()
{
        set_name("戴文重", ({"dai wenzhong", "dai"}));
        set("age", 42);
        set("gender", "男性");
        set("long",
"驿站里的当家，长的圆圆胖胖的。\n");
   set("title", "驿站当家");
        set("attitude", "peaceful");

        set("combat_exp", 40000);
        set("shen_type", 1);
   set("max_force", 300);
   set("force", 300);
   set("force_factor", 5);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_skill("parry", 40);
        set("inquiry", ([
                "发信" : (: send_mail :),
                "收信" : (: receive_mail :),
                "信件" : (: receive_mail :),
                "信" : (: receive_mail :),
                "mail" : "您讲的是外国话吧？我听不懂耶~~~~~~~~",
        ]) );

   setup();
        carry_object(__DIR__"obj/choupao")->wear();
}
string send_mail()
{
        object mbox;

        if( this_player()->query_temp("mbox_ob") )
                return "你的信箱还在吧？用信箱就可以寄信了。\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "等一下到驿站来找我吧。\n";
        seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return "哦...
要寄信是吗？这是你的信箱，寄信的方法信箱上有说明。\n";
}

string receive_mail()
{
        object mbox;

        if( this_player()->query_temp("mbox_ob") )
                return "你的信箱还在吧？你所有的信都在里面。\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "等一下到大石头来找我吧。\n";
        seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return
"好，待我找找....有了，你的信箱在这，慢慢看吧，不打搅你了。\n";
}

