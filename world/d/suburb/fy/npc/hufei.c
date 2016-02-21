// hufei.c

inherit NPC;
string ask_me();
void do_kill(object ob);

void create()
{
	set_name("胡斐", ({"hu fei", "hu", "fei"}));
	set("gender", "男性");
	set("nickname", "雪山飞狐");
	set("age", 25);
	set("long", 
		"他就是胡一刀之子，因其武功高强神出鬼没。\n"
		"在江湖上人送外号「雪山飞狐」。\n"
		"他身穿一件白色长衫，腰间别着一把看起来很旧的刀。\n"
		"他满腮虬髯，根根如铁，一头浓发，却不结辫。\n");
	set("attitude", "peaceful");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("chat_chance", 20);
	set("chat_msg", ({
		"胡斐叹了口气道:“不知什么时候还能再见到若兰姑娘。\n",
		"胡斐恨恨道：“苗人凤是我杀父仇人，我必报此仇！”\n",
		(: random_move :),
	}));
	
	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 190000);
	set("score", 20000);
	 
	set_skill("force", 110);             // 基本内功
	set_skill("hujia-daofa", 150);    // 胡家刀法	
	set_skill("blade", 120);           // 基本刀法
	set_skill("hunyuan-yiqi", 120);   // 混元一气功
	set_skill("dodge", 120);           // 基本躲闪
	set_skill("shaolin-shenfa", 120);   // 胡家身法
	set_skill("parry", 120);             // 基本招架
		
	map_skill("force", "hunyuan-yiqi");
	map_skill("blade", "hujia-daofa");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "hujia-daofa");
   	set("inquiry",([
		"宝刀": (: ask_me :),
             	]));
	set("baodao_count",1);
    setup();
	carry_object(__DIR__"obj/cwbdao")->wield();
    carry_object("/d/suburb/fy/city/obj/cloth")->wear();
 
}

string ask_me()
{
	
	
	object ob, me;
	
	me = this_player();
	if((int)me->query("shen") < 0)
	{
//		me->set_leader(ob);
		call_out("do_kill",1,this_player());
	}
	else if((int)(me->query("shen")<100000))
	    return "以你目前的作为是不能拿这把刀的。\n";

   	else if((int)(me->query("shen") > 100000))
	{
		if(query("baodao_count") > 1){		
    		call_out("waiting",0,me,ob);
			add("baodao_count", -1);
    		ob = new ("/clone/weapon/cwbdao");
    		ob->move(this_player());
			return " 好吧，这把闯王宝刀就赠与你，希望你好好利用它。\n";
		}
		else return "你来晚了, 现在这把刀已不在此处。\n";
	}

}

void do_kill(object ob)
{
	object me, room1;       
    me = this_object();
    room1 = environment(me);
 
    if (room1->query("no_fight"))
	    room1->set("no_fight", 0);
 
    if (interactive(ob))
    {
        command("say 你这恶贼竟敢打我宝刀的主意, 给我纳命来！\n");
        me->set_leader(ob);
        remove_call_out("kill_ob");
        call_out("kill_ob", 1, ob);
    }
 
}	

