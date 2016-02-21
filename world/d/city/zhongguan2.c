// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;
string *student_msg = ({
                "朝闻道，夕死可矣",
                "君子喻于义，小人喻于利",
                "见贤思齐焉，见不贤而内自省也",
                "君子讷于言而敏于行",
                "君子坦荡荡，小人长戚戚",
                "君子泰而不骄；小人骄而不泰",
});


void create ()
{
        set ("short", "总管府大堂");
        set ("long", @LONG

相府的大厅，摆设虽说不是很豪华，却也别有一番气势。正中有一张
楠木雕花椅，两边是几张红木的坐椅．总管平时在这里接见一些客人
(qiuxue)，两边回廊通向内宅。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "north" : __DIR__"zhongguan",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/kaishan" : 1,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 2,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_qiuxue", "qiuxue"); 
}
int do_qiuxue()
{       object ob, pai_ob;
        string object_file; 
        string obj_file;
        int i;
        object me;
        me=this_player();
        if(!(ob = present("yin kaishan", environment(me))))
                return notify_fail("总管今日不在，改日再来吧！\n");
        if( !(int)me->query_skill("literate") >= 45 )
return notify_fail("殷开山笑道：阁下的水平怕还不可以上国子监吧！\n");
        if(!me->query("guozi/paid"))
        return notify_fail("殷开山笑道：虽是国子监，柴米油盐钱还是要交的！\n");

write("殷开山从架上拿下一个小牌，笑道：望阁下珍惜机会，他日定会出人头地！\n
殷开山把牌子递给" + this_player()->name() + "．\n");
        me->set("guozi/paid", 0);
        pai_ob = new("/obj/pai");
                obj_file = sprintf("%O", ob);
        for(i=0; i <sizeof(obj_file); i++)  {
    }   
        obj_file = obj_file[0..i-1];

        pai_ob->set("player", this_player()->id());
pai_ob->set_temp("long_1", "国子监秀才" + this_player()->name() + "\n" + "背面还刻着：" +
student_msg[random(sizeof(student_msg))] + "\n");
        
        this_player()->start_busy(1);
        pai_ob->move(this_player());
        
        return 1;
}


