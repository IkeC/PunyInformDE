! PunyInformDE: Custom German ZSCII alphabet table.
!
! MUST be included before any string literals in the game source,
! including "Constant Story ..." (per fredrikr, PunyInform dev).
!
! Puts German umlauts (ä ö ü ß Ä Ö Ü) into the cheapest row (A0)
! of the ZSCII alphabet table so each encodes as 1 Z-character instead
! of 2-4, saving space in Z5+ Unicode story files.
!
! Row layout (vs. standard):
!   A0 (1 zchar): umlauts replace j (pos 9→ä, 15→ö, 22→ü, 23→ß)
!   A1 (2 zchar): uppercase umlauts replace J; j placed here (pos 25)
!   A2 (2 zchar): q x y J Q X Y added; _ # ' \ / ( ) " removed
!
! Only applies to V5+ games without USE_ASCII (Z3/ASCII builds skip this).

#IfV5;
#IfNDef USE_ASCII;
Zcharacter
    "abcdefghiäklmnopörstuvwüßz"
    "ABCDEFGHIÄKLMNOPÖRSTUVWÜjZ"
    "0123456789.,!?_#'/-:();";
#EndIf; ! USE_ASCII
#EndIf; ! IfV5
