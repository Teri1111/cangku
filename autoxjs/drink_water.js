



//----------------调试--------------



appname = "微信";
launchApp(appname);

sleep(900);
click(70, 220);

while(textContains("文件传输助手").exists()){
    sleep(900);
    click(70, 220);

}


var pay_button = text("确认支付").findOne();

click(pay_button.bounds().centerX(), pay_button.bounds().centerY());
sleep(1000);


textContains("小象挖井").waitFor();
sleep(1000);
click(720, 2900);



// var send_button = textContains("文件传输助手").findOne();

// click(send_button.bounds().centerX(), send_button.bounds().centerY());

// var drink_link = textContains("jiuijngwulian").findOne();

// click(drink_link.bounds().centerX(), drink_link.bounds().centerY());
// var suspend_window_button = id("actionbar_up_indicator").findOne();


// click(suspend_window_button.bounds().centerX(), suspend_window_button.bounds().centerY());
