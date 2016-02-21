
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("皱皱的破纸片", ({"pozhi"}) );
	set_weight(5);
	set("long",
		"这是一张皱皱的破纸片儿。可往上写东西(print)\n");
	set("unit", "张");
        set("value", 100000);
}

void init()
{
  if(this_player()==environment())
  add_action("do_print","print");

}

int do_print(string arg)
{
        object obj, tarobj;
        string sheet, target;

	if( !arg || sscanf(arg, "%s", target)!=1 )
		return notify_fail("指令格式：print <姓名> \n");
	tarobj = present(target, environment(this_player()));
	if( !tarobj) tarobj = find_living(target);
	if( !tarobj ) {
	   message_vision("$N把" + target + "写在$n上。\n", this_player(), this_object());
	   this_object()->set("long",
		"这是一张" + this_object()->name() + "，上面写着＂" + target + "＂几个小字．\n");
        }
        else {
	   message_vision("$N把" + tarobj->name() + "写在$n上。\n", this_player(), this_object());
	   this_object()->set("targetname",tarobj->name());
	   this_object()->set("targetgender",tarobj->query("gender"));
	   this_object()->set("long",
		"这是一张" + this_object()->name() + "，上面写着＂" + tarobj->name() + "＂几个小字．\n");
        }
        this_object()->set("targetid", target);
        return 1;
}
