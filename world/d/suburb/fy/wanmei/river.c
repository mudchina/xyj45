// 
// 

inherit ROOM;
void create()
{
        set("short", "С����");
        set("long", @LONG
������С���������룬������ǳ��ˮ���ļ���ˮ�沨��������չ��ӳ��
�������۰�Ĺ�â������С��ż��Ծ���ָ���ˮ�У�ȦȦˮ��������������
г��Ϫ�档
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"playground",
]));
	set("outdoors","wanmei");
        set("objects", ([
                __DIR__"npc/snake" :3,
                        ]) );
        setup();
}
void init()
{
	if(interactive(this_player()))
	call_out("do_flush",5,this_player());
	
}

void do_flush(object me)
{
	object room;

        if(!me || environment(me) != this_object())
                return;
	tell_object(me,"һ����ӿ�����㱻���������Σ���\n");
	room= load_object(__DIR__"lowriver");
	me->move(room);
}	