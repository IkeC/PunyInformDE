System_file;

! ext_cheap_scenery_de.h — German wrapper for ext_cheap_scenery.h
!
! Include this file instead of ext_cheap_scenery.h in German games.
! It pre-defines CS_DEFAULT_MSG with a German fallback reply, then
! loads the extension so the #Ifndef guard in ext_cheap_scenery.h
! skips the English default.
!
! You can override the message before including this file:
!   Constant CS_DEFAULT_MSG "Daran ist nichts Besonderes.";
!   Include "ext_cheap_scenery_de.h";

#Ifndef CS_DEFAULT_MSG;
Constant CS_DEFAULT_MSG "Du siehst nichts Interessantes daran.";
#Endif;

Include "ext_cheap_scenery.h";
