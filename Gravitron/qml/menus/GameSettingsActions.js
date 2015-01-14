function getSlidePlayingFieldSize() {
    return Settings.playingFieldSize;
}

function slide_playingFieldSizeChanged() {
    Settings.setPlayingFieldSize(slide_playingFieldSize.value);
}

function getSlideBotsCount() {
   return Settings.botsCount;
}

function slide_botsCountChanged() {
    Settings.setBotsCount(slide_botsCount.value);
}

function getSlidePlanetCount() {
   return Settings.planetCount;
}

function slide_planetCountChanged() {
    Settings.setPlanetCount(slide_planetCount.value);
}

function getSlideAstroidCount() {
    return Settings.astroidCount;
}

function slide_astroidCountChanged() {
    Settings.setAstroidCount(slide_astroidCount.value);
}

function getSlideFrag() {
    return Settings.frag;
}

function slide_fragChanged() {
    Settings.setFrag(slide_frag.value);
}

function getSlideRespawTime() {
    return Settings.respawTime;
}

function slide_respawTimeChanged() {
    Settings.setRespawTime(slide_respawTime.value);
}
