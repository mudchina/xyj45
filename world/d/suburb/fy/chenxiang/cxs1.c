// 
// 

inherit ROOM;
void create()
{
        set("short", "�������Ͻ�");
        set("long", @LONG
������Ĵ󲿷־����Ը���ˮ��Ϊ���������������ס�ĵط���ÿ��
������ũ�������ų��صĲ��������������ĺ�ˮ�����л������ص�����һ��
��ð��ŨŨ�Ĵ��̣�ɢ�������˵ĵ��������ļҡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxcenter",
  "south" : __DIR__"farmershop",
]));
        set("objects", ([
	__DIR__"npc/farmer": 2,
                        ]) );
        set("outdoors", "chenxiang");
        setup();
        replace_program(ROOM);
}