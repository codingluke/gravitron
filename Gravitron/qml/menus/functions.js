function btn_newGameClicked(){
    modelLoader.source = "NewGame.qml"
}

function btn_startGameClicked() {
    main_audioPlayer.stop();
    scrollView.visible = false;
    loader.visible = true;
    loader.source = "../Game.qml";
    Game.setQmlParent(loader.item);
    Game.start();
}

function btn_startMultiplayerGameClicked() {
    console.log("start game");
    main_audioPlayer.stop();
    scrollView.visible = false;
    loader.visible = true;
    loader.source = "../Game.qml";
    Game.setQmlParent(loader.item);
    Game.startServer(TcpServer);
}

function btn_joinMultiplayerGameClicked() {
    console.log("join game");
    main_audioPlayer.stop();
    scrollView.visible = false;
    loader.visible = true;
    loader.source = "../Game.qml";
    Game.setQmlParent(loader.item);
    Game.startClient(TcpClient);
}

function btn_settingsClicked() {
    modelLoader.source = "GlobalSettings.qml"
}

function btn_creditsClicked() {
    modelLoader.source = "Credits.qml"
}

function btn_createMultiplayerGameClicked() {
    modelLoader.source = "Server.qml"
}

function btn_createServerClicked() {
    TcpServer.startListen(txt_serverPort.value);
}

function btn_joinGameClicked() {
    modelLoader.source = "Client.qml"
}

function btn_connectToServerClicked() {
    TcpClient.start(txt_serverHost.text, txt_clientServerPort.value);
}

function showSubMenu(name) {
    load_subMenu.source = name;
}

function btn_backClicked() {
    modelLoader.source = "Main.qml"
}

function btn_backToNewGameClicked() {
    modelLoader.source = "NewGame.qml"
}

function btn_singlePlayerClicked() {
    modelLoader.source = "StartGame.qml"
}

function btn_multiPlayerClicked(){
    modelLoader.source = "MultiPlayer.qml"
}

