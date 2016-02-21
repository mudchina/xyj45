// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit F_VENDOR_SALE;

int base_price=100000;

int ask_party();
int ask_money();
void create()
{
   reload("xifuhui");
        set_name("老害虫", ({"xifuhui boss","boss" }));
   set("title", "喜福会老板娘");
   
        set("age", 32);
        set("gender", "女性");
        set("attitude", "friendly");

        set("combat_exp", 50000);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
   set("per", 20);

set("inquiry", ([
"name": "在下便是这里的老板。\n",
"here": "这里是喜福会，城中大户人家结婚都要来这里摆喜宴哩。\n",
"宴" : (: ask_party :),
"喜宴" : (: ask_party :),
"席" : (: ask_party :),
"酒席" : (: ask_party :),
"party" : (: ask_party :),
"money": (: ask_money :),
]) );
        setup();
        carry_object("/d/obj/cloth/pink_cloth")->wear();
}

void init()
{
    ::init();
   add_action("do_serve", "serve");
   add_action("do_finish", "finish");
   add_action("do_start", "start");
     add_action("do_fight", "fight");
     add_action("do_kill", "kill");
     add_action("do_steal", "steal");
     add_action("do_cast", "cast");
     add_action("do_exert", "exert");
     add_action("do_perform", "perform");
     add_action("do_bian", "bian");
   add_action("do_fight", "fight");

}
int ask_party()
{   object me, who, wife;
   me=this_object();
   who=this_player();
//   if( !who->query("married") ) {
//     message_vision("$N看着$n大笑起来：你还没结婚呢，开什么喜宴！\n", me, who);
//     return 1;
//   }
//   if( who->query("married_party") ) {
//     message_vision("$N看着$n迟疑的问道：你不是已经开过喜宴了吗？\n", me, who);
//     return 1;
//   }
   if( who->query_temp("host_of_party") ) {
     message_vision("$N对$n说：这不是正开着喜宴呢吗？\n", me, who);
     return 1;
   }
//   if( (string)who->query("gender")=="女性" ) {
//     message_vision("$N皱了皱眉，对$n说道：还是叫你的丈夫来办这件事吧！\n", me,who);
//     return 1;
//   }
//   if( !objectp(wife=present(who->query("couple/id"), environment(who))) ) {
//     message_vision("$N对$n说：新娘子都没来，这喜宴怎么开？\n", me, who);
//     return 1;
//   }
   if( me->query_temp("ready_to_party") ) {
     message_vision("$N对$n不好意思的说：我这正开着一席呢，要不您明儿再来吧！\n", me, who);
     return 1;
   }
   if( (string)environment(me)->query("short")!="喜福会" ) {
     message_vision("$N对$n为难的说：现在这里也没准备，我是难以相助啊！\n", me, who);
     return 1;
   }
   if( who->query_temp("ready_to_pay") ) {
     message_vision("$N对$n不奈烦的说道：你怎么问个没完！\n", me, who);
     return 1;
   }
   if( !who->query_temp("party_paid") ) {
     message_vision("$N对$n说：这一次喜宴吗，可要花费"+
        price_string(base_price*query_price()/10)+
        "呢！\n", me, who);
     who->set_temp("ready_to_pay", 1);
     return 1;
   }
}
int accept_object(object who, object ob)
{
   object m;
   int value;
   int price;

   value=ob->value();

   if( !who->query_temp("ready_to_pay") )
     return notify_fail(name()+"迟疑的看着你，不知道你想干什么！\n");

   if( !value )
     return notify_fail(name()+"奇怪的看着你说：给我这干什么？\n");

   price=base_price*query_price()/10;

   if( value < price )
     return notify_fail(name()+"说：这些哪够呀，要"+
        price_string(price)+"才行！\n");
   if(!take_money(value, base_price))
       return 0;
   this_object()->save();
   who->set_temp("host_of_party", 1);
   who->delete_temp("ready_to_pay");
   call_out("destroy", 1, ob);

   call_out("count_money", 2, who);
   call_out("start_party", 5, who);
   return 1;
}

int ask_money()
{
   object who=this_player();
   int i;
   i=(int)this_object()->query("money")+160;
   if( who->query("id")!="bula"){ 
     command("dunno");
     return 1;
   }
   command("whisper bula 这个月生意不错，到现在共赚了"
+chinese_number(i)+"两金子了。\n");
   return 1;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}
void count_money(object who)
{
   message_vision("\n$N把$n给的钱仔细的清点了一遍。\n\n", this_object(), who);
   message_vision("$N痛快的说：开席！\n", this_object() );

}

