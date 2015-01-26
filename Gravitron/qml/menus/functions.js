function btn_newGameClicked(){
    main_list.model = newGameMenu;
}

function btn_startGameClicked() {
    scrollView.visible = false;
    loader.visible = true;
    loader.source = "../Game.qml";
    Game.setQmlParent(loader.item);
    Game.start();
}

function btn_startMultiplayerGameClicked() {
    console.log("start game");
    scrollView.visible = false;
    loader.visible = true;
    loader.source = "../Game.qml";
    Game.setQmlParent(loader.item);
    Game.startServer(TcpServer);
}

function btn_joinMultiplayerGameClicked() {
    console.log("join game");
    scrollView.visible = false;
    loader.visible = true;
    loader.source = "../Game.qml";
    Game.setQmlParent(loader.item);
    Game.startClient(TcpClient);
}

function btn_settingsClicked() {
    main_list.model = globalSettingsMenu;
}

function btn_creditsClicked() {
    main_list.model = creditsMenu;
}

function btn_createMultiplayerGameClicked() {
    main_list.model = serverMenu;
}

function btn_createServerClicked() {
    TcpServer.startListen(txt_serverPort.value);
}

function btn_joinGameClicked() {
    main_list.model = clientMenu;
}

function btn_connectToServerClicked() {
    TcpClient.start(txt_serverHost.text, txt_clientServerPort.value);
}

function btn_statsClicked() {
    //showSubMenu("StatsSubMenu.qml");
    main_list.model = statsMenu
}

function showSubMenu(name) {
    load_subMenu.source = name;
}

function btn_backClicked() {
    main_list.model = mainMenu;
    scrollView.visible = true;
    loader.visible = false;
}

function btn_backToNewGameClicked() {
    main_list.model = newGameMenu
}

function btn_singlePlayerClicked() {
    main_list.model = startGameMenu;
}

function btn_multiPlayerClicked(){
    //showNewGameSubMenu("MultiPlayerSubMenu.qml")
    main_list.model = multiPlayerMenu;
}

function showNewGameSubMenu(name) {
    col_newGameSubMenu.visible = false;
    load_singlePlayerSubMenu.source = name;
    load_singlePlayerSubMenu.visible = true;
}
