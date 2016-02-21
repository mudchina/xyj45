// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// updated.c

void create() { seteuid(getuid()); }

void check_user(object ob)
{
   int v1, v2;
   string m;
   mapping my;

   ob->delete_skill("antielem");

   ob->delete_skill("octigua-magic");
   if( (string)ob->query_skill_mapped("spells")=="octigua-magic" )
     ob->map_skill("spells");
   if( (string)ob->query_skill_mapped("magic")=="octigua-magic" )
     ob->map_skill("magic");

   if( (v1=ob->query_skill("evolution", 1)) > 0 ) {
     if( (v2=ob->query_skill("magic", 1)) > 0 ) {
        ob->set_skill("spells", v2);
        if( stringp(m=ob->query_skill_mapped("magic")) ) {
          ob->map_skill("magic");
          ob->map_skill("spells", m);
        }
     }
     ob->set_skill("magic", v1);
     ob->delete_skill("evolution");
     ob->map_skill("evolution");
   }

   if( (v1=ob->query_skill("essence", 1)) > 0 ) {
     ob->set_skill("force", v1);
     ob->delete_skill("essence");
     if( stringp(m=ob->query_skill_mapped("essence")) ) {
        ob->map_skill("essence");
        ob->map_skill("force", m);
     }
   }

   my = ob->query_entire_dbase();
   if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
   if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
   if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"];
   if( my["eff_gin"] > my["max_gin"] ) my["eff_gin"] = my["max_gin"];
   if( my["eff_kee"] > my["max_kee"] ) my["eff_kee"] = my["max_kee"];
   if( my["eff_sen"] > my["max_sen"] ) my["eff_sen"] = my["max_sen"];
   if( my["gin"] > my["eff_gin"] ) my["gin"] = my["eff_gin"];
   if( my["kee"] > my["eff_kee"] ) my["kee"] = my["eff_kee"];
   if( my["sen"] > my["eff_sen"] ) my["sen"] = my["eff_sen"];

// added by dream to clear ppl's invisibility and immortal when updated
// for future spells. July 11, 1997.

   if ( !wizardp(ob) && ob->query("env/invisibility") )
     ob->set("env/invisibility", 0);
   if ( !wizardp(ob) && ob->query("env/immortal") )
     ob->set("env/immortal", 0);

   // by snowcat - adjust title
   if (ob->query("zhangmen"))
   {
     object zhangmen = new (ob->query("zhangmen/base_name"));

          if (zhangmen)
     {
       zhangmen->set_save_file(ob->query("zhangmen/data_name"));
       zhangmen->restore();

       if (zhangmen->query("family/family_name")!=ob->query("family/family_name"))
       {
         // already betrayed
         if (ob->query("title")==ob->query("zhangmen/title") ||
             ob->query("title")==ob->query("zhangmen/title_old"))
         {
           if (ob->query("family/family_name"))
             ob->set("title",
                       sprintf("%s第%s代%s",
                               ob->query("family/family_name"),
                               chinese_number(ob->query("family/generation")),
                               ob->query("family/title")));
         }
         if (zhangmen->query("current_player")==ob->query("id"))
         {
           zhangmen->reset_me(zhangmen);
           zhangmen->save();
         }
         ob->delete("zhangmen");
       }
       else if (zhangmen->query("current_player")==ob->query("id"))
            {
         ob->set("title",ob->query("zhangmen/title"));
            }
       else
       {
         /*
         ob->set("title",
                   sprintf("%s第%s代%s",
                           ob->query("family/family_name"),
                           chinese_number(ob->query("family/generation")),
                           ob->query("family/title")));
          */
         ob->set("title",ob->query("zhangmen/title_old"));
         ob->delete("zhangmen");
       }
            ob->save();
     }
   }

   // by snowcat
   // the following is used to update ob's data in case
   // of system change
   {
          int tmpint;
          string tmpstr;

     if (tmpint = ob->query("obstacle/level"))
     {
       if (! ob->query("obstacle/number"))
         ob->set("obstacle/number",tmpint);
     }
     if (tmpstr = ob->query("obstacle/1"))
     {
       if (ob->query("obstacle/nuerguo"))
       {
         // already there
       }
       else if (tmpstr == "marriage" ||
                tmpstr == "company" ||
                tmpstr == "stomachache")
         ob->set("obstacle/nuerguo",tmpstr);
       else
         ob->set("obstacle/nuerguo","done");
     }
     if (tmpstr = ob->query("obstacle/2"))
     {
       if (ob->query("obstacle/firemount"))
       {
         // already there
       }
       else if (tmpstr != "done")
         ob->set("obstacle/firemount",tmpstr);
       else 
         ob->set("obstacle/firemount","done");
     }
     if (tmpint = ob->query("obstacle/2_bone"))
            ob->set("obstacle/firemount_bone",tmpint);
     if (tmpstr = ob->query("obstacle/3"))
     {
       if (ob->query("obstacle/wudidong"))
       {
         // already there
       }
       else
         ob->set("obstacle/wudidong",tmpstr);
     }
     ob->delete("obstacle/level");
     ob->delete("obstacle/1");
     ob->delete("obstacle/2");
     ob->delete("obstacle/2_bone");
     ob->delete("obstacle/3");
   }

   // by snowcat
   if (ob->query("obstacle/reward"))
         ob->set("obstacle/wuzhuang","done");

   // by snowcat
   // the following is a filter for 东海龙宫
   {
          string tmpstr;

          tmpstr = ob->query("family/family_name");
     if (tmpstr == "龙宫")
       ob->set("family/family_name","东海龙宫");

          tmpstr = ob->query("title");
     if (tmpstr == "龙宫第二代弟子")
       ob->set("title","东海龙宫第二代弟子");
     if (tmpstr == "龙宫第三代弟子")
       ob->set("title","东海龙宫第三代弟子");
   }

   // by snowcat
   // the following is a filter for relai reward
   {
     if (ob->query("obstacle/reward") &&
         ob->query("obstacle/mud_age") == 0)
       ob->set("obstacle/mud_age", ob->query("mud_age"));
        }
}
