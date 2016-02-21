// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// check somebody's position

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
   BLU "初学乍练" NOR,   BLU "初窥门径" NOR,
   HIB "粗通皮毛" NOR,   HIB "略知一二" NOR,
   YEL "半生不熟" NOR,   YEL "马马虎虎" NOR,
   HIY "已有小成" NOR,   HIY "渐入佳境" NOR,
   HIM "驾轻就熟" NOR,   HIM "了然于胸" NOR,
   HIR "出类拔萃" NOR,   HIR "心领神会" NOR,
   MAG "神乎其技" NOR,   MAG "出神入化" NOR,
   CYN "豁然贯通" NOR,   CYN "登峰造极" NOR,
   HIC "举世无双" NOR,   HIC "一代宗师" NOR,
   HIC "震古铄今" NOR,   HIW "深不可测" NOR
});

string *exp_level_desc = ({
   BLU "新入道途" NOR,   HIB "初领妙道" NOR,
   HIB "略通道行" NOR,   HIB "渐入佳境" NOR,
   HIB "道心稳固" NOR,   CYN "一日千里" NOR,
   CYN "脱胎换骨" NOR,   CYN "霞举飞升" NOR,
   CYN "道满根归" NOR,   HIC "不堕轮回" NOR,
   HIC "已证大道" NOR,   HIW "天人合一" NOR
});

string *mana_level_desc = ({
         BLU "初具法力" NOR,   HIB "略晓变化" NOR,
   HIB "腾云驾雾" NOR,   HIB "预知祸福" NOR,
          HIB "妙领天机" NOR,   CYN "呼风唤雨" NOR,
          CYN "负海担山" NOR,    CYN "移星换斗" NOR,
   HIC "随心所欲" NOR,      HIC "变换莫测" NOR,
          HIW "法力无边" NOR
});

string skill_level(int,int);

int main(object me,string arg)
{
   object ob;
   int mana_cost;
   int sen_cost;
   int skill_lvl,mana_lvl,exp_lvl;
   string lvl;
   mapping skl;
   int *levels,i;
   string msg;

   if(!arg) 
     return notify_fail("你想打听谁的状态？\n");
   if((int)me->query("combat_exp")<5000)
     return notify_fail("你的道行不够，用不了地耳灵。\n");
   if((int)me->query("mana")<60) 
     return notify_fail("你的法力不够，用不了地耳灵。\n");
   if((int)me->query("sen")<=50)
     return notify_fail("你现在太累了，休息休息吧！\n");
   mana_cost=-(100-(int)me->query_skill("spells"))/4-40;
   mana_cost=mana_cost+10;
   if(mana_cost > -50) mana_cost=-50;
   me->add("mana", mana_cost);
   sen_cost=50;
   message_vision(HIY "$N口中念了几句咒文，眼中突然精光一闪，大喝一声“顺风耳何在！”\n只听嘿嘿几声奸笑，不知从哪里钻出来一个肥头大耳的家伙，在$N耳边低声说了几句话。\n" NOR, me);
   ob = find_player(arg);
   if( !ob ) ob = find_living(arg);
   if(!ob || ob->query("env/invisibility"))
     return notify_fail("顺风耳告诉你：奇怪，找不到这个人．．．\n");
   skl=ob->query_skills();
   if(!sizeof(skl)) {
     write("顺风耳告诉你： " + ob->name() + "目前并没有学会任何技能。\n");
   }
   else {
     levels=values(skl);
     skill_lvl=0;
     for(i=0;i<sizeof(skl);i++) {
        if(skill_lvl<levels[i]) skill_lvl=levels[i];
     }
     lvl=skill_level(1,skill_lvl);
     write("顺风耳告诉你： " + ob->name() + "目前武功已达" + lvl + "的境界。\n");
   }
   exp_lvl=ob->query("combat_exp");
   lvl=skill_level(2,exp_lvl);
   write("顺风耳告诉你： " + ob->name() + "目前道行已达" + lvl + "的境界。\n");
   mana_lvl=ob->query("max_mana");
   lvl=skill_level(3,mana_lvl);
   write("顺风耳告诉你： " + ob->name() + "目前法力已达" + lvl + "的境界。\n");

        message_vision("$N忽然莫名其妙地哆嗦了一下。\n",ob); 
   msg="你急忙掐指一算，";
        if(ob->query("combat_exp")>me->query("combat_exp")/5)
     msg+="原来是"+me->name()+"("+me->query("id")+")"+
          "正在打听你的道行。\n";
        else
     msg+="心中却只是一片茫然。\n";
        tell_object(ob, msg);

   return 1;
}

string skill_level(int type,int level)
{
   int grade,lvl,n;

   switch(type) {
   case 1:
     grade=level/10;
     if(grade>=sizeof(skill_level_desc)) grade=sizeof(skill_level_desc)-1;
     return skill_level_desc[grade];
   case 2:
   //in unit of 1000, increase by n^3, to get final one need 1331k.
     lvl=level/1000;
     for(grade=0;grade<sizeof(exp_level_desc);grade++) {
        n=(grade+1)*(grade+1)*(grade+1);
        if(lvl<n) break;
     }
     if(grade>=sizeof(exp_level_desc)) grade=sizeof(exp_level_desc)-1;
     return exp_level_desc[grade];
   case 3:
   //in unit of 20, increase by n^2, to get final one need 2000.
     lvl=level/20;
     for(grade=0;grade<sizeof(mana_level_desc);grade++) {
        n=(grade+1)*(grade+1);
        if(lvl<n) break;
     }
     if(grade>=sizeof(mana_level_desc)) grade=sizeof(mana_level_desc)-1;
     return mana_level_desc[grade];
   }
   return "";
}

int help(object me)
{
   write(@HELP
指令格式 : check|cha [<某人>]

地耳灵: 打听别人现在的道行,法力及武功级别。

武功级别：
   初学乍练   初窥门径   粗通皮毛
   略知一二   半生不熟   马马虎虎
   已有小成   渐入佳境   驾轻就熟
   了然于胸   出类拔萃   心领神会
   神乎其技   出神入化   豁然贯通
   登峰造极   举世无双   一代宗师
   震古铄今   深不可测

道行级别：
   新入道途   初领妙道   略通道行
   渐入佳境   道心稳固   一日千里
   脱胎换骨   霞举飞升   道满根归
   不堕轮回   已证大道   天人合一
   
法力级别：
   初具法力   略晓变化   腾云驾雾
   预知祸福   妙领天机   呼风唤雨
   负海担山    移星换斗   随心所欲
   变换莫测   法力无边
HELP
    );
    return 1;
}

