// 
// 

#include <ansi.h>
inherit ROOM;
string *directions= ({"西方","北方","东方","南方"});
void echoforest(object me);
void create()
{
        set("short", "古树顶");
        set("long", @LONG
放眼望去，树海茫茫，了无边际。浓密的树枝象一块厚实的地毯铺盖着
整个大地。这棵树上粗壮的树枝极力向四周伸展，其中有一根略为光滑，似
乎是被人攀把过的痕迹。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"center1",

]));
        set("outdoors", "manglin");
	set("current_dir",0);
        setup();
}

void init()
{
add_action("do_swing","swing");
add_action("do_turn","turn");
add_action("do_look","look");
}
int do_look(string arg)
{
	if( arg == "vine" 
		|| arg == "树枝" )
	{
	write("这是一根粗壮光滑的树枝，现在对着正"+directions[query("current_dir")]+"。\n");
	return 1;
	}
	return 0;
}
int do_swing(string arg)
{
	object me;
	int c_dir;
	me = this_player();
        if( arg == "vine"
                || arg == "树枝" )
        {
	echoforest(me);
	c_dir = query("current_dir");
	message_vision("\n\n$N抓紧树枝，用力向"+
	directions[c_dir] +
	"荡去！	
听着耳边的呼呼风声，$N不禁惊叫道：
啊啊啊．．．哦哦哦哦哦哦．．．啊啊！！！\n\n",me);
	if(c_dir == 0 )
		me->move(__DIR__"edge1");
	else
		me->move(__DIR__"top"+sprintf("%d",c_dir+1));
	return 1;
	}
	else return 0;

}
int do_turn(string arg)
{
	object me;
	int c_dir;
	me = this_player();
        if( arg == "vine"
                || arg == "树枝" )
        {
	c_dir = (int) query("current_dir");
	c_dir = (c_dir + 1 ) %4 ;
	set("current_dir",c_dir);
	message_vision("$N用力扳动树枝，使它对着正"+directions[c_dir]+"。\n",me);
        return 1;
        }
        return 0;

}
void echoforest(object me)
{
int i;
object room;
string *names = ({"center1","center2","center3", "center4",
		"dummy1","dummy2","dummy3","dummy4",
		"groupe1","groupe2","groupe3","groupe4",
                "groupw1","groupw2","groupw3","groupw4",
                "groupn1","groupn2","groupn3","groupn4",
                "groups1","groups2","groups3","groups4",
		"top2","top3","top4" });
for(i=0;i<sizeof(names);i++)
{
if( room = find_object(__DIR__+names[i]))
tell_object(room,HIW "\n\n远方传来一声长叫：＂啊啊啊．．．哦哦哦哦哦哦．．．啊啊啊！！＂\n\n" NOR);
}
}
void reset()
{

::reset();

	set("current_dir" , random(4));
}
