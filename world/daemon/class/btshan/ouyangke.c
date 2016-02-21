//NPC /d/baituo/npc/ouyangke.c
#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void greeting(object ob);
int accept_object(object who, object ob);
void create()
{
	seteuid(getuid());
	set_name("欧阳克", ({ "ouyang ke", "ouyang", "ke" }));
	set("long", "他一身飘逸的白色长衫，手摇折扇，风流儒雅。\n");
	set("title", "白驼山少庄主");
	set("nickname", HIM "玉面蛇心" NOR);
	set("gender", "男性");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("per", 26);

	set("sen", 1000);
	set("max_sen", 1000);
	set("gin", 800);
	set("max_gin", 800);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 10);

	set("combat_exp", 200000);
	set("score", 40000);

	set_skill("unarmed", 100);
	set_skill("hand", 80);
	set_skill("dodge", 120);
	set_skill("parry", 90);
	set_skill("force", 90);
	set_skill("staff", 80);
	set_skill("hamagong",90);
	set_skill("chanchu-bufa", 100);
	set_skill("shexing-diaoshou", 100);
	set_skill("lingshe-zhangfa", 100);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

	set("startroom","/d/city/beidajie1");

        create_family("白驼山派",2,"弟子");

	set("chat_chance", 10);
	set("chat_msg", ({
		"欧阳克唱道: 漂亮姑娘你请留步￣￣让我多看你一眼￣￣\n",
		"欧阳克色迷迷地看着街边的小姑娘。\n",
		"欧阳克把纸扇一展，转过身去，深情地吟道：红颜知己最难得￣\n",
		(: random_move :)
	}) );

	setup();
	carry_object("/d/baituo/obj/baipao")->wear();
	add_money("silver",10);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) 
       {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("gender")=="女性")
	{
	   switch(random(3))
	   {
		case 0:command("rose "+(string)ob->query("id"));break;
	  	case 1:command("kiss "+(string)ob->query("id"));break;
	   	case 2:command("love "+(string)ob->query("id"));break;
	   }
     
	}
	else
           say("欧阳克叹了一口气说：这位"+RANK_D->query_respect(ob)+
               ",你要是能给我弄一个女人来就好了。\n");
	return;
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") == "白驼山派")
	{
	     if((int)ob->query("combat_exp")<10000)
	       command("say 你的经验太低，我还不能收你。继续努力吧。\n");
	     else
               {command("say 你跟着我要好好学。\n");               
	        command("recruit "+ob->query("id"));
                 }
	      return;
	}
	if ((string)ob->query("gender") == "女性")
		message_vision("欧阳克动情地说道：这位" + RANK_D->query_respect(ob) +
		"真乃我的红颜知己，\n我现在还不能收你，只能送你上白驼山。\n",ob);
	else
		message_vision("欧阳克笑笑说：这位"+RANK_D->query_respect(ob)+
		"，我现在还不能收你，只能送你上白驼山。\n",ob);
     write(HIY "只见欧阳克把纸扇往你眼前一晃，\n
     你觉得眼前一闪，身体轻飘飘地飞了出去￣￣\n" NOR);
     ob->move("/d/baituo/lianagong");

}

int accept_fight(object ob)
{
	if ((string)ob->query("gender") == "女性")
	{
		message_vision("欧阳克摆摆手说道：这位"+RANK_D->query_respect(ob)+
		"，我怎能欺负女孩子呢！\n", ob);
		return 0;
        }
          if ((string)ob->query("family/family_name") == "白驼山派")
	 {
	  if((int)ob->query("combat_exp")<100000)
	    return notify_fail("欧阳克笑道：你的经验太低了,再练几年吧。！\n");
	  }
	message_vision("欧阳克一拱手说道：这位"+RANK_D->query_respect(ob)+
	"，在下领教了。\n", ob);

	return 1;
}
 
int accept_object(object who, object ob)
{
	object obn;
          if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	
	if ( !present(ob, who) ) {say("你没有这件东西。\n"); return 0;}

	if (  (string)ob->query("gender") != "女性")
	{	say("欧阳克不需要这件东西。\n"); return 0;}
	
	if ( (int)ob->query("age") <18 )
	{	say("欧阳克大惊失色道：未成年少女我怎敢要！\n"); return 0;}
        if ( (int)ob->query("age") >40 )
	{	 say("欧阳克轻蔑地一笑道：这种老古董还是留给你自己吧！\n"); return 0;}

			  
	obn=new("/clone/money/silver");
        obn->set_amount(30);
        obn->move(who);
        message_vision("欧阳克一把把"+ob->query("name")+"揽在怀里，对$N说这点银子是你的辛苦费，
              咱回头见。\n说完，就携着"+ob->query("name")+"往丽春院奔去...\n",who);
        move("/d/city/lichunyuan");
        return 1;
}
