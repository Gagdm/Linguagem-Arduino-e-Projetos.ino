#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "constantes.h"

class Controller {
  private:

    unsigned long forBlocked;

    void block_microwave();

    void fix_clock();

    void choose_timer();

    void timer();

    void fan_menu();

    void fan_on();

    void fan_off();

    void thirty_seconds();

    void choose_time();

    void power_menu();

    void choose_power();

    void cooking(); 

    void stopped_cooking();

    void easy_menu();

    void popcorn_menu();

    void confirm_popcorn();

    void confirm_mugcake();

    void confirm_omelet();

    void rice_menu();

    void confirm_rice();

    void confirm_brigadeiro();

    void pizza_menu();

    void confirm_pizza();

    void beans_menu();

    void confirm_beans();

    void meat_menu();

    void confirm_meat();

    void chicken_menu();

    void confirm_chicken();

    void thaw_on();

    void thaw_off();

    void list_menu();

    void list_mode();

  public:

    Controller();

    void task_manager();

};

#endif