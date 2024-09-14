#include "SemaPed.h"

//========================================================================================

/* LED PED_RED CONTROL */
void SemaphorePed::handle_PedRed() {
//----------------------------------------------------------------------------------------

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /* Ao apertar o botão, passará mais 17s até abrir a passagem para pedestres. Além disso,
       quando faltar 10s para o LED PED_RED apagar, ele deve piscar para sinalizar */
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /* Caso o botão seja apertado e já se passaram 17s (15s LED GREEN + 2s LED YELLOW) */
  if((btn_on == true) && ((millis() - millisPedestre) > 17000)) {
    digitalWrite(PED_RED, LOW);
  }

//----------------------------------------------------------------------------------------
  /* Caso o botão seja apertado, o LED PED_RED piscará para sinalizar os últimos 
                               10s do mesmo aceso */
  else if((btn_on == true) && ((millis() - millisPedestre) > 7000) && ((millis() - millisPedestre) < 7200)) {
      digitalWrite(PED_RED, LOW);
  }

//----------------------------------------------------------------------------------------
  else {
    /* Botão não apertado ou ainda não passou 17s, LED PED_RED deve estar aceso */
    digitalWrite(PED_RED, HIGH);

    /* Limpa os blocos do LCD utilizados na contagem regressiva */
    lcd.setCursor(14, 0);
    lcd.print(NOT_SQUARE);
    lcd.print(NOT_SQUARE);
  }
//----------------------------------------------------------------------------------------
}

//========================================================================================

/* LED PED_GREEN CONTROL */
void SemaphorePed::handle_PedGreen() {
//----------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /* Após 17s, deve-se abrir a passagem para pedestres, possuindo uma contagem 
                      regressiva para o LED PED_GREEN apagar */
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /* Caso botão foi apertado e já se passaram 17s (15s LED GREEN + 2s LED YELLOW) */ 
  if((btn_on == true) && ((millis() - millisPedestre) > 17000)) {

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /* O LED PED_GREEN ficará aceso por 21s, e o take contará quantos segundos já 
          se passaram desde o momento que o LED PED_GREEN acendeu */
    count = 21;
    int take_count = ((millis() - millisPedestre) - 17000) / 1000;

    /* Quantos segundos faltam para apagar o LED PED_GREEN */
    count = count - take_count;

    /* A condição de entrada deste if será atendida 1 vez a cada segundo, tal medida 
      evitará erros na hora de printar no LCD 16x2, já que, apenas quando a condição 
                      é atendida, a tela é apagada e reescrita */
    if(erase > count) {
      erase = count;
      /* Limpa os blocos do LCD 16x2 que são utilizados na contagem regresiva, 
              para que o próximo número possa ser escritos*/
      lcd.setCursor(14, 0);
      lcd.print(NOT_SQUARE);
      lcd.print(NOT_SQUARE);

      /* Posiciona o cursor a depender de quantas casas o número a ser printado possui */
      if(count < 10) lcd.setCursor(15, 0);  
      else lcd.setCursor(14, 0);
      
      /* Printa o número no LCD */
      lcd.print(count);
    }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /* Faltando 10s para LED PED_GREEN apagar, ele deve piscar para sinalizar */
    if(((millis() - millisPedestre) > 28000) && ((millis() - millisPedestre) < 28200)) {
      digitalWrite(PED_GREEN, LOW);
    }
    else {
      digitalWrite(PED_GREEN, HIGH);
    }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  }

//----------------------------------------------------------------------------------------
  else {
    /* Caso o botão não foi apertado ou ainda não se passaram 17s */
    digitalWrite(PED_GREEN, LOW);
  }
//----------------------------------------------------------------------------------------
}

//========================================================================================

/* LED PED_BLUE CONTROL */
void SemaphorePed::handle_PedBlue() {
//----------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /* Nos últimos 10s de LED PED_GREEN aceso, o LED PED_BLUE deve piscar com uma 
                  frequência de 2Hz até o LED PED_GREEN apagar */
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /* Caso o botão tenha sido apertado e está nos últimos 10s de LED PED_GREEN aceso */
  if((btn_on == true) && ((millis() - millisPedestre) > 28000)) {
    /* O ciclo do forBlue, repetirá 2 vezes por segundo */
    if((millis() - forBlue) > 500) {
      restart_forBlue();
    }

    /* Gerenciamento do LED PED_BLUE durante esses 10s */
    if((millis() - forBlue) < 250) {
      digitalWrite(PED_BLUE, HIGH);
    }
    else {
      digitalWrite(PED_BLUE, LOW);
    }
  }

//----------------------------------------------------------------------------------------
  else {
    /* Caso o botão não tenha sido apertado ou ainda não se passaram 28s */
    digitalWrite(PED_BLUE, LOW);
  }
//----------------------------------------------------------------------------------------

}

