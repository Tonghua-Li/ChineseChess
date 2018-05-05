TEMPLATE = subdirs

SUBDIRS += \
    AppLib \
    Tests \
    Chess

Chess.depends = AppLib
Tests.depends = AppLib
