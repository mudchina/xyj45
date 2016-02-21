// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
 
void do_drink();
 
void create()
{
        seteuid(getuid());
        set_name("李白", ({"li bai", "li"}));
        set("long", "大诗人李白，清高飘逸，剑术通神。\n");
        set("gender","男性");
   set("title", "诗仙");
   set("class", "scholar");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",100000);
        set("attitude","heroism");
        set("chat_chance",20);
        set("chat_msg", ({
        "李白低声长吟道：危楼高百尺，手可摘星辰。\n",
        "李白低吟道：而来四万八千岁，不与秦汉通人烟。\n",
        "李白鼓腹而歌：挥手自兹去，萧萧班马鸣。\n",

"李白击节而歌：赵客缦湖缨，吴钩霜雪明。银鞍照白马，飒沓如流星。\n",
        (: do_drink :),
        "李白低吟道：夫天地者，万物之逆旅。光阴者，百代之过客。\n",

"李白击节而歌：脚着谢公屐，身登青云梯。半壁见海日，空中闻天鸡。\n",
        "李白吟道：孤帆远影碧空尽，唯见长江天际流。\n",
        "李白朗声吟道：蜀道之难，难于上青天，侧身西望长咨嗟。\n",
        (: do_drink :),
        "李白低声长吟：红颜弃轩冕，白首卧松云。\n",
        "李白醉态毕露，朗声长吟：醉看风落帽，舞爱月流人。\n",
        "李白长吟道：音尘绝，西风残照，汉家陵阙。\n",
   (: random_move :)
        }));

        set("chat_chance", 10);

        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("unarmed", 80);
        set_skill("sword", 120);
        set_skill("literate", 120);
   set("max_force", 200);
   set("force", 200);
   set("force_factor", 10);
        set("max_kee", 700);
        set("max_gin", 400);
        set("max_sen", 500);

        setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
   carry_object("/d/obj/book/poem");
        add_money("silver", 40);
}
 
void do_drink()
{
    object *list, ob;
    int i, can_drink;
    if ((int)this_object()->query("water") >= 380) return;
    list = all_inventory(this_object());
    i = sizeof(list);
    can_drink = 0;
    while (i--) {
        if ((string)list[i]->query("liquid/type") == "alcohol") {
            ob = list[i];
            can_drink = 1;
        }
    }
    if (can_drink) {
        command("drink "+(string)ob->query("id"));
        if ((int)ob->query("liquid/remaining") == 0)
            command("drop "+(string)ob->query("id"));
    }
    else {
        command("sigh");
        command("say 酒．．．给我酒．．．");
    }
    return;
}

int accept_object(object who, object ob)
{   object m;
   m=new("/d/obj/book/jianpu.c");
    if ((string)ob->query("liquid/type")=="alcohol")
    {
        if ((int)ob->query("liquid/remaining") == 0)
        {
            command("shake");
            command("say 空的我不要．．．");
            return notify_fail("好象李白不是收破烂的，不要空瓶子。\n");
        }
        else
                if ( (string)ob->name()=="牛皮酒袋" )
                {
                        command ("frown");
                        command ("say 这酒还是您留着自己喝吧。");
                        return
notify_fail("好象李白看不起你给他的酒。\n");
                }
                else
                {
                        command("smile");
                        command("say 多谢!");
        if ((int)who->query_temp("mark/李白") < 1){
        who->set_temp("mark/李白", 1 ); 
        }
                        if(present("jian pu", this_object())) {
        return 0;
        }
                        who->add_temp("mark/李白", 1 );
                        call_out("destroy", 1, ob);
                if ((int)who->query_temp("mark/李白") >= 5+random(5))
                        {
command ( "whisper " + who->query("id") + 
" 我看您也是位练功习武的人，也算咱们有缘，这本剑谱就送给你拿去研读吧。\n");
          m->move(who);
                                who->set_temp("mark/李白", 0 );
          return 1;
                        }
                        return 1;
                }
        }
    }

void destroy(object ob)
{
        destruct(ob);
        return;
}

