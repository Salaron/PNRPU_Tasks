#ifndef TOPTITLEBAR_H
#define TOPTITLEBAR_H
#include <QWidget>
#include <QIcon>
#include <QStyle>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QSpacerItem>
#include <QApplication>
#include <QDebug>
#include "calculatorwindow.h"

class TopTitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TopTitleBar(QWidget *parent = 0)
        :QWidget(parent)
    {
        QPushButton *close = new QPushButton(this);
        close->setObjectName("closeButton");
        close->setVisible(false);
        close->setIcon(QIcon(":/assets/close.svg"));
        close->setMinimumSize(60, 30);
        close->setStyleSheet("QPushButton {\n  background-color: rgba(255, 255, 255, 0);\n  color: white; \nopacity: 0;\n  border: 0px;\n  border-radius: 0px;\n}\n\nQPushButton:hover {\n	background-color: rgb(232, 17, 35);\nopacity: 1;\n}\n\nQPushButton:pressed {\n    background-color: rgba(255, 255, 255, 0.6);\n}");
        connect(close, SIGNAL(released()), this, SLOT(closeApp()));

        QPushButton *aot = new QPushButton(this);
        aot->setObjectName("aotButton");
        aot->setIcon(QIcon(":/assets/external.png"));
        aot->setIconSize(QSize(24, 24));
        aot->setMinimumSize(32, 32);
        aot->setToolTip("Always on top");
        aot->setStyleSheet("QPushButton {\n  background-color: rgba(255, 255, 255, 0);\n  color: white; \nopacity: 0;\n  border: 0px;\n  border-radius: 0px;\n}\n\nQPushButton:hover {\n	background-color: rgba(255, 255, 255, 0.5);\n}\n\nQPushButton:pressed {\n    background-color: rgba(255, 255, 255, 0.6);\n}");
        connect(aot, SIGNAL(released()), this, SLOT(onAOT()));

        QSpacerItem *item = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Fixed);
        QHBoxLayout* layout = new QHBoxLayout(this);
        layout->addWidget(aot);
        layout->addSpacerItem(item);
        layout->setAlignment(close, Qt::AlignRight);
        layout->setSpacing(0);
        layout->addWidget(close);
        layout->setMargin(0);
        setLayout(layout);
    }


protected slots:
    void closeApp() {
        QApplication::quit();
    }

    void onAOT() {
        bool enable;
        QWidget* centralWidget = dynamic_cast<QWidget *> (parentWidget());
        if (centralWidget != nullptr)
        {
            CalculatorWindow* main = dynamic_cast<CalculatorWindow*>(centralWidget->parentWidget());
            if (main != nullptr) {
                main->switchAlwaysOnTop();
                enable = main->alwaysOnTop;
            }
        }
        QPushButton* close = nullptr;
        QPushButton* aot = nullptr;
        for (int i = 0; i < layout()->count(); ++i)
        {
          QWidget *widget = layout()->itemAt(i)->widget();
          if (widget != nullptr && widget->objectName() == "closeButton")
          {
            close = (QPushButton*)widget;
          }
          if (widget != nullptr && widget->objectName() == "aotButton") {

          }
        }

        if (close != nullptr) {
            close->setVisible(enable);
        }
        if (aot != nullptr) {
            if (enable) {
                aot->setToolTip("Full view");
                aot->setIcon(QIcon(":/assets/internal.png"));
                aot->setIconSize(QSize(24, 24));
            } else {
                aot->setToolTip("Always on top");
            }
        }
    }
};
#endif // TOPTITLEBAR_H
