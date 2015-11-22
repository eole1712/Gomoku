######################################################################
# Automatically generated by qmake (3.0) Sun Nov 22 14:25:35 2015
######################################################################

TEMPLATE = app
TARGET = Gomoku
INCLUDEPATH += . gui srcs/core srcs/rules
QMAKE_POST_LINK += cp Gomoku ..

QMAKE_CXXFLAGS += -std=c++11

QT += core gui widgets

# Input
HEADERS += gui/drawingArea.hpp \
           gui/gomokuButton.hpp \
           gui/mainwindow.h \
           gui/modifiableQLabel.hpp \
           gui/winchanger.hpp \
           QtFiles/ui_mainwindow.h \
           srcs/core/AI.hpp \
           srcs/core/Game.hpp \
           srcs/core/GameManager.hpp \
           srcs/core/GameMap.hpp \
           srcs/core/Human.hpp \
           srcs/core/IGame.hpp \
           srcs/core/IGameManager.hpp \
           srcs/core/IGameMap.hpp \
           srcs/core/IJudge.hpp \
           srcs/core/IPlayer.hpp \
           srcs/core/IRule.hpp \
           srcs/core/Judge.hpp \
           srcs/core/Player.hpp \
           srcs/rules/BasicCheck.hpp \
           srcs/rules/EatThem.hpp \
           srcs/rules/Win.hpp
FORMS += gui/mainwindow.ui
SOURCES += gui/drawingArea.cpp \
           gui/gomokuButton.cpp \
           gui/main.cpp \
           gui/mainwindow.cpp \
           gui/modifiableQLabel.cpp \
           gui/winchanger.cpp \
           srcs/core/AI.cpp \
           srcs/core/Game.cpp \
           srcs/core/GameManager.cpp \
           srcs/core/GameMap.cpp \
           srcs/core/Human.cpp \
           srcs/core/Judge.cpp \
           srcs/core/Player.cpp \
           srcs/rules/BasicCheck.cpp \
           srcs/rules/EatThem.cpp \
           srcs/rules/Win.cpp
