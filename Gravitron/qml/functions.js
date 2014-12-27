function btn_newGameClicked(){
    main_list.model = newGameMenu;
}

function btn_startGameClicked() {
    //showSubMenu("Game.qml");
    scrollView.visible = false;
    loader.visible = true;
    loader.source = "Game.qml";
    Game.setQmlParent(loader.item);
    Game.start();
}

function btn_settingsClicked() {
    main_list.model = globalSettingsMenu
}

function btn_creditsClicked() {
    main_list.model = creditsMenu
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

function btn_singelPlayerClicked() {
    main_list.model = singlePlayerMenu;
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
