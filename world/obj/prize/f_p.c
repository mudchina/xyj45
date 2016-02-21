// black_vest.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("大还丹", ({ "dan" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","风云第一的奖品 用法：boost\n");
		set("unit", "颗");
		set("value", 5000000);
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
	string theskill;
	int thelevel = 0;
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
		if(skl[sname[i]] > thelevel) {theskill = sname[i]; thelevel = skl[sname[i]];}	
	}
	ob->set_skill(theskill, (int)thelevel+1);
message_vision("$N的"+to_chinese(theskill)+"增强了。\n", this_player());
destruct(this_object());
return 1;
}
