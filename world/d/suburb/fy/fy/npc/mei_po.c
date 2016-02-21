// mei_po.c
#include <ansi.h>

inherit NPC;

string marry();
string unmarry();

void create()
{
        set_name("媒婆", ({ "mei_po" }) );
        set("title", "鸳鸯亭");
        set("gender", "女性" );
        set("age", 43);
        set("long",
                "一位精明能干的老媒婆\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("inquiry", ([
                "婚约" : "是啊... 这里就可以缔结和解除婚约",
        ]) );
        set_skill("literate", 70);
        set_skill("dodge", 500);
        set_skill("unarmed", 300);
        setup();
        carry_object("/obj/cloth")->wear();

        add_money("gold", 5);
}

void init()
{
        object ob;

        ::init();
        add_action("do_marry", "marry");
        add_action("do_unmarry", "unmarry");
}

int do_marry(string arg) {
        object obj, me;
        object ob;
        int i;

        me = this_player();
	if( me->query("marry"))	
	                return notify_fail(
                "你已经和别人有婚约了吧?这里不允许重婚的。\n");
        
        if(!arg || !objectp(obj = present(arg, environment(me)))
                )
                return notify_fail("你想和谁缔结良缘？\n");

	if( obj->query("marry"))
               return notify_fail(
                "你的对象已经和别人有婚约了吧?这里不允许重婚的。\n");


        if( !living(obj) )
                return notify_fail(obj->name() + 
                "已经无法和你缔结良缘了。\n"); 

        if(obj==me)     return notify_fail("你是自恋狂吗？\n");
	if(!userp(obj)) return notify_fail("你只可和玩家联婚．\n");
        if((string)obj->query("gender")== (string)me->query("gender"))
                return notify_fail("同性恋？太领先于时代了吧？\n");

        if ( (((int)me->query("age")<18)&&
                ((string)me->query("gender")=="男性")) ||
              (((int)me->query("age")<16) &&
                ((string)me->query("gender")=="女性")) )
                return notify_fail("你太小啦，怎么可以啦？\n");  

        if( userp(obj) && !obj->query_temp(me->query("id") + "m"))
	{
                message_vision(MAG "\n$N对著$n说道：" 
                    + RANK_D->query_self(me) 
                    + me->name() + "，愿意和"
                    + RANK_D->query_respect(obj) + 
                "结为夫妇\n\n"NOR, me,obj);           
                 me->set_temp(obj->query("id") + "m",1);
           tell_object(obj, MAG "如果你愿意和对方结为夫妇，请你也对" 
                        +me->name() + "("+(string)me->query("id")+
                        ")"+ "下一次 marry 指令。\n" NOR);
                write(MAG  
                        "现在你急切盼望着你的心上人说同意...\n" NOR);
                return 1;
        }
        
	me->set("marry",obj->query("id"));
	obj->set("marry",me->query("id"));
        
        message_vision(MAG "恭喜 $N 和 $n ，一对璧人喜结良缘。\n" NOR,
        obj, me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s 和 %s 现在开始是夫妇啦! \n", 
        me->name(1), obj->name(1)));


        return 1;
}

int do_unmarry(string arg)
{
        object marry_card1,marry_card2,  me;
        object couple_ob;
        int i, have_marry;
        string target, tmpstr1, tmpstr2,str1,str2;
        string cardname;
             
        me = this_player();       
        if (!me->query("marry"))
                return notify_fail("你还未有婚约啊。\n");
        
	target = (string) me->query("marry");        

         if(!objectp(couple_ob = present(target, environment(me)))
                 )
                return notify_fail("你的伴侣现在不在场.\n");


        if( userp(couple_ob) && !couple_ob->query_temp(me->query("id")+"d"))
                {
                message_vision(MAG "\n$N对著$n说道：" 
                        + RANK_D->query_self(me) 
                        + me->name() + "，咱们解除婚约吧!好吗?\n\n"
                        NOR, me, couple_ob);           
                 me->set_temp(couple_ob->query("id")+"d",1);
           tell_object(couple_ob, MAG "如果你愿意解除婚约，请你也"
                + "下一次 unmarry 指令。\n" NOR);
                write(MAG  
                "现在你只有等着" +couple_ob->query("name")+"同意啦...\n" NOR);
                return 1;
        }

        
        message_vision(MAG " $N 和 $n 从现在开始解除婚约,互不相干!\n" NOR,
        couple_ob, me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s 和 %s 从现在开始解除婚约,互不相干! \n", 
        me->name(1), couple_ob->name(1)));
	me->set("marry",0);
	couple_ob->set("marry",0);
	me->add("divorced",1);
	couple_ob->add("divorced",1);
        return 1;
}
