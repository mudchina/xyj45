// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

��᫵�ɽ����ɽ�������ѣ��Ĵ��ǻ�ɽҰ�룬��������һƬ��
Զ���ֺ������Բԡ�·���в����Ĺ������ٸ��������󣬴�
������ķ�ɳ��

LONG);

  set("exits", ([
        "southwest"   : __DIR__"shan13",
        "northeast"   : "/d/qujing/baoxiang/yelu1",
      ]));
  set("outdoors", __DIR__);

  setup();
}


