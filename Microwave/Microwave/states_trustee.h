#ifndef STATES_TRUSTEE_H
#define STATES_TRUSTEE_H

#include "constantes.h"
#include "controller.h"

class Manager {
    private:

        bool check_three;
        char three_seconds;
        unsigned long forThree;
        
        int new_state;

        int turn_off();

        int init(); 

        int init_help();

        int blocked();

        int fix_clock();

        int choose_timer();

        int timer();

        int fan_menu();

        int fan_on();

        int fan_off();

        int thirty_seconds();

        int choose_time();

        int power_menu();

        int choose_power();

        int cooking(); 

        int stopped_cooking();

        int easy_menu();

        int popcorn_menu();

        int confirm_popcorn();

        int confirm_mugcake();

        int confirm_omelet();

        int rice_menu();

        int confirm_rice();

        int confirm_brigadeiro();

        int pizza_menu();

        int confirm_pizza();

        int beans_menu();

        int confirm_beans();

        int meat_menu();

        int confirm_meat();

        int chicken_menu();

        int confirm_chicken();

        int thaw_on();

        int thaw_off();

        int list_menu();

        int list_mode();

        void check_timer();

    public:

        Manager();

        void state_manager();

};

#endif
