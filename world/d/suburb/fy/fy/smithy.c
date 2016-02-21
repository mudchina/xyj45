
inherit ROOM;

void create()
{
        set("short", "张家铁铺");
        set("long", @LONG
风云老少都喜欢在这里打造称手的铁器，从火炉中冒出的火光将墙
壁映得通红，屋子的角落里堆满了各式铁器的完成品或未完成品，像是锄
头、铁锤、铲子、长剑等，叮叮当当的声音敲得满屋子响。
门口有一个大木牌（ｓｉｇｎ）．
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"ecloud3",
]));

        set("objects", ([
                "/d/suburb/fy/fengyun/npc/smith": 1 ]) );
        set("item_desc", ([
                "sign": @TEXT

目前我们可订作（ｄｉｎｇ）：

铁斧（ａｘｅ），单刀（ｂｌａｄｅ），匕首（ｄａｇｇｅｒ），
钢叉（ｆｏｒｋ），铁锤（ｈａｍｍｅｒ），
禅杖（ｓｔａｆｆ），铁剑（ｓｗｏｒｄ），铁鞭（ｗｈｉｐ）

每件一两黄金．

例子：
ｄｉｎｇ　ｓｗｏｒｄ　￥ＨＩＧ￥ 碧血剑  ｂｌｏｏｄｙｓｗｏｒｄ

张铁匠就会帮你作一件发绿色的＂碧血剑＂ 叫 ｂｌｏｏｄｙｓｗｏｒｄ

$BLK$ - 黑色            $NOR$ - 恢复正常颜色
$RED$ - 红色            $HIR$ - 亮红色
$GRN$ - 绿色            $HIG$ - 亮绿色
$YEL$ - 土黄色          $HIY$ - 黄色
$BLU$ - 深蓝色          $HIB$ - 蓝色
$MAG$ - 浅紫色          $HIM$ - 粉红色
$CYN$ - 蓝绿色          $HIC$ - 天青色
$WHT$ - 浅灰色          $HIW$ - 白色

TEXT
        ]) );

        setup();
        replace_program(ROOM);
}
