// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// yuelao.c 月下老人
// AceP
// mon 1/2/97

inherit NPC;

int do_register();
int do_zuomei(string);
int do_divorce(string);

void create()
{
   set_name("月下老人", ({ "yuexia laoren", "yuelao", "laoren" }));
   set("long", 
"他就是专管天上地下姻缘的月下老人了。
他满脸红光，须眉皆白，正坐在那儿翻看一本书，
手上黏着一根红绳，口中正自言自语着些什么。\n");
   set("gender", "男性");
   set("per", 100);
   set("age", 101);
   set("attitude", "friendly");
   set("str", 30);
   set("int", 30);
   set("con", 30);
   set("per", 25);
      
   set("max_kee", 1200);
   set("max_gin", 1000);
   set("max_sen", 1200);
   set("force", 1000);
   set("max_force", 1000);
   set("max_mana", 1200);
   set("mana", 1200);
   set("combat_exp", 500000);

   set_skill("force", 100);
   set_skill("dodge", 100);
   set_skill("unarmed", 100);
   set_skill("parry", 100);
   set_skill("literate", 150);

   set("inquiry", ([
     "name" : "区区正是月老，在此负责天上地下所有的姻缘，已有不知道多少年了。",
     "here" : "这儿就是我办公的地方，所有的姻缘都是我在这儿偷偷牵的线，也是在这儿注册完婚的。",
     "结婚" : "想结婚？你要找到你命中注定的那姻缘，然后一起到这里来登记完婚。",
     "离婚" : "唉，世道变了，这年头人心不古，离婚率高得可怕。唉，不管怎样，我也负责处理离婚(divorce)申请。",
     "做媒" : "媒人是结婚必不可少的证人，做媒(zuomei)的负责给女方做证。",
       ]) );

   setup();
}

void init()
{
   add_action("do_divorce", "divorce");
   add_action("do_zuomei", "zuomei");
   add_action("do_propose", "propose");
   add_action("do_marry", "marry");
}


int do_propose(string arg)
{
   object me,who;
   me=this_player();
        if(me->query("age") < 16)
           return notify_fail("小孩子一边玩儿去。\n");

        if (!arg) return notify_fail("你要向谁求婚？\n");

        if (me->query("gender")=="女性")
                return notify_fail("只有男人才能向别人求婚！\n");

        if (!objectp(who=present(arg,environment(me))))
                return notify_fail("这里没有这个人。\n");

        if (!who->is_character())
                return notify_fail("想清楚！"+who->name()+"是什么呀！\n");

        if (who==me)
                return notify_fail("开什么玩笑？！？\n");

        if (who->query("gender")=="男性")
                return notify_fail("嗯？你变态吗？！？\n");

        if (me->query("married"))
                return notify_fail("嘿嘿，不怕" + me->query("couple/name") + "揍你吗？\n");

        if (!living(who))
                return notify_fail("嗯...你还是先把"+who->name()+"弄醒吧。\n");


   if ((me->query("bonze/class")=="bonze")||(who->query("bonze/class")=="bonze"))
     return notify_fail("出家人四大皆空，婚嫁之事就免了吧。\n");

        if (who->query("married"))
                return notify_fail("还是算了吧，"+who->name()+"是有夫之妇啦！\n");

        message_vision("$N对着$n拍着胸脯说：只要你嫁给我，你叫我做什么我就做什么！\n", me, who);

        me->set("proposing",1);
        me->set("propose_target", getuid(who));
        who->set("proposed",1);
        who->set("propose_man", getuid(me));

        return 1;
}

int do_marry(string arg)
{
   object me,who;
   me=this_player();

   if(me->query("age") < 15)
              return notify_fail("小孩子一边玩儿去。\n");

        if (me->query("gender")=="男性")
                return notify_fail("只有女人才能答应别人的求婚！\n");

        if (!arg) 
     return notify_fail("你要嫁给谁？\n");

        if (!me->query("proposed"))
                return notify_fail("嗯？没人向你求婚啊。\n");

        if (!objectp(who=present(arg,environment(me))))
                return notify_fail("这里没有这个人。\n");

        if (!who->is_character())
                return notify_fail("想清楚！"+who->name()+"是什么呀！\n");

        if (who==me)
                return notify_fail("开什么玩笑？！？\n");

        if (!living(who))
                return notify_fail("嗯...你还是先把"+who->name()+"弄醒吧。\n");

        if (me->query("propose_man")!=getuid(who))
                return notify_fail("嗯？"+who->name()+"没向你求过婚啊。\n");


        if (who->query("propose_target")!=getuid(me))
                return notify_fail("对不起，"+who->name()+"已经改变主意不向你求婚了。\n");
   
   if(!me->query("meiren"))
     return notify_fail("大姑娘家的，还是请个媒人来保亲吧！\n");

        message_vision("$N歪头想了会，羞羞答答地说道：好吧！\n",me,who);

        who->delete("proposing");
        who->delete("propose_target");

        me->delete("proposed");
        me->delete("propose_man");

        command("say 哈哈哈哈！好极了，一切齐备，我这就为你们主婚！");
        write("月下老人低头把姻缘簿翻了翻，写下些什么。\n");
        command("say 恭喜，恭喜！");
        command("say 哈哈哈哈！！！！");
        command("say "+me->name()+"和"+who->name()+"由"+me->query("meiren")+"做媒，今日喜结良缘，各位仙友做个见证。");
        command("say 恭祝两位白头偕老，早生贵子。");

        who->delete("meiren");
        who->set("married",1);
        who->set("husband/"+getuid(me), me->name());
        who->set("couple/id", getuid(me));
        who->set("couple/name", me->name());
        me->set("married", 1);
        me->set("wife/"+getuid(who), who->name());
        me->set("couple/id", getuid(who));
        me->set("couple/name", who->name());
        me->set_temp("marrying",1);
        me->set_temp("bride",getuid(who));

        return 1;
}


int do_zuomei(string arg)
{
   object me, who;
   me=this_player();

    if (!arg || !objectp(who=present(arg,environment(me)))) {
     tell_object(me,"你要给谁做媒？\n");
     return 1;
   }
        if (who->query("gender")=="男性")
                return notify_fail("这个人并不需要人做媒！\n");

   if (arg==me->query("proposed_target"))
     return notify_fail("啊？给自己做媒？听说过吗？！？\n");

   if (arg==me->query("id"))
     return notify_fail("啊？给自己做媒？听说过吗？！？\n");

   if (!who->query("proposed")) 
     return notify_fail("嗯？这人没打算结婚啊，你瞎起什么哄？！？\n");

   message_vision("$N笑嘻嘻的说：我想给女方做媒。\n", me);
   command("say " + me->query("name") + "原意给" + who->name() + "做媒？");
   command("say 这可是成人之美的善事啊，好极了，我这就记录下来。");
   who->set("meiren", me->query("name"));
   return 1;
}

int do_divorce(string arg)
{
   object me,who;
   me=this_player();

   if (!arg)
     return notify_fail("你打算跟谁离婚？\n");

    if (!me->query("married"))
     return notify_fail("你根本没结过婚！\n");

   if (me->query("gender")=="男性") {
     if (!me->query("wife/"+arg))
        return notify_fail("月下老人奇怪地看了你一眼，道：这人根本不是你妻子！\n");
     if (!(who=find_player(arg))) {
        message_vision("$N冲着月下老人大声嚷嚷着：这日子没法过了，我要离婚！\n", me);
        command("say 对不起，您夫人现在不在线上，不能办理离婚手续");
        return 1; }
     if (!me->query_temp("divorcing")) {
        message_vision("$N冲着月下老人大声嚷嚷着：这日子没法过了，我要离婚！\n", me);
        command("say 唉，你当真想休了你的妻子吗？如果是，请再向我申请一次。");
        me->set_temp("divorcing",1);
        return 1; }
     me->delete("married");
     me->delete("couple");
     me->delete("wife");
     me->delete_temp("divorcing");
     who->delete("married");
     who->delete("couple");
     who->delete("husband");
     tell_object(who, me->name()+"把你休了。");
   }
   else {
     if (!me->query("husband/"+arg))
        return notify_fail("月下老人奇怪地看了你一眼，道：这人根本不是你丈夫！\n");
     if (!(who=find_player(arg))) {
        message_vision("$N冲着月下老人大声嚷嚷着：这日子没法过了，我要离婚！\n", me);
        command("say 对不起，您丈夫现在不在线上，不能办理离婚手续");
        return 1; }
     if (!me->query_temp("divorcing")) {
        message_vision("$N冲着月下老人大声嚷嚷着：这日子没法过了，我要离婚！\n", me);
        command("say 唉，你当真想抛弃你的丈夫吗？如果是，请再向我申请一次。");
        me->set_temp("divorcing",1);
        return 1; 
        }

     who->delete("married");
     who->delete("wife");
     who->delete("couple");
     me->delete("married");
     me->delete("couple");
     me->delete_temp("divorcing");
     me->delete("husband");
     tell_object(who, me->name()+"抛弃了你，不知是跟谁私奔去了。");
   }
   command("say 唉 ... ...");
   command("say 唉 ... 从今天起，"+me->name()+"和"+who->name()+"就不再是夫妻了。");
   command("say 又一桩失败的婚姻，唉 ... ... ");

        log_file("yl.rc",me->name()+"和"+who->name()+
      "于"+NATURE_D->game_time()+"("+ctime(time())+")离婚。\n");

   return 1;
}
