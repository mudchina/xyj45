inherit ROOM;
void create()
{
        set("short", "����ǽ");
        set("long", @LONG
�������ĳ�ǽ�ָ��ֺ񣬸���һ�ְ�ȫ�ĸо���ң�����⣬��ɫ����Ұһ������
һ����СС��ũ�����ǵ��ĵ�׺�ſ������Ұ������ʱ������������Ϧ��б�գ���
��ʤ�ա�Զ�������Ⱥɽ�������˸е�����׳�ۡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"nupgate",
  "east"  : __DIR__"necorner", 
]));
        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}