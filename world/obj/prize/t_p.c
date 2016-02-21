// black_vest.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("还丹", ({ "dan" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","风云第三的奖品 用法：boost\n");
		set("unit", "颗");
		set("value", 3000000);
		set("no_drop",1);
	}
	setup();
}

int query_autoload() { return 1; }
void init()
{
  if(this_player()==environment())
  add_action("boost_skill","boost");
}

int boost_skill()
{
        object ob, *list, couple_ob;
	string f_ski, s_ski, t_ski;
	int f_lvl= 0, s_lvl = 0, t_lvl=0;
        mapping skl, lrn, map;
        string *sname, *mapped,target,cardname;
        int i, marry_flag;
	ob = this_player();
        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( "你目前并没有学会任何技能。\n");
                return 1;
        }
        sname  = sort_array( keys(skl), (: strcmp :) );

        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);

       for(i=0; i<sizeof(skl); i++) {
		if(skl[sname[i]] >= f_lvl) 
		{
			t_lvl = s_lvl;
			t_ski = s_ski;
			s_lvl = f_lvl;
			s_ski = f_ski;
			f_lvl = skl[sname[i]];
			f_ski = sname[i];
		}
	else if( skl[sname[i]] >= s_lvl)
		{
                        t_lvl = s_lvl;
                        t_ski = s_ski;
			s_lvl = skl[sname[i]];
                        s_ski = sname[i];
		}
	else if( skl[sname[i]] >= t_lvl)
		{
                        t_lvl = skl[sname[i]];
                        t_ski = sname[i];
		}
					}
	if(!t_ski) t_ski = s_ski;
        if(!t_ski) t_ski = f_ski;
	ob->set_skill(t_ski, (int)t_lvl+1);
message_vision("$N的"+to_chinese(t_ski)+"增强了。\n", this_player());
destruct(this_object());
return 1;
}
