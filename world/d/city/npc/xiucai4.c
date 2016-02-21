// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
string apply_gongming(object me);

void create()
{
        set_name("贺知章", ({"he zhizhang", "he", "zhizhang"}));
        set("gender", "男性");
        set("age", 55);
   set("title", "国子监大学士");
        set("str", 25);
   set("int", 30);
        set("long", "贺知章是国子监大学士，统管全国文人考试及升级。\n");
        set("combat_exp", 30000);
        set("attitude", "friendly");
        set("class", "scholar");
        set_skill("unarmed", 50);
        set_skill("dodge",50);
   set_skill("literate", 100);
        set_skill("parry", 50);

        set("force", 500); 
        set("max_force", 500);
   set("inquiry", ([
     "name" : "薄名何足挂齿...老夫贺知章蒙皇上恩赏国子监大学士，实是愧不敢当。\n",
     "here" : "这里便是国子监。\n",
     "读书识字": "对了，你是来对地方了！\n",
     "学习" : "只要总管府认定，我们就收！\n",
     "功名" : (: apply_gongming :),
        ]) );
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}
int recognize_apprentice(object ob, object who)
{
   object tongpai;
        if( !tongpai = present("tong pai", ob))
return notify_fail("贺知章笑道：没有总管府的认可，我是不敢乱收学生的！\n");
   if((string)tongpai->query("player") != (string)ob->id())
return notify_fail("贺知章瞪了你一眼，学文之人怎可作弊！！？\n");
        return 1;
}

string apply_gongming(object me)
{
        me=this_player();
        if( me->query("class") != 0 ) //means already has a class
        {
                return "功名富贵都是过眼云烟，又何必挂在心上？\n";
        }
        else
        {
                message_vision("贺知章说道：功名富贵都是过眼云烟，又何必挂在心上？\n", me);
                message_vision("贺知章对$N叹了口气道：既然你如此热衷...\n", me);
                me->set("class", "scholar");
                if( me->query_skill("literate", 1) < 20 )
                        return "以阁下的才识，还只能从童生做起。\n";
                else if( me->query_skill("literate", 1) < 100 )
                        return "以阁下的才识，做个秀才还是可以的。\n";
                else    return "以阁下的才识，做个大学士没问题。\n";
        }
}

