// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// uptime.c

inherit F_CLEAN_UP;

// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
int report()
{
   int t, d, h, m, s;
   string time;

   t = uptime();
   s = t % 60;     t /= 60;
   m = t % 60;     t /= 60;
   h = t % 24;     t /= 24;
   d = t;

   if(d) time = chinese_number(d) + "天";
   else time = "";

   if(h) time += chinese_number(h) + "小时";
   if(m) time += chinese_number(m) + "分";
   time += chinese_number(s) + "秒。\n";

   write("西游记已经运行了" + time + "\n");
   return 1;
}

int main()
{
   report();
   write("\n");
   return 1;
}

int help(object me)
{
   write(@HELP
指令格式 : uptime
 
这个指令告诉你西游记已经运行了多久。
 
HELP
    );
    return 1;
}
