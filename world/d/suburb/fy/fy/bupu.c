inherit ROOM;
void create()
{
        set("short", "风云布铺");
        set("long", @LONG
布铺里摆满了绫罗绸缎，这里专门订作，裁剪，改装各种鞋，帽，
衫．这里做的衣服不但款式新颖，而且经久耐用．风云老少们穿的大
部份都是这里出的．门口有一个大木牌（ｓｉｇｎ）．
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ecloud2",
]));
        set("objects", ([
        "/d/suburb/fy/fengyun/npc/caifeng" : 1,
			]) );
        set("item_desc", ([
                "sign": @TEXT
这里是布铺，目前我们可订作（ｄｉｎｇ）：

帽子（ｈａｔ），围巾（ｓｃａｒｆ），外衣（ｓｕｉｔ），
腰带（ｂｅｌｔ），布鞋（ｓｈｏｅｓ）．

每件一两黄金．

例子：
ｄｉｎｇ　ｓｕｉｔ　￥ＨＩＹ￥  团金黄龙袍  ｒｏｂｅ

布铺就会帮你作一件黄色的 ｒｏｂｅ　叫＂团金黄龙袍＂ 

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
