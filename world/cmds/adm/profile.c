// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// profile.c

int main(object me, string arg)
{
   seteuid(geteuid(me));

   PROFILE_D->make_profile(arg);
   write("Result written to /PROFILE\n");

   return 1;
}
int help (object me)
{
        write(@HELP
指令格式: profile
 
turns on command profiling, the result will be saved to /PROFILE
 
HELP
);
        return 1;
}
 
