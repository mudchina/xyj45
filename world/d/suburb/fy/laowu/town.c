
inherit ROOM;

void create()
{
        set("short", "����֮��");
        set("long", @LONG
�ڷ⽭��ǰ���죬���ݵľ��������׼���õ�ľ�������ɻ����У�����������ϵס��
�⽭�󣬸��ڽ����ϵ�ľ�ܶ������˸������������ڣ���ש���ߣ�����һ�������СС��
��ʽ�����ķ��ӣ����ڽ��ϸ���������
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"daroad",
  "south" : __DIR__"laowu",
  "east" : __DIR__"town1",
  "west" : __DIR__"town2",
]));
        set("outdoors", "laowu");

        setup();
        replace_program(ROOM);

}
