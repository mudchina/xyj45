// suicide.c

#include <ansi.h>

inherit F_CLEAN_UP;
int rmhirdir(string dir);
int main(object me, string arg)
{
	if( me->is_busy() )
		return notify_fail("你上一个动作还没完成。\n");

	if( !arg ) {
		write("You commit suicide.\n");
		return 1;
	}

	if( arg!="-f" ) 
		return notify_fail("自杀有两种，您是要永远死掉还是重新投胎？\n");

	write(
		"如果您选择永远死掉的自杀方式，你的资料就永远删除了，一但\n"
		"输入密码则不可再后悔了：");
	input_to("check_password", 1, me, 1);
	return 1;
}

private void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;
	string name;
	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("密码错误！\n");
		return;
	}

	if (forever) {
		tell_object( me,
			HIR "\n\n永别了，希望你在风云玩得开心...。\n\n\n" NOR);
        link_ob = me->query_temp("link_ob");
        if( !link_ob ) return 0;

        log_file("static/SUICIDE",
                sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );

        seteuid(getuid());
        name = me->query("id");
       LOGIN_D->cphirdir(DATA_DIR + "login/" + name[0..0] + "/" + name, "/suicide/login/"+name+time());
       LOGIN_D->cphirdir(DATA_DIR + "user/" + name[0..0] + "/" + name, "/suicide/user/"+name+time());
      rmhirdir(DATA_DIR + "login/" + name[0..0] + "/" + name );
      rmhirdir(DATA_DIR + "user/" + name[0..0] + "/" + name );

        tell_room(environment(me), me->name() +
                "自杀了，以後你再也看不到这个人了。\n", ({me}));
        destruct(me);
        return 0;

	}
}
int rmhirdir(string dirstr)
{
string *dir;
int i;
dir = get_dir(dirstr+"/");
        for(i=0; i<sizeof(dir); i++) {
                if(file_size(dirstr+"/"+dir[i]) == -2 ) {
                                rmhirdir( dirstr +"/"+dir[i]);
                                rmdir(dirstr+"/"+dir[i]);
                                                }
                rm(dirstr+"/"+dir[i]);
        }
rmdir(dirstr);

return 1;

}
int help (object me)
{
        write(@HELP
指令格式: suicide [-f]
 
如果因为某种原因你不想活了, 你可以选择自杀.
自杀分两种:
 
suicide    : 重新投胎
suicide -f : 永远的除去玩家资料, 系统会要求你
             输入密码以确认身份.
 
请慎重选择 :)
 
HELP
);
        return 1;
}

