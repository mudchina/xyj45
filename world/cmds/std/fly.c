// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//cglaem...12/17/96.

#include <ansi.h>

int main(object me, string arg)
{
   string loc = 0;
   int mana_cost;
   object ridee, map;
   string ridemsg;

        seteuid(getuid());

        if( me->is_fighting() )
                return notify_fail("你正在战斗，飞不开。\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
                return notify_fail("你正忙着呢，没工夫腾云驾雾。\n");
   if( !wizardp(me) && !environment(me)->query("outdoors") )
     return notify_fail("周围没有一片云，没办法腾云驾雾。\n");
   if( me->is_ghost() )
     return notify_fail("做了鬼了，就老实点吧！\n");
        if( !arg )
                return notify_fail("你要飞到哪里去？\n");
   if( me->query_temp("no_move") )
     return notify_fail("你被定住了，哪里飞得起来！\n");

        if( (int)me->query("combat_exp") < 10000 ){
                message_vision(HIY
"$N奋力望上一跳，似乎想飞起来。结果离地不到三尺就一个倒栽葱摔了下来。\n"
NOR, me);
                return notify_fail("可能是你道行还不够。\n");
        }

        if( (int)me->query("mana") < 200 ){
                message_vision(HIY
"$N奋力望上一跳，似乎想飞起来。结果离地不到三尺就一个倒栽葱摔了下来。\n"
NOR, me);
                return notify_fail("可能是你法力还不够。\n");
        }

        if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 50 )
                return
notify_fail("你现在头脑不太清醒，当心掉下来摔死。\n");

        if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 50 )
                return
