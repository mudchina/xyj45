// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// to.c

// inherit F_CLEAN_UP;
// Don't want this command be cleaned up while typing long string.

int main(object me, string arg)
{
   me->edit( (: call_other, this_object(), ({ "do_to", me, arg }) :) );
   return 1;
}

void do_to(object me, string arg, string str)
{
   seteuid(getuid());
   if(arg) me->force_me(arg + " " + str);
   else me->force_me(str);
}

int help(object me)
{
write(@HELP
指令格式 : to <指令>

可以一次输出多行以上的文字, <指令>通常是输出讯息的指令如
say，tell，describe，chat。。。等。
例如： 
>to say
结束离开用 '.'，取消输入用 '~q'，使用内建列编辑器用 '~e'。
—————————————————————————————

          ≡≡≡≡≡≡≡封神榜≡≡≡≡≡≡≡
            日曜星君 小道童 kuer             
            月曜星君 魂断兰桥 miner          
            金曜星君 三石 san                
            木曜星君 山水 wen                
            水曜星君 小楼 pxl                
            火曜星君 宰父多多 hengha         
            土曜星君 小英 nonn               
          ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡
.

输出到荧幕上的结果则是 :

你说道：
          ≡≡≡≡≡≡≡封神榜≡≡≡≡≡≡≡
            日曜星君 小道童 kuer             
            月曜星君 魂断兰桥 miner          
            金曜星君 三石 san                
            木曜星君 山水 wen                
            水曜星君 小楼 pxl                
            火曜星君 宰父多多 hengha         
            土曜星君 小英 nonn               
          ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡

HELP
    );
    return 1;
}

