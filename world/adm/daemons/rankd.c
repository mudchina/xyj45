// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// rankd.c

#include <ansi.h>

string query_rank(object ob)
{
   if(strlen(ob->query("added_title"))<1) ob->set("added_title", "未设");
   //need this default, otherwise looks too ugly sometimes.

   if( ob->is_ghost() ) return HIB "【 鬼  魂 】" NOR;
   switch(ob->query("gender")) 
   {
   case "女性":
     switch(wizhood(ob)) {
        case "(admin)":   return GRN "【 巫  女 】" NOR;
        case "(arch)":     return GRN "【 巫  女 】" NOR;
        case "(wizard)":   return GRN "【 巫  女 】" NOR;
        case "(apprentice)":   return GRN "【客座巫女】" NOR;
                           case "(immortal)":      return GRN "【 小巫女 】" NOR;
                           case "(elder)":         return GRN "【荣誉玩家】" NOR;
        default:
          switch(ob->query("class")) 
          {
//------------------rank for girls--------------------
case "xian":
   if((int)ob->query("combat_exp")<1000) 
     return GRN "【 玉  女 】" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return GRN "【 小仙姑 】" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return GRN "【 仙  女 】" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return GRN "【"+ob->query("added_title")+"仙子】" NOR;   
   else 
     return GRN "【"+ob->query("added_title")+"圣母】" NOR;
   break;
case "yaomo":
   if((int)ob->query("combat_exp")<1000) 
     return GRN "【 小妖女 】" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return GRN "【 妖  女 】" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return GRN "【 妖  精 】" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return GRN "【"+ob->query("added_title")+"魔女】" NOR;   
   else 
     return GRN "【"+ob->query("added_title")+"公主】" NOR;
   break;
case "bonze":     
   if((int)ob->query("combat_exp")<1000) 
     return GRN "【 小尼姑 】" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return GRN "【 小师太 】" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return GRN "【 师  太 】" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return GRN "【"+ob->query("added_title")+"神尼】" NOR;   
   else 
     return GRN "【"+ob->query("added_title")+"菩萨】" NOR;
   break;
case "taoist":                
   if((int)ob->query("combat_exp")<1000) 
     return GRN "【 女道童 】" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return GRN "【 小道姑 】" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return GRN "【 玄  女 】" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return GRN "【"+ob->query("added_title")+"玄女】" NOR;   
   else 
     return GRN "【"+ob->query("added_title")+"圣母】" NOR;
   break;
case "dragon":     
   if((int)ob->query("combat_exp")<1000) 
     return GRN "【 小宫娥 】" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return GRN "【 宫  女 】" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return GRN "【 小龙女 】" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return GRN "【"+ob->query("added_title")+"龙女】" NOR;   
   else 
     return GRN "【"+ob->query("added_title")+"公主】" NOR;
   break;
case "scholar":
   if( (string)ob->query("added_title")=="未设" )
   {
     if((int)ob->query_skill("literate", 1)<20) 
        return GRN "【 女学童 】" NOR;
     else if((int)ob->query_skill("literate", 1)<100) 
        return GRN "【 才  女 】" NOR;
     else 
        return GRN "【 女学士 】" NOR;
   }
   else
   {
     if((int)ob->query_skill("literate", 1)<20) 
        return GRN "【 女学童 】" NOR;
     else if((int)ob->query_skill("literate", 1)<100) 
        return GRN "【"+ob->query("added_title")+"秀才】" NOR;
     else 
        return GRN "【"+ob->query("added_title")+"学士】" NOR;
   }
   break;
case "fighter":     
   if((int)ob->query("combat_exp")<1000) 
     return GRN "【 女  兵 】" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return GRN "【 女参将 】" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return GRN "【 女将军 】" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return GRN "【"+ob->query("added_title")+"大将军】" NOR;   
   else 
     return GRN "【"+ob->query("added_title")+"大元帅】" NOR;
   break;
case "youling":   
   if((int)ob->query("combat_exp")<1000) 
     return GRN "【阴曹小鬼】" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return GRN "【迷魂女鬼】" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return GRN "【幽冥女使】" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return GRN "【"+ob->query("added_title")+"无常】" NOR;   
   else 
     return GRN "【"+ob->query("added_title")+"女王】" NOR;
   break;   
case "dancer":
   return GRN "【 舞  妓 】" NOR;   
   break;
default:        
   return  MAG "【 平  民 】" NOR;
//------------------end rank for girls--------------------
          }
        }
//begin 男性：
   default:
     switch(wizhood(ob)) 
     {
        case "(admin)":     return HIW "【 巫  师 】" NOR;
        case "(arch)":        return HIW "【 巫  师 】" NOR;
        case "(wizard)":     return HIW "【 巫  师 】" NOR;
        case "(apprentice)":                return HIW "【客座巫师】" NOR;
                           case "(immortal)":               return HIW "【 小巫师 】" NOR;
        case "(elder)":                return HIW "【荣誉玩家】" NOR;
        default:
          switch(ob->query("class")) 
          {
//------------------rank for men--------------------
case "xian":                 
   if((int)ob->query("combat_exp")<1000) 
     return RED "【 仙  童 】" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return RED "【 散  仙 】" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return RED "【 大  仙 】" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return RED "【"+ob->query("added_title")+"大仙】" NOR;   
   else if((int)ob->query("combat_exp")<1000000) 
     return RED "【"+ob->query("added_title")+"大仙】" NOR;
   else 
     return RED "【"+ob->query("added_title")+"天尊】" NOR;
   break;
case "yaomo":
   if((int)ob->query("combat_exp")<1000) 
     return RED "【 小  妖 】" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return RED "【 妖  怪 】" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return RED "【 妖  仙 】" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return RED "【 "+ob->query("added_title")+"怪 】" NOR;   
   else if((int)ob->query("combat_exp")<1000000) 
     return RED "【"+ob->query("added_title")+"老魔】" NOR;
   else 
     return RED "【"+ob->query("added_title")+"魔王】" NOR;
   break;
case "bonze":     
   if((int)ob->query("combat_exp")<1000) 
     return RED "【 小和尚 】" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return RED "【 和  尚 】" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return RED "【 圣  僧 】" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return RED "【"+ob->query("added_title")+"尊者】" NOR;   
   else if((int)ob->query("combat_exp")<1000000) 
     return RED "【"+ob->query("added_title")+"罗汉】" NOR;
   else 
     return RED "【"+ob->query("added_title")+"菩萨】" NOR;
   break;
case "taoist":                 
   if((int)ob->query("combat_exp")<1000) 
     return RED "【 小道士 】" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return RED "【 道  士 】" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return RED "【 道  长 】" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return RED "【"+ob->query("added_title")+"天师】" NOR;   
   else if((int)ob->query("combat_exp")<1000000) 
     return RED "【"+ob->query("added_title")+"真人】" NOR;
   else 
     return RED "【"+ob->query("added_title")+"天尊】" NOR;
   break;
case "dragon":     
   if((int)ob->query("combat_exp")<1000) 
     return RED "【 虾  兵 】" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return RED "【 蟹  将 】" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return RED "【巡海夜叉】" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return RED "【"+ob->query("added_title")+"夜叉】" NOR;   
   else if((int)ob->query("combat_exp")<1000000) 
     return RED "【"+ob->query("added_title")+"龙】" NOR;
   else 
     return RED "【"+ob->query("added_title")+"龙王】" NOR;
   break;
case "scholar":
   if( (string)ob->query("added_title")=="未设" )
   {
     if((int)ob->query_skill("literate", 1)<20) 
        return RED "【 童  生 】" NOR;
     else if((int)ob->query_skill("literate", 1)<100) 
        return RED "【 秀  才 】" NOR;
     else 
        return RED "【 大学士 】" NOR;
   }
   else
   {
     if((int)ob->query_skill("literate", 1)<20) 
        return RED "【 童  生 】" NOR;
     else if((int)ob->query_skill("literate", 1)<100) 
        return RED "【"+ob->query("added_title")+"秀才】" NOR;
     else 
        return RED "【"+ob->query("added_title")+"学士】" NOR;
   }
   break;
case "fighter":     
   if((int)ob->query("combat_exp")<1000) 
     return RED "【 小  兵 】" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return RED "【 小  校 】" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return RED "【 参  将 】" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return RED "【"+ob->query("added_title")+"将军】" NOR;   
   else if((int)ob->query("combat_exp")<1000000) 
     return RED "【"+ob->query("added_title")+"大将军】" NOR;
   else 
     return RED "【"+ob->query("added_title")+"大元帅】" NOR;
   break;
case "youling":   
   if((int)ob->query("combat_exp")<1000) 
     return RED "【阴曹小鬼】" NOR;
   else if((int)ob->query("combat_exp")<10000) 
     return RED "【勾魂使者】" NOR;   
   else if((int)ob->query("combat_exp")<100000) 
     return RED "【地府判官】" NOR;
   else if((int)ob->query("combat_exp")<500000) 
     return RED "【"+ob->query("added_title")+"无常】" NOR;   
   else if((int)ob->query("combat_exp")<1000000) 
     return RED "【"+ob->query("added_title")+"鬼王】" NOR;
   else 
     return RED "【"+ob->query("added_title")+"王】" NOR;
   break;
default:
   return "【 平  民 】";
//------------------end rank for men--------------------
          }
        }
   }
}

