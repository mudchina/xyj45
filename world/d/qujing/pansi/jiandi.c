// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ɽ�����ݵش����Ĵ��ǽ�ˮ�����������޷���š������Ǹ�ɽ
���룬���߽���ˮ�����������������һ�������ϡ�

LONG);

  set("exits", ([
        "westup"    : __DIR__"jiankou1",
        "down"    : __DIR__"jiandi2",
      ]));
  set("objects", ([
        __DIR__"npc/shuizhi" : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}
