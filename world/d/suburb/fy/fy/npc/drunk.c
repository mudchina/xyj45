inherit NPC;
 
void do_drink();
 
void create()
{
        seteuid(getuid());
        set_name("醉汉", ({"drunk", "man", "drunk man"}));
        set("long", @TEXT
 
TEXT
        );
        set("gender","男性");
        set("age",37);
        set("con",30);
        set("str",30);
        set("combat_exp",100);
        set("attitude","heroism");
        set("chat_chance",10);
        set("chat_msg", ({
        (: do_drink :), }) );
        setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/example/wineskin");
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
            command("drop wineskin");
    }
    else {
        command("sigh");
        command("say 酒..... 给我酒....");
    }
    return;
}
 
int accept_object(object who, object ob)
{
    if ((string)ob->query("liquid/type")=="alcohol") {
        if ((int)ob->query("liquid/remaining") == 0) {
            command("shake");
            command("say 空的我不要...");
            return 0;
        }
        else {
            command("smile");
            command("say 多谢!");
            return 1;
        }
    }
    else return 0;
}
 