notify_fail("你想飞起来，可是体力似乎有点不支。\n");

        mana_cost=-(100-(int)me->query_skill("spells"))/4-40;
        if(mana_cost > 0) mana_cost=0;

   if( (string)me->query("family/family_name") == "阎罗地府") {
     message_vision(HIY"$N手一指，平地间一股阴风刮起，将$N裹了起来，\n"+
"再吹一声口哨，随之飘去不见了。。。\n\n"NOR, me);
   }else if( (string)me->query("family/family_name") == "大雪山"
     || (string)me->query("family/family_name") == "陷空山无底洞" ) {
     message_vision(HIY"$N手一指，「呼」地一阵狂风刮起，吹的人都睁不开眼睛，\n"+
"再吹一声口哨，随之飘去不见了。。。\n\n"NOR, me);
   }else {   
        message_vision(HIY
"$N手一指，召来一朵云彩，高高兴兴地坐了上去，\n"+
"再吹一声口哨，随之往上冉冉地升起。。。\n\n"NOR, me);
   }

        me->add("mana", mana_cost);

        if(arg=="stone") loc="/d/4world/entrance";
        else if(arg=="kaifeng") loc="/d/kaifeng/tieta";
        else if(arg=="moon") loc="/d/moon/ontop2";
        else if(arg=="lingtai") loc="/d/lingtai/gate";
        else if(arg=="putuo") loc="/d/nanhai/gate";
        else if(arg=="changan") loc="/d/city/center";
        else if(arg=="sky") loc="/d/sky/nantian";
   else if(arg=="wuzhuang") loc="/d/qujing/wuzhuang/gate";
   else if(arg=="meishan") loc="/d/meishan/erlangwai";

   else if(arg=="penglai") {
     if(!(map=present("eastsea map", me)) && !wizardp(me)) {
        write("你在天上转了半天也不知该往那边飞。。。\n");
        message_vision("\n$N失望地从云上跳了下来！\n", me);
        return 1;
        }
     if( !wizardp(me)&&(string)map->query("unit")!="张" ){
        write("你在天上转了半天也不知该往那边飞。。。\n");
                        message_vision("\n$N失望地从云上跳了下来！\n", me);
                        return 1;
                        }
//     write("你驾着祥云向东边海中飞去。。。\n\n");
     loc="/d/penglai/penglai";
   }
   else if(arg=="xueshan") {
     if(!(map=present("xueshan map", me)) && !wizardp(me)) {
        write("你在天上转了半天也不知该往那边飞。。。\n");
        message_vision("\n$N失望地从云上跳了下来！\n", me);
        return 1;
        }
     if( !wizardp(me)&&(string)map->query("unit")!="张" ){
                        write("你在天上转了半天也不知该往那边飞。。。\n");
                        message_vision("\n$N失望地从云上跳了下来！\n", me);
                        return 1;
                        }
//     write("你驾着祥云向大雪山飞去。。。\n\n");
     loc="/d/xueshan/binggu";
   }
   else if(arg=="baoxiang"){
     loc = "/d/qujing/baoxiang/bei1.c";
     loc[strlen(loc)-3] = '1'+random(4);
   }else if(arg=="pingding"){
     loc = "/d/qujing/pingding/ping1.c";
     loc[strlen(loc)-3] = '1'+random(4);
   }else if(arg=="yalong"){
     loc = "/d/qujing/pingding/yalong1.c";
     loc[strlen(loc)-3] = '1'+random(3);
   }else if(arg=="wuji"){
     loc = "/d/qujing/wuji/square.c";
     //loc[strlen(loc)-3] = '1'+random(9);
   }else if(arg=="chechi"){
     loc = "/d/qujing/chechi/jieshi1.c";
     loc[strlen(loc)-3] = '1'+random(9);
   }else if(arg=="tongtian"){
     loc = "/d/qujing/tongtian/hedong1.c";
     loc[strlen(loc)-3] = '1'+random(6);
   }else if(arg=="jindou"){
     loc = "/d/qujing/jindou/jindou1.c";
     loc[strlen(loc)-3] = '1'+random(4);
   }else if(arg=="nuerguo"){
     loc = "/d/qujing/nuerguo/towna1.c";
     /*
     if (me->query("obstacle/nuerguo")!="done" && !wizardp(me)){
        write("\n一阵风把你东倒西歪地吹了回来！\n");
        write("看样子飞不过去。\n");
        return 1;
        }
     */
     loc[strlen(loc)-4] = 'a'+random(3);
     loc[strlen(loc)-3] = '1'+random(3);
   }else if(arg=="dudi"){
     loc = "/d/qujing/dudi/dudi1.c";
     loc[strlen(loc)-3] = '1'+random(4);
        }else if(arg=="firemount"){
            loc = "/d/qujing/firemount/cuiyun1.c";
     loc[strlen(loc)-3] = '1'+random(5);
   }else if(arg=="jilei"){
     loc = "/d/qujing/jilei/jilei1.c";
     loc[strlen(loc)-3] = '1'+random(3);
   }else if(arg=="jisaiguo"){
     loc = "/d/qujing/jisaiguo/east1.c";
     loc[strlen(loc)-3] = '1'+random(4);
   }else if(arg=="jingjiling"){
     loc = "/d/qujing/jingjiling/jingji1.c";
   }else if(arg=="xiaoxitian"){
     loc = "/d/qujing/xiaoxitian/simen.c";
        }else if(arg=="zhuzi"){
            loc = "/d/qujing/zhuzi/zhuzi1.c";
     loc[strlen(loc)-3] = '1'+random(5);
        }else if(arg=="qilin"){
            loc = "/d/qujing/qilin/yutai.c";
        }else if(arg=="pansi"){
            loc = "/d/qujing/pansi/ling1.c";
     loc[strlen(loc)-3] = '1'+random(6);
        }else if(arg=="biqiu"){
            loc = "/d/qujing/biqiu/jie1.c";
     loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="qinghua"){
     loc = "/d/qujing/biqiu/zhuang.c";
        }else if(arg=="wudidong"){
     loc = "/d/qujing/wudidong/firemount-wudidong3.c";
     loc[strlen(loc)-3] = '1'+random(3);
        }else if(arg=="qinfa"){
            loc = "/d/qujing/qinfa/jiedao1.c";
     loc[strlen(loc)-3] = '1'+random(8);
        }else if(arg=="yinwu"){
            loc = "/d/qujing/yinwu/huangye1.c";
        }else if(arg=="fengxian"){
            loc = "/d/qujing/fengxian/jiedao1.c";
     loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="yuhua"){
            loc = "/d/qujing/yuhua/xiaojie1.c";
     loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="baotou"){
            loc = "/d/qujing/baotou/shanlu1.c";
     loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="zhujie"){
            loc = "/d/qujing/zhujie/shanlu11.c";
     loc[strlen(loc)-3] = '1'+random(8);
        }else if(arg=="jinping"){
            loc = "/d/qujing/jinping/xiaojie1.c";
     loc[strlen(loc)-3] = '1'+random(7);
        }else if(arg=="qinglong"){
            loc = "/d/qujing/qinglong/shanjian.c";
        }else if(arg=="tianzhu"){
            loc = "/d/qujing/tianzhu/jiedao11.c";
     loc[strlen(loc)-3] = '1'+random(8);
        }else if(arg=="maoying"){
            loc = "/d/qujing/maoying/shanpo1.c";
     loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="lingshan"){
            loc = "/d/qujing/lingshan/dalu1.c";
     loc[strlen(loc)-3] = '1'+random(3);
        }else if(arg=="es"){
            loc = "/d/suburb/es/snow/square.c";
            if (file_size(loc)==-1)
                loc = 0;
        }else if(arg=="xkx"){
            loc = "/d/suburb/xkx/city/guangchang.c";
            if (file_size(loc)==-1)
                loc = 0;
        }else if(arg=="fy"){
            loc = "/d/suburb/fy/fy/fysquare.c";
            if (file_size(loc)==-1)
                loc = 0;
        }else{
                write("\n\n到了！你按下云头跳了下来。\n");
                write("咦？．．．怎么还在原来的地方？\n");
                return 1;
        }

   if (! loc) {
     write("\n\n到了！你按下云头跳了下来。\n");
     write("咦？．．．怎么还在原来的地方？\n");
     return 1;
   }
     
   if (ridee = me->ride()) {
     ridemsg = ridee->query("ride/msg")+"着"+ridee->name();
     ridee->move(loc);
   }  
   else  
     ridemsg = "";
                                                 
   me->move(loc);
        write("\n\n到了！你按下云头跳了下来。\n");

   if( (string)me->query("family/family_name")=="阎罗地府") {
     message_vision(HIY"\n只见平地吹起一阵阴风，$N"+ridemsg+"从里面走了出来。\n"
NOR, me);
   }else if( (string)me->query("family/family_name") == "大雪山"
     || (string)me->query("family/family_name") == "陷空山无底洞") {
     message_vision(HIY"\n只见狂风大作，$N"+ridemsg+"从里面走了出来。\n"NOR, me);
   }else{
        message_vision(HIY
"\n只见半空中降下一朵云彩，$N"+ridemsg+"从里面走了出来。\n" NOR, me);
   }

        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : fly|fei [目的地]