string query_respect(object ob)
{
   int age;
   string str;

   if( stringp(str = ob->query("rank_info/respect")) )
     return str;

   // added by snowcat
   age = ob->query("fake_age");
   if (age == 0) age = ob->query("age");
   switch(ob->query("gender")) 
   {
     case "女性":
        switch(ob->query("class")) 
        {
case "bonze":
   if( age < 18 ) return "小师太";
   else return "师太";
   break;
case "taoist":
   if( age < 18 ) return "小仙姑";
   else return "仙姑";
   break;
case "xian":
   if( age < 18 ) return "小仙姑";
   else return "仙姑";
   break;
default:
   if( age < 18 ) return "小姑娘";
   else if( age < 50 ) return "姑娘";
   else return "婆婆";
   break;
        }
     case "男性":
     default:
        switch(ob->query("class")) 
        {
case "xian":
   if( age < 18 ) return "小神仙";
   else if( age < 50 ) return "仙兄";
   else return "老神仙";
   break;
case "bonze":
   if( age < 18 ) return "小师父";
   else if( age < 50 ) return "大师";
   else return "长老";
   break;
case "taoist":
   if( age < 18 ) return "小道爷";
   else if( age < 50 ) return "道兄";
   else return "道长";
   break;
case "fighter":
   if( age < 18 ) return "小将军";
   else if( age < 50 ) return "大将军";
   else return "老将军";
   break;
case "scholar":
   if( age < 18 ) return "小相公";
   else if( age < 50 ) return "相公";
   else return "老先生";
   break;
case "swordsman":
   if( age < 18 ) return "小老弟";
   else if( age < 50 ) return "壮士";
   else return "老前辈";
   break;
default:
   if( age < 18 ) return "小兄弟";
   else if( age < 50 ) return "壮士";
   else return "老爷子";
   break;
        }
   }
}