//========================================================================================

/* BUZZER CONTROL */
void SemaphorePed::controller_Buzzer() {
//----------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /* O Buzzer é responsável por diversos avisos sonoros durante o ciclo do semáforo. 
    - [1] Assim que o LED PED_GREEN acender, o Buzzer deve realizar um bip médio e mais 
      grosso que os bips no [2] para avisar que é permitida a passagem de pedestre
    - [2] Nos últimos 10s do LED PED_GREEN aceso, o Buzzer deve realizar um bip curto e 
             fino com uma frequência de 0,5Hz até o LED PED_GREEN apagar 
    - [3] No último segundo de LED PED_GREEN aceso, o Buzzer deve realizar um bip longo 
        e com mesma frequência que [1] por 1s, para sinalizar que o sinal para pedestre 
                                     está fechando*/
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  /* [1] */
  if((btn_on == true) && ((millis() - millisPedestre) > 17000) && ((millis() - millisPedestre) < 17600)) {
    tone(BUZZER, 2000);
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  /* [2] */
  else if((btn_on == true) && ((millis() - millisPedestre) > 28000)) {
    /* Mantem a frequência dos bips finos de 28s até 37s */
    if((millis() - millisPedestre) < 37000) {
      /* O ciclo do forBlue, repetirá 1 vez a cada 2 segundos */
      if((millis() - forBuzzer) > 2000) {
        restart_forBuzzer();
      }

      /* Gerenciamento do Buzzer por esses 9s */
      if((millis() - forBuzzer) < 300) {
        tone(BUZZER, 6500);
      }
      else {
        noTone(BUZZER);
      }

    }
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    else { 
      /* [3] */
      tone(BUZZER, 2000);
    }
    
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  }

//----------------------------------------------------------------------------------------
  else {
    noTone(BUZZER);
  }
//----------------------------------------------------------------------------------------
}

//========================================================================================

/* Reseta as flags, o count e o erase para o próximo ciclo */
void SemaphorePed::reset_flags_count() {
  btn_on = false;
  restart = true;
  count = 21;
  erase = 22;
}

//========================================================================================

/* Resetará o millisPedestre, e colocará a flag restart para false, não permitindo resetar 
  novamente o millisPedestre, mesmo que o botão seja apertado novamente, dentro dos 38s do 
              ciclo do semáforo (17s LED PED_RED + 21s LED PED_GREEN) */
void SemaphorePed::restart_millisPedestre() {
  millisPedestre = millis();
  restart = false;
}

//========================================================================================

/* Resetará o forBlue, permitindo que o LED PED_BLUE pisque na frequência requisitada */
void SemaphorePed::restart_forBlue() {
  forBlue = millis();
}

//========================================================================================

/* Resetará o forBuzzer, permitindo que o BUZZER faça bip na frequência requisitada */
void SemaphorePed::restart_forBuzzer() {
  forBuzzer = millis();
}

//========================================================================================

/* Construtor */
SemaphorePed::SemaphorePed() {
  millisPedestre = millis();
  forBlue = millis();
  forBuzzer = millis();
  btn_on = false;
  restart = true;
  count = 21;
  erase = 22;
}

//========================================================================================

/* Gerencia o funcionamento do semáforo para pedestres, chamando as outras funções e 
                estabelencendo uma lógica na visão "macro" */
void SemaphorePed::SemaPed() {
//----------------------------------------------------------------------------------------
  /* Caso o botão seja apertado, a flag bnt_on será setada como true e ocorrerá o restart 
    millisPedestre, forBlue e forBuzzer, se for permitido, ou seja, se restart == true */
  if(digitalRead(BUTTON) == LOW) {
    btn_on = true;
    if(restart == true) {
      restart_millisPedestre();
      restart_forBlue();
      restart_forBuzzer();
    }
  }

//----------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /* Caso o botão seja apertado e o restart é igual a false, significa dizer que está 
       sendo realizado o ciclo do semáforo (vermelho, verde). Entretanto, ao passar 38s, 
        o ciclo já se encerrou, portanto devemos resetar as flags e o count para que 
                           o sistema possa ser reiniciado */
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /* Reseta as flags, o count e o erase */
  if((btn_on == true) && (restart == false) && ((millis() - millisPedestre) > 38000)) {
    reset_flags_count();
  }

//----------------------------------------------------------------------------------------
  /* Chama as funções que gerenciam o comportamento dos LEDs e do Buzzer */
  handle_PedRed();
  handle_PedGreen();
  handle_PedBlue();
  controller_Buzzer();
}

//========================================================================================