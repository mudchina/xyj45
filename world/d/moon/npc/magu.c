// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//mugu.c

inherit NPC;
string ask_for_leave();

void create()
{
        set_name("麻姑", ({"magu"}));
        set("gender", "女性" );
        set("age", 35);
        set("title","月宫管家");
        set("long", "麻姑在月宫可是里里外外一把手。\n");
        set("combat_exp", 100);
        set("attitude", "peaceful");
        set("per", 15);
        set("max_kee", 200);
        set("max_gin", 100);
        set("max_sen", 100);
        set("inquiry", ([
     "脱离" : (: ask_for_leave :),
     "leave" : (: ask_for_leave :),
     ]) );
   setup();
        carry_object("/d/ourhome/obj/pink_cloth")->wear();
        carry_object("/d/ourhome/obj/shoes")->wear();
}

void init()
{
        add_action("do_agree", "agree");
}

string ask_for_leave()
{
   object me=this_player();

   if (me->query("family/family_name") == "月宫" ) {
     command("say 你既是执意下山，老身却有几句话说。");
     me->set_temp("betray", 1);
     return ("脱离师门要需要有一定惩罚，你可愿意(agree)？");
   }

   return ("老身不知。\n");
}

int do_agree(string arg)
{
   if(this_player()->query_temp("betray")) {
     message_vision("$N答道：弟子愿意。\n\n", this_player());
     command("say 既是你与月宫无缘，你便下山去吧！");
     this_player()->add("betray/count", 1);
     this_player()->add("betray/moon", 1);
     this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
     this_player()->delete("family");
     this_player()->delete("class");
     this_player()->set("title", "普通百姓");
     this_player()->set_temp("betray", 0);
     this_player()->save();
     command("say 江湖风波，善恶无形，好自为之。。。\n");
     return 1;
   }
}

