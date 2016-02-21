// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

string say_position();
void create()
{
       set_name("万圣公主", ({"wansheng gongzhu","gongzhu","princess"}));

        set("long","万圣公主是万圣龙王的女儿，最近招了九头怪为驸马。\n");
       set("gender", "女性");
       set("age", 20);
        set("int", 25+random(5));
       set("attitude", "peaceful");
        set("combat_exp", 280000);
   set("eff_dx", -100000);
   set("nkgain", 400);
       set("rank_info/respect", "公主殿下");
       set("class","dragon");
       set("per", 30);
       set("max_kee", 800);
       set("max_sen", 500);
       set("force", 800);
       set("max_force", 600);
       set("force_factor", 20);
       set("max_mana", 500);
       set("mana", 400);
       set("mana_factor", 10);
       set_skill("literate", 70);
   set_skill("stealing", 70);
       set_skill("unarmed", 70);
       set_skill("dodge", 160);
       set_skill("force", 70);
       set_skill("parry", 70);
       set_skill("spells", 70);
        set_skill("dragonfight", 70);
        set_skill("dragonforce", 70);
        set_skill("dragonstep", 70);
        map_skill("unarmed", "dragonfight");
        map_skill("force", "dragonforce");
        map_skill("dodge", "dragonstep");
   set("inquiry",([
       "宝贝": "什么宝贝不宝贝的！\n",
       "佛宝": "佛宝现是我龙宫的镇潭之宝了，谁也拿不到。\n",
                  "方位": (: say_position :),
                  ]));

        setup();
   carry_object("/d/qujing/bibotan/obj/clasp")->wear();
        carry_object("/d/obj/cloth/pinkskirt")->wear();
}


int recognize_apprentice(object who)
{   who= this_player();
   if( who->query("family/family_name")=="乱石山碧波潭" 
     && who->query("can_learn_stealing") ) { 
           return 1;
   }
   return 0;
}

string say_position()
{   object me =this_object();
   object who=this_player();

   if( me->is_fighting() || who->is_fighting() )
   return ("什么方位不方位的，我不懂。\n");

   if(member_array("tianboer xiao", who->parse_command_id_list())==-1) {
     call_out("kill_him", 1, who);
     return ("今日不除你，终成我龙宫大患！\n");
   }

   if( me->query("talked") )
   return ("什么方位不方位的，我不是已经告诉你！\n");
   me->set("talked", 1);
   call_out("tell_position", 1, who);
   return "";
}
void tell_position(object who)
{
   if( !who || environment(who) != environment()) return;
   switch (random(8)) {
     case 0:
        command("whisper xiao 今日方位在乾位。");
        who->set_temp("heard_position", "乾");
     break;
                case 1:
                        command("whisper xiao 今日方位在坤位。");
                        who->set_temp("heard_position", "坤");
                break;
                case 2:
                        command("whisper xiao 今日方位在兑位。");
                        who->set_temp("heard_position", "兑");
                break;
                case 3:
                        command("whisper xiao 今日方位在离位。");
                        who->set_temp("heard_position", "离");
                break;
                case 4:
                        command("whisper xiao 今日方位在震位。");
                        who->set_temp("heard_position", "震");
                break;
                case 5:
                        command("whisper xiao 今日方位在艮位。");
                        who->set_temp("heard_position", "艮");
                break;
                case 6:
                        command("whisper xiao 今日方位在巽位。");
                        who->set_temp("heard_position", "巽");
                break;
                case 7:
                        command("whisper xiao 今日方位在坎位。");
                        who->set_temp("heard_position", "坎");
                break;
   }
}
void kill_him(object who)
{
   object husband = present("jiutou fuma", environment(this_object()));
   
   if(husband)
   husband->kill_ob(who);
   ::kill_ob(who);
}
