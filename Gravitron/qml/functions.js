function hideAllSubMenus() {
    newGameSubMenu.visible = false;
    settingsSubMenu.visible = false;
    creditsSubMenu.visible = false;
    statsSubMenu.visible = false;
    col_mainMenu.visible = false;
}

function hideAllNewGameSubMenus() {
    singlePlayerSubMenu.visible = false;
    multiPlayerSubMenu.visible = false;
    col_newGameSubMenu.visible = false;
}

function btn_newGameClicked(){
    hideAllSubMenus();
    newGameSubMenu.visible = true;
}

function btn_settingsClicked() {
    hideAllSubMenus();
    settingsSubMenu.visible = true
}

function btn_creditsClicked() {
    hideAllSubMenus()
    creditsSubMenu.visible = true
}

function btn_statsClicked() {
    hideAllSubMenus()
    statsSubMenu.visible = true
}

function btn_backClicked() {
    hideAllSubMenus();
    col_mainMenu.visible = true;
}

function btn_backToNewGameClicked() {
    hideAllNewGameSubMenus();
    col_newGameSubMenu.visible = true;
}

function btn_singelPlayerClicked() {
    hideAllNewGameSubMenus();
    singlePlayerSubMenu.visible = true;
}

function btn_multiPlayerClicked(){
    hideAllNewGameSubMenus();
    multiPlayerSubMenu.visible = true;
}
