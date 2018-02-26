/********************************************************************************
** Form generated from reading UI file 'subsiki.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBSIKI_H
#define UI_SUBSIKI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_subsikiClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QPushButton *closeButton;
    QLabel *Title;
    QTextEdit *Subtitles;
    QGridLayout *gridLayout_2;
    QLineEdit *line_mover;
    QPushButton *Move;
    QLabel *wrong_mover;
    QLabel *label_mover;
    QRadioButton *radioButton_down;
    QRadioButton *radioButton_up;
    QPushButton *Open;
    QPushButton *Save;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *subsikiClass)
    {
        if (subsikiClass->objectName().isEmpty())
            subsikiClass->setObjectName(QStringLiteral("subsikiClass"));
        subsikiClass->setEnabled(true);
        subsikiClass->resize(385, 503);
        subsikiClass->setToolButtonStyle(Qt::ToolButtonIconOnly);
        subsikiClass->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(subsikiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        closeButton = new QPushButton(centralWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setMaximumSize(QSize(170, 16777215));

        gridLayout_3->addWidget(closeButton, 0, 1, 1, 1);

        Title = new QLabel(centralWidget);
        Title->setObjectName(QStringLiteral("Title"));
        QFont font;
        font.setPointSize(12);
        Title->setFont(font);
        Title->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(Title, 0, 0, 1, 1);

        Subtitles = new QTextEdit(centralWidget);
        Subtitles->setObjectName(QStringLiteral("Subtitles"));
        Subtitles->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        Subtitles->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        Subtitles->setReadOnly(true);

        gridLayout_3->addWidget(Subtitles, 1, 0, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        line_mover = new QLineEdit(centralWidget);
        line_mover->setObjectName(QStringLiteral("line_mover"));
        line_mover->setMaximumSize(QSize(100, 30));
        line_mover->setInputMethodHints(Qt::ImhDigitsOnly);

        gridLayout_2->addWidget(line_mover, 0, 2, 1, 1);

        Move = new QPushButton(centralWidget);
        Move->setObjectName(QStringLiteral("Move"));
        Move->setMinimumSize(QSize(100, 0));
        Move->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(Move, 0, 0, 1, 1);

        wrong_mover = new QLabel(centralWidget);
        wrong_mover->setObjectName(QStringLiteral("wrong_mover"));
        wrong_mover->setInputMethodHints(Qt::ImhNone);
        wrong_mover->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(wrong_mover, 2, 2, 1, 1);

        label_mover = new QLabel(centralWidget);
        label_mover->setObjectName(QStringLiteral("label_mover"));
        label_mover->setMaximumSize(QSize(20, 16777215));
        label_mover->setLayoutDirection(Qt::LeftToRight);
        label_mover->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_mover, 0, 3, 1, 1);

        radioButton_down = new QRadioButton(centralWidget);
        radioButton_down->setObjectName(QStringLiteral("radioButton_down"));

        gridLayout_2->addWidget(radioButton_down, 4, 0, 1, 1);

        radioButton_up = new QRadioButton(centralWidget);
        radioButton_up->setObjectName(QStringLiteral("radioButton_up"));

        gridLayout_2->addWidget(radioButton_up, 2, 0, 1, 1);

        Open = new QPushButton(centralWidget);
        Open->setObjectName(QStringLiteral("Open"));
        Open->setMinimumSize(QSize(100, 0));
        Open->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(Open, 0, 5, 1, 1);

        Save = new QPushButton(centralWidget);
        Save->setObjectName(QStringLiteral("Save"));
        Save->setMinimumSize(QSize(100, 0));
        Save->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(Save, 2, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 6, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 2, 0, 1, 2);

        subsikiClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(subsikiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        subsikiClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(subsikiClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 385, 21));
        subsikiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(subsikiClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        subsikiClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(subsikiClass);
        QObject::connect(closeButton, SIGNAL(clicked()), Subtitles, SLOT(clear()));

        QMetaObject::connectSlotsByName(subsikiClass);
    } // setupUi

    void retranslateUi(QMainWindow *subsikiClass)
    {
        subsikiClass->setWindowTitle(QApplication::translate("subsikiClass", "subsiki", 0));
        closeButton->setText(QApplication::translate("subsikiClass", "Wyczy\305\233\304\207", 0));
        Title->setText(QApplication::translate("subsikiClass", "Tytu\305\202 filmu", 0));
        Move->setText(QApplication::translate("subsikiClass", "Przesu\305\204", 0));
        wrong_mover->setText(QApplication::translate("subsikiClass", "podaj liczb\304\231 \n"
"ca\305\202kowit\304\205", 0));
        label_mover->setText(QApplication::translate("subsikiClass", "[ms]", 0));
        radioButton_down->setText(QApplication::translate("subsikiClass", "Przesu\305\204 do\n"
" ty\305\202u", 0));
        radioButton_up->setText(QApplication::translate("subsikiClass", "Przesu\305\204 do\n"
" przodu", 0));
        Open->setText(QApplication::translate("subsikiClass", "Wczytaj", 0));
        Save->setText(QApplication::translate("subsikiClass", "Zapisz", 0));
    } // retranslateUi

};

namespace Ui {
    class subsikiClass: public Ui_subsikiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBSIKI_H
