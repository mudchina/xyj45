// npc: shijian.c
// Jay 3/26/96
#include <ansi.h>
inherit NPC;


void create()
{
	set_name("侍鞭", ({ "shibian"}) );
	set("nickname", HIM "鞭" NOR );
	set("gender", "女性" );
	set("age", 20);
	set("long", 	
		"她头上包着天青色纱巾，一领天青色布袍，没有一丝褶皱。\n");
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 30);
	set("shen_type", 0);
	set("max_neli",500);
	set("jiali",50);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("force",150);
	set_skill("sword",150);
	set_skill("parry",90);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",50);

	set("combat_exp", 250000);
	set("score",0);
	
	set("attitude", "peaceful");
        
	set("inquiry", ([
		"造鞭"  : "师傅命我帮助别人造鞭，但到现在也不见一个人影。谁要造鞭呢？\n",
		"原料"  : "造鞭只能用寒丝羽竹。\n",
	]) );

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_zhu","zhu");
}


int accept_object(object who, object ob)
{	
	if(!(who->query_temp("whip") ) ){
		message_vision(HIC"师傅没有同意为你造鞭，您请回吧！\n"NOR, who);
		return 1;
	}
	who->delete_temp("whip");
	who->set_temp("m_whip",1);
	switch ((string)ob->query("name") ) 
	{
		case "寒丝羽竹": 
			break;
		default :
			message("vision","这是什么！师傅说这不能用来打造长鞭！",who);
			return 0;
	}
	message("vision","侍鞭低头检视了一下手中的"+(string)ob->query("name")+
			"点了点头说：\n", who);
	message("vision","。。。好我们现在就开始造鞭！\n", who);
	write("请这位"+RANK_D->query_respect(who)+"给鞭起名字吧！(zhu 鞭的名字 英文代号)\n");
	return 1;

}

int do_zhu(string arg)
{
	string o_name,id,w_name;
	object whip,make_time;   //生成的武器句柄
	object me;
	me = this_player();
	if(!(me->query_temp("m_whip")) ) 
		return notify_fail("什么?\n");
	me->delete_temp("m_whip");
	me->delete_temp("get_orc");
	me->delete_temp("or");

	if((me->query("weapon/make")) ){
		say("侍鞭一脸茫然：您已经有一把自造的武器了，还来干什么？难到不可手么？\n");
		return 2;
	}
	if( !arg )
		return notify_fail("侍鞭认真的说：想好剑的名称及代号后在对我说。\n");

	sscanf(arg ,"%s %s" ,w_name ,id);
	if(!w_name||!id)
		return notify_fail("什么?(使用zhu 鞭的名字 英文代号\n)");
	o_name="寒丝羽竹";
	make_time=NATURE_D->game_time();
	message_vision(me->name()+"沉吟了一会，对侍鞭巧声说了几句话。侍鞭点了点头。说：好吧！\n",me );
	message_vision("\n侍鞭回过身，拿出一把寒气逼人的匕首，交到了$N的手中，自己拿出寒丝羽竹说：开始吧！\n",me );
	message_vision(HIB "$N双手紧紧握住匕首，用尽全身的力气向竹杆削去！\n" NOR,me);
	message_vision(RED "只听得嗤的一声轻响，匕首一滑竟刺到了$N的手上！\n" NOR,me );
	message_vision(YEL "$N只觉得手背的伤口一热，随着鲜血的流出，浑身的血液似乎都沸腾了起来！\n" NOR,me);
	message_vision(HIM "一身精血胶合着汩汩的内气，源源不断的向侍鞭手中的寒丝羽竹涌去\n" NOR,me );
	if( (me->query("qi"))<(me->query("max_qi")) || (me->query("jing"))<(me->query("max_jing")) || (me->query("neili"))<(me->query("max_neili")) )
	{
		message_vision(HIR "突然$N觉得伤口一阵巨痛，气血一阵翻涌，一口真气接不上来。。。。 \n" NOR, me);
		me->set("neili",0);
		me->unconcious();
		return 1;
	}
	message_vision(HIR "只听咯的一声轻响，一柄长鞭从炉中倏然跃起。化作一道青电猛的向$N的前胸刺来！！\n" NOR,me );
	say("侍鞭见状大叫：神鞭初成，人血以祭！！闪开！\n");
	message_vision("$N只觉得眼前一花，一条青影迅捷无比的挡在了$N的身前。\n",me );	
	message_vision(HIR "长鞭透胸穿出，侍鞭惨号一声，鲜血溅得$N满脸都是！\n" NOR,me );
	message_vision(RED "侍鞭脚下一个不稳，倒在了地上。侍鞭已经奄奄一息了。\n" NOR,me);
	this_object()->set("max_qi",10);
	message_vision("长鞭又飞了起来，飞到半空，扑的一声落回到地上。\n一室的劲气化于无形，一切又归于沉寂。\n",me );

	me->set("qi",0);
	me->set("jing",0);
	me->set("neili",0);

	me->set("weapon/make",1);		//武器制造后防止再造的标志		
	me->set("weapon/name",w_name);	//武器的名称
	me->set("weapon/id",id);		//武器的代号
	me->set("weapon/lv",1);    	//武器等级
	me->set("weapon/or",o_name);	//记录制造原料
	me->set("weapon/value",0);	      	//记录武器升级已有的点数	
	me->set("weapon/type","鞭");
	me->set("weapon/time",make_time);

	whip=new("/d/suburb/fy/npc/m_weapon/weapon/m_whip",1);	//生成新剑
	whip->move(this_player());
	message_vision("侍鞭摸起地上，带着斑斑血迹的长鞭，说：\n鞭。。已。。成。。，侍鞭的任务。。。也就完成了。。。。\n",me );
	say("侍鞭艰难的说：鞭。。您。。收好，我该走了。。。\n");
	message_vision("侍鞭说完。倏的便不见了。\n",me);
	this_object()->die();
	return 1;
}