void start_party(object who)
{
   object me=this_object();
   command("chat* "+name()+
          "：各位老爷太太少爷小姐，今日" + who->query("name") +  
"在喜福会大开酒席，欢迎各位前来捧场！");
   command("say 您要开始(start)，我便开席。您要上菜(serve)，我就上菜，等您吃饱了，玩腻了，咱就结束(finish)。");
   me->set_temp("ready_to_party", 1);
}
int do_start()
{   
   object who = this_player();
        object me = this_object();
   int i;
   object *list;
   object girla,girlb,girlc,girld,cup;
   if( !who->query_temp("host_of_party") )
     return notify_fail(name()+"对你说：你又不是新郎官！\n");
   if( !me->query_temp("ready_to_party") )
     return notify_fail(name()+"对你说：开始什么呀，现在又没人结婚！\n");
   if( me->query_temp("party_start_already") )
     return notify_fail(name()+"生气的对你说：这不是已经开始了嘛！\n");

   message_vision("$N大声对$n说：老板，开席！\n\n", who, me);
   message_vision("$N大声喊着：开～～席～～喽～～\n\n", me);
   me->set_temp("party_start_already", 1);
   me->delete_temp("ready_to_party");
   tell_room( environment(who), "旁边四个唢呐手大声的吹起了欢快的唢呐。\n");   

   list = all_inventory(environment(me));
   i = sizeof(list);
   while (i--)
   {
       object ob= list[i];
      if( cup=new("/d/obj/food/dishes/cup"))
       cup->move(ob);
   }
   seteuid(getuid());
   if(girla=new("/d/city/npc/girla"))   
    girla->move(environment(me));

        seteuid(getuid());
        if(girlb=new("/d/city/npc/girlb"))
        girlb->move(environment(me));

        seteuid(getuid());
        if(girlc=new("/d/city/npc/girlc"))
        girlc->move(environment(me));

        seteuid(getuid());
        if(girld=new("/d/city/npc/girld"))
        girld->move(environment(me));

   tell_room(environment(who), "内堂走出几个漂亮的小姑娘。\n");
   tell_room(environment(who), "你得到了一个白玉酒盏。\n");
   call_out("finish_party", 500, who);
   return 1;
}
int do_serve()
{
   object me=this_object();
   object who=this_player();
   object food;
   if( !who->query_temp("host_of_party") )
     return notify_fail(name()+"对你嚷道：主人还没说话，你嚷个什么劲！\n");
   if( !me->query_temp("party_start_already") )
     return notify_fail(name()+"对你说：你还没宣布开始(start)，怎么上菜呢？\n");
   if ( (present("food 2", environment(me))) )
     return notify_fail(name()+"对你说：慢慢吃，吃完自然会给你上菜。\n");

   message_vision("$N大声嚷嚷着：上菜，上菜！\n", who);

   tell_room(environment(me), "从内堂跑出四五个小伙计，手脚麻利的将桌上的剩菜饭端了下去。\n");
   tell_room(environment(me), "小伙计又从内堂出来，端上了一桌新的酒席。\n");
        if(food=new("/d/obj/food/dishes/food"))
        food->move(environment(me));
   if(food=new("/d/obj/food/dishes/food"))
        food->move(environment(me));
   if(food=new("/d/obj/food/dishes/food"))
        food->move(environment(me));
   if(food=new("/d/obj/food/dishes/food"))
        food->move(environment(me));
   return 1;
}
int do_finish()
{
   object me=this_object();
   object who=this_player();

   if( !who->query_temp("host_of_party") )
     return notify_fail(name()+"瞪了你一眼：别乱说话！\n");

   if( !me->query_temp("party_start_already") )
     return notify_fail(name()+"瞪了你一眼：不是已经结束了吗！\n");
   message_vision("$N对$n说道：吃饱喝足，多谢老板招待！\n", who, me);
   remove_call_out("finish_party");
   call_out("finish_party", 3, who);
   return 1;
}
void finish_party(object who)
{
   object me=this_object();
        int i;
        object *list;

   message_vision("$N大声说道：宴席就此结束，多谢大家光临！\n", me);
   command("gongxi " + who->query("id"));

   me->delete_temp("party_start_already");
   who->delete_temp("host_of_party");
//   who->set_temp("married_party", 1);
   list=all_inventory(environment(me));
   i=sizeof(list);
   while (i--)
   {
     if(list[i]->query("id") != "ban niang")
        continue;
     else
        destruct (list[i]);
   }
}
int do_fight(string arg)
{
        object who = this_player();
        object me = this_object();
        message_vision("$N脸色不大对，好象动了杀机！\n", who);
        message_vision("$N对$n直摇头：这大喜的日子动什么刀枪啊！\n", me, who);
        return 1;
}

int do_kill(string arg)
{
     object who = this_player();
    object me = this_object();

   if(!arg || present(arg,environment(me))!=me) return 0;

   message_vision("$N脸色不大对，好象动了杀机！\n", who);
   message_vision("$N对$n直摇头：这大喜的日子动什么刀枪啊！\n", me, who);
   return 1;
}
int do_cast(string arg)
{
        object who = this_player();
        object me = this_object(); 
   message_vision("$N张开嘴，结结吧吧地念了几声咒语。\n", who);
        message_vision ("$N对$n直摇头：这大喜的日子，你念哪门子咒啊！\n", me, who);
        return 1;
}        
int do_exert(string arg)
{               
        object who = this_player();
        object me = this_object();
   message_vision("$N鬼鬼祟祟地一运气。\n",who);
        message_vision("$N对$n吐吐舌头，说：刚吃过饭，不要乱用内功！\n", me, who);
        return 1;
}
int do_perform(string arg)
{
        object who = this_player();
        object me = this_object();
   message_vision("$N脸色不大对，好象动了杀机！\n", who);
        message_vision ("$N对$n直摇头：这大喜的日子动什么刀枪啊！\n", me, who);  
        return 1;
}        
int do_steal(string arg)
{       
        object who = this_player();
        object me = this_object();
   message_vision("$N伸出手，想要偷点什么。\n", who);
        message_vision ("$N对$n骂道：怎可随便光天化日施盗行窃！\n",me,who);
     return 1;
}

int do_bian(string arg)
{
     object who = this_player();
     object me = this_object();
   message_vision("$N鬼鬼祟祟地想变成什么东西。\n",who);
   message_vision("$N对$n说：这是喜宴，不可随意变化！\n",me,who);
        return 1;
}