string query_rude(object ob)
{
   int age;
   string str;

   if( stringp(str = ob->query("rank_info/rude")) )
     return str;

   // added by snowcat
   age = ob->query("fake_age");
   if (age == 0) age = ob->query("age");
   switch(ob->query("gender")) 
   {
     case "女性":
        switch(ob->query("class")) 
        {
case "xian":
   if(age < 30) return "小妖精";
   else if(age < 50) return "妖女";
   else return "老妖婆";
   break;
case "yaomo":
   if(age < 30) return "小妖女";
   else if(age < 50) return "妖女";
   else return "老妖婆";
   break;
case "bonze":
   if(age < 30) return "小贼尼";
   else if(age < 50) return "贼尼";
   else return "老贼尼";
   break;
case "taoist":
   if(age < 30) return "小妖女";
   else if(age < 50) return "妖女";
   else return "老妖婆";
   break;
default:
   if( age < 30 ) return "小贱人";
   else if(age < 50) return "贱人";
   else return "死老太婆";
   break;
        }
     case "男性":
     default:
        switch(ob->query("class")) 
        {
case "xian":
   if( age < 50 ) return "死妖怪";
   else return "老妖怪";
   break;
case "yaomo":
   if( age < 50 ) return "死妖怪";
   else return "老妖怪";
   break;
case "bonze":
   if( age < 50 ) return "死秃驴";
   else return "老秃驴";
   break;
case "taoist":
   return "死牛鼻子";
   break;
case "scholar":
   if( age < 18 ) return "小书呆子";
   else if( age < 50 ) return "臭书呆子";
   else return "老童生";
   break;
default:
   if( age < 18 ) return "小王八蛋";
   else if( age < 50 ) return "臭贼";
   else return "老匹夫";
   break;
        }
   }
}

string query_self(object ob)
{
   int age;
   string str;

   if( stringp(str = ob->query("rank_info/self")) )
     return str;

   // added by snowcat
   age = ob->query("fake_age");
   if (age == 0) age = ob->query("age");
   switch(ob->query("gender")) 
   {
     case "女性":
        switch(ob->query("class")) 
        {
case "bonze":
   if( age < 50 ) return "贫尼";
   else return "老尼";
   break;
default:
   if( age < 30 ) return "小女子";
   else return "妾身";
   break;
        }
     case "男性":
     default:
        switch(ob->query("class")) 
        {
case "bonze":
   if( age < 50 ) return "贫僧";
   else return "老纳";
   break;
case "taoist":
   return "贫道";
   break;
case "scholar":
   if( age < 30 ) return "晚生";
   else return "不才";
   break;
default:
   if( age < 50 ) return "在下";
   else return "老头子";
   break;
        }
   }
}

string query_self_rude(object ob)
{
   int age;
   string str;

   if( stringp(str = ob->query("rank_info/self_rude")) )
     return str;

   // added by snowcat
   age = ob->query("fake_age");
   if (age == 0) age = ob->query("age");
   switch(ob->query("gender")) 
   {
     case "女性":
        switch(ob->query("class")) 
        {
case "bonze":
   if( age < 50 ) return "贫尼";
   else return "老尼";
   break;
default:
   if( age < 50 ) return "本姑娘";
   else return "老娘";
   break;
        }
     case "男性":
     default:
        switch(ob->query("class")) 
        {
case "bonze":
   if( age < 50 ) return "大和尚我";
   else return "老和尚我";
   break;
case "taoist":
   return "本山人";
   break;
case "scholar":
   if( age < 50 ) return "本相公";
   else return "老夫子我";
   break;
default:
   if( age < 18 ) return "你家小爷我";
   else if( age < 50 ) return "大爷我";
   else return "你爷爷我";
   break;
        }
   }
}