当你的道行和法力高强时，你可以腾云驾雾。

目前你可以飞到的地方：
changan     ->长安城            kaifeng     ->开封城
stone       ->花果山仙石        sky         ->南天门
moon        ->昆仑山月宫        penglai     ->蓬莱仙岛
lingtai     ->灵台方寸山        putuo       ->南海普陀山
xueshan     ->大雪山寒冰谷      meishan     ->梅山灌江口
wuzhuang    ->万寿山五庄观

baoxiang    ->宝象国            pingding    ->平顶山
yalong      ->压龙山            wuji        ->乌鸡国
chechi      ->车迟国            tongtian    ->通天河
jindou      ->金兜山            nuerguo     ->女儿国
dudi        ->毒敌山            firemount   ->火焰山
jilei       ->积雷山            jisaiguo    ->祭赛国
jingjiling  ->荆棘岭            xiaoxitian  ->小西天
zhuzi       ->朱紫国            qilin       ->麒麟山
pansi       ->盘丝岭            biqiu       ->比丘国 
qinghua     ->清华庄            wudidong    ->无底洞
qinfa       ->钦法国            fengxian    ->凤仙郡 
yinwu       ->隐雾山            yuhua       ->玉华县 
baotou      ->豹头山            zhujie      ->竹节山
jinping     ->金平府            qinglong    ->青龙山 
tianzhu     ->天竺国            maoying     ->毛颖山 
lingshan    ->灵山                   

如果是《西游记》扩充版，你可以飞到：
es          ->东方故事          xkx         ->侠客行
fy          ->风云

HELP
        );
        return 1;
}

