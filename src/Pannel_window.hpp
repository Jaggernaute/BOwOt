//
// Created by jaggernaute on 3/10/22.
//

#ifndef PROJECT_ADMIN_INTERFACE_PANNEL_WINDOW_HPP
#define PROJECT_ADMIN_INTERFACE_PANNEL_WINDOW_HPP

#include <QMainWindow>
#include <QApplication>
#include "../include/Users.hpp"

class Pannel_window: public QMainWindow {
    QMainWindow *window;
    QVBoxLayout *window_layout = new QVBoxLayout();
    QGridLayout *cards_layout = new QGridLayout();
    QWidget *cards_widget = new QWidget();
    QVBoxLayout *add_user_layout = new QVBoxLayout();
    QWidget *window_widget = new QWidget();

public:
    Pannel_window(){
        window = new QMainWindow();
        window->setWindowTitle("Liste utilisateurs");
        window->resize(QApplication::screens()[0]->size());
        display_users();
        add_user();

        window_layout->addWidget(cards_widget);
        window_layout->addLayout(add_user_layout);
        window_widget->setLayout(window_layout);

        window->setCentralWidget(window_widget);
        window->show();
    }

    void display_users() {
        auto user_list = Users::get_user(12);
        int row = 0;
        int col = 0;
        for(const auto& user: user_list){

            if (col == 4) {
                col = 0;
                row++;
            }
            if ((row == 3) && (col <= 4)) {
                return;
            }

            auto user_layout = new QVBoxLayout();

            auto user_name = new QLabel(user.get_name());
            auto user_id = new QLabel("#" + QString::number(user.get_id()));
            auto user_email = new QLabel(user.get_email());
            auto user_id_badge = new QLabel(user.get_id_badge());
            auto user_last_reservation = new QLabel(user.get_last_reservation().toString());

            user_layout->addWidget(user_name);
            user_layout->addWidget(user_id);
            user_layout->addWidget(user_email);
            user_layout->addWidget(user_id_badge);
            user_layout->addWidget(user_last_reservation);

            auto card = new QWidget();
            card->setFixedSize(300,150);
            card->setStyleSheet("background-color: #1C2837;");
            card->setLayout(user_layout);

            cards_layout->addWidget(card, row, col);
            col++;
        }
        cards_widget->setLayout(cards_layout);
    }

    void add_user(){
        auto hlayout = new QHBoxLayout();

        auto name = new QLineEdit();
        name->setPlaceholderText("Prenom");
        auto surname = new QLineEdit();
        surname->setPlaceholderText("Nom");
        auto email = new QLineEdit();
        email->setPlaceholderText("Email");
        auto id_badge = new QLineEdit();
        id_badge->setPlaceholderText("Badge");

        auto add_button = new QPushButton("Ajouter");
        add_button->setStyleSheet("background-color: #1C2837; color: #F5F6F7;");
        add_button->setFixedSize(100,50);
        add_button->setFont(QFont("Arial", 12));
        add_button->setCursor(Qt::PointingHandCursor);
        add_button->setFocusPolicy(Qt::NoFocus);
        add_button->setFlat(true);
        add_button->setIcon(QIcon(":/icons/add.png"));
        add_button->setIconSize(QSize(20,20));
        add_button->setToolTip("Ajouter un utilisateur");

        hlayout->addWidget(surname);
        hlayout->addWidget(name);
        hlayout->addWidget(email);
        hlayout->addWidget(id_badge);-
        hlayout->addWidget(add_button);



        auto title = new QLabel("Ajout client");
        title->setStyleSheet("color: #F5F6F7;");
        title->setFont(QFont("Arial", 18));

        add_user_layout->addWidget(title);
        add_user_layout->addLayout(hlayout);
    }
};

#endif //PROJECT_ADMIN_INTERFACE_PANNEL_WINDOW_HPP
