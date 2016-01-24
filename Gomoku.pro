######################################################################
# Automatically generated by qmake (3.0) Sun Nov 22 14:25:35 2015
######################################################################

TEMPLATE = app
TARGET = Gomoku
INCLUDEPATH += . srcs/gui srcs/core srcs/rules
##QMAKE_POST_LINK += cp Gomoku ..

CONFIG += c++11

QT += core gui widgets

# Input
HEADERS += srcs/gui/drawingArea.hpp \
           srcs/gui/Gui.hpp \
           srcs/gui/IGui.hpp \
           srcs/gui/gomokuButton.hpp \
           srcs/gui/mainwindow.h \
           srcs/gui/modifiableQLabel.hpp \
           srcs/gui/winchanger.hpp \
           srcs/core/AI.hpp \
           srcs/core/Game.hpp \
           srcs/core/GameManager.hpp \
           srcs/core/GameMap.hpp \
           srcs/core/Case.hpp \
           srcs/core/Human.hpp \
           srcs/core/IGame.hpp \
           srcs/core/IGameManager.hpp \
           srcs/core/IGameMap.hpp \
           srcs/core/IJudge.hpp \
           srcs/core/IPlayer.hpp \
           srcs/core/IRule.hpp \
           srcs/core/Judge.hpp \
           srcs/core/Player.hpp \
           srcs/core/Node.hpp \
           srcs/core/MinMax.hpp \
           srcs/rules/BasicCheck.hpp \
           srcs/rules/EatThem.hpp \
           srcs/rules/Win.hpp \
           srcs/rules/DoubleThree.hpp
FORMS += srcs/gui/mainwindow.ui
SOURCES += srcs/gui/drawingArea.cpp \
           srcs/gui/Gui.cpp \
           srcs/gui/gomokuButton.cpp \
           srcs/gui/mainwindow.cpp \
           srcs/gui/modifiableQLabel.cpp \
           srcs/gui/winchanger.cpp \
           srcs/core/AI.cpp \
           srcs/core/Game.cpp \
           srcs/core/GameManager.cpp \
           srcs/core/GameMap.cpp \
           srcs/core/Case.cpp \
           srcs/core/Human.cpp \
           srcs/core/Judge.cpp \
           srcs/core/Player.cpp \
           srcs/core/Node.cpp \
           srcs/core/MinMax.cpp \
           srcs/rules/BasicCheck.cpp \
           srcs/rules/EatThem.cpp \
           srcs/rules/Win.cpp \
           srcs/rules/DoubleThree.cpp \
           srcs/core/main.cpp
