function btn_newGameClicked(){
    showSubMenu("NewGameSubMenu.qml");
}

function btn_settingsClicked() {
    showSubMenu("GlobalSettingsSubMenu.qml");
}

function btn_creditsClicked() {
    showSubMenu("CreditsSubMenu.qml");
}

function btn_statsClicked() {
    showSubMenu("StatsSubMenu.qml");
}

function showSubMenu(name) {
    col_mainMenu.visible = false;
    load_subMenu.source = name;
    load_subMenu.visible = true;
}

function btn_backClicked() {
    load_subMenu.visible = false;
    col_mainMenu.visible = true;
}

function btn_backToNewGameClicked() {
    load_singlePlayerSubMenu.visible = false;
    col_newGameSubMenu.visible = true;
}

function btn_singelPlayerClicked() {
    showNewGameSubMenu("SinglePlayerSubMenu.qml")
}

function btn_multiPlayerClicked(){
    showNewGameSubMenu("MultiPlayerSubMenu.qml")
}

function showNewGameSubMenu(name) {
    col_newGameSubMenu.visible = false;
    load_singlePlayerSubMenu.source = name;
    load_singlePlayerSubMenu.visible = true;
}
