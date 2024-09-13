#include "SemaCar.h"

/* Variáveis que guardam os ASCII dos caracteres 
              a serem utilizados */
char SQUARE = S;
char NOT_SQUARE = NS;

//========================================================================================

/* LED GREEN CONTROL */
void Semaphore::handle_green() {
//----------------------------------------------------------------------------------------
  /* Caso o botão não tenha sido apertado, o LED GREEN continuará 
      aceso e o LCD 16x2 continuará printando 10 SQUAREs */
  if(btn_on == false) {
    digitalWrite(GREEN, HIGH);
    for(int i = 0; i < 10; i ++) {
      lcd.setCursor(i,0);
      lcd.print(SQUARE);
      lcd.setCursor(i,1);
      lcd.print(SQUARE);
    }
  }

//----------------------------------------------------------------------------------------
  /* Caso o botão seja apertado, o LED GREEN ficará aceso por mais 15s */
  if (((millis() - millisCarro) < 15000) && (btn_on == true)) {
    digitalWrite(GREEN, HIGH);

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /* Nos últimos 10s do LED GREEN aceso no ciclo corrente, o LCD 16x2 irá diminuindo 
                  a quantidade de SQUAREs printados até chegar a 0 */
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /*  Antes de 5s a tela do LCD irá se manter inalterada. Passados 5s, o LCD 16x2 
    piscará e, a partir desse momento, começa-se a decrementar a quantidade de SQUAREs */     
    if(((millis() - millisCarro) < 5000) || (((millis() - millisCarro) > 5200) && ((millis() - millisCarro) < 6000))) {
        for(int i = 0; i < 10; i ++) {
          lcd.setCursor(i,0);
          lcd.print(SQUARE);
          lcd.setCursor(i,1);
          lcd.print(SQUARE);
        }
    }
    else if(((millis() - millisCarro) > 5000) && ((millis() - millisCarro) < 5200)) {
      lcd.clear();
    }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /* Nos próximos 10s, a quantidade de SQUAREs printados pelo LCD 16x2 sofrerá um 
                      decréscimo de 1 unidade a cada segundo */
    if(((millis() - millisCarro) > 6000) && ((millis() - millisCarro)  < 15000)) { 
      /* take é a quantidade que devemos retirar do número inicial de SQUAREs (10), mudará 
                                   a cada seg, cálculos: 
              time(5000 à 15000) - 5000(para retirar os 5s anteriores)] / 1000 */
      int take_green = ((millis() - millisCarro) - 5000) / 1000;

      /* A condição de entrada deste if será atendida apenas 1 vez a cada segundo, 
        tal medida evitará erros na hora de printar no LCD 16x2, já que, apenas 
                quando a condição é atendida, a tela é apagada */
      if(count < take_green) {
        count = take_green;
        lcd.clear();
      }

      /* Printa os SQUAREs */
      for(int i = 0; i < 10 - take_green; i++) {
        lcd.setCursor(i,0);
        lcd.print(SQUARE);
        lcd.setCursor(i,1);
        lcd.print(SQUARE);
      }
    }   
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  }

//----------------------------------------------------------------------------------------
  else {
    /* Botão foi apertado e já se passaram os últimos 15s do LED GREEN ligado, logo 
          o estado do semáfaro será outro neste momento (amarelo ou vermelho), 
                            por isso devemos desliga-lo */
    digitalWrite(GREEN, LOW);
  }

//----------------------------------------------------------------------------------------
}

//========================================================================================

/* LED YELLOW CONTROL */
void Semaphore::handle_yellow() {
//----------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /* LED YELLOW deve acender, caso o botão tenha sido apertado e, desde a primeira ação, 
    já se passaram 15s (tempo do LED GREEN aceso). Além disso, limpa-se o LCD 16x2 para que 
    não seja printado nada durante esse estado do semafóro e seta novamente o 'count' como -1, 
    pois o utilizaremos da mesma forma posteriormente, porém, dessa vez, com o LED RED */
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  /* LED YELLOW ficará aceso por 2s e limpa a tela do LCD 16x2 
             (para apagar o SQUARE remanescente) */
  if (((millis() - millisCarro) > 15000) && ((millis() - millisCarro) < 17000) && (btn_on == true)) {
    digitalWrite(YELLOW, HIGH);
    lcd.clear();
    count = -1;
  }

//----------------------------------------------------------------------------------------
  else {
    /* O semáforo está em algum outro estado (verde ou vermelho), 
                   por isso devemos desliga-lo */
    digitalWrite(YELLOW, LOW);
  }

//----------------------------------------------------------------------------------------
}

//========================================================================================

void Semaphore::handle_red() {
//----------------------------------------------------------------------------------------
  /* Caso o botão seja apertado e já se passaram 17s (15s LED GREEN + 2s LED YELLOW), 
                              LED RED deve acender */
  if (((millis() - millisCarro) > 17000) && (btn_on == true)) {
    digitalWrite(RED, HIGH);

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /* Nos últimos 10s do LED RED aceso no ciclo corrente, o LCD 16x2 irá diminuindo 
                  a quantidade de SQUAREs printados até chegar a 0 */
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /*  Antes de 27s a tela do LCD irá se manter inalterada. Passados 27s, o LCD 16x2 
    piscará e, a partir desse momento, começa-se a decrementar a quantidade de SQUARES */ 
    if(((millis() - millisCarro) < 27000) || (((millis() - millisCarro) < 28000) && ((millis() - millisCarro) > 27200))) {
      for(int i = 0; i < 10; i ++) {
        lcd.setCursor(i,0);
        lcd.print(SQUARE);
        lcd.setCursor(i,1);
        lcd.print(SQUARE);
      }
    }
    if(((millis() - millisCarro) > 27000) && ((millis() - millisCarro) < 27200))  {
      lcd.clear();
    }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /* Nos próximos 10s, a quantidade de SQUAREs printados pelo LCD 16x2 sofrerá um 
                      decréscimo de 1 unidade a cada segundo */
    if(((millis() - millisCarro) > 28000) && ((millis() - millisCarro)  < 38000)) {
      /* take é a quantidade que devemos retirar do número inicial de SQUAREs (10), mudará 
                                   a cada seg, cálculos: 
              time(28000 à 38000) - 5000(para retirar os 5s anteriores)] / 1000 */
      int take_red = ((millis() - millisCarro) - 27000) / 1000;

      /* A condição de entrada deste if será atendida apenas 1 vez a cada segundo, 
        tal medida evitará erros na hora de printar no LCD 16x2, já que, apenas 
                quando a condição é atendida, a tela é apagada */
      if(count < take_red) {
        count = take_red;
        lcd.clear();
      }

      /* Printa os SQUAREs */
      for(int i = 0; i < 10 - take_red; i++) {
        lcd.setCursor(i,0);
        lcd.print(SQUARE);
        lcd.setCursor(i,1);
        lcd.print(SQUARE);
      }
    }
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  }

//----------------------------------------------------------------------------------------
  else {
    /* Botão foi apertado e ainda não se chegou nos 17s, desde a primeira ação, logo 
          o estado do semáfaro será outro nesse momento (verde ou amarelo), 
                            por isso devemos desliga-lo */
    digitalWrite(RED, LOW);
  }
//----------------------------------------------------------------------------------------
}

//========================================================================================

/* Reseta as flags e o count para o próximo ciclo */
void Semaphore::reset_flags_count() {
  btn_on = false;
  restart = true;
  count = -1;
}

//========================================================================================

/* Resetará o millisCarro, e colocará a flag restart para false, não permitindo resetar 
  novamente o millisCarro, mesmo que o botão seja apertado novamente, dentro dos 38s do 
          ciclo do semáforo (15s LED GREEN + 2s LED YELLOW + 21s LED RED) */
void Semaphore::restart_millisCarro() {  
  millisCarro = millis();
  restart = false;  
}

//========================================================================================

/* Construtor */
Semaphore::Semaphore() {
  millisCarro = millis();
  btn_on = false;
  restart = true;
  count = -1;
}

//========================================================================================

/* Gerencia o funcionamento do semáforo para carros, chamando as outras funções e 
                estabelencendo uma lógica na visão "macro" */
void Semaphore::SemaCar() {
//----------------------------------------------------------------------------------------
  /* Caso o botão seja apertado, a flag bnt_on será setada como true e ocorrerá o restart 
            do millisCarro, se for permitido, ou seja, se restart == true */
  if (digitalRead(BUTTON) == LOW) {
    btn_on = true;
    if((restart == true)) {
      restart_millisCarro();
    }
  }

//----------------------------------------------------------------------------------------

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /* Caso o botão seja apertado e o restart é igual a false, significa dizer que está 
        sendo realizado o ciclo do semáforo (verde, amarelo, vermelo). Entretanto, ao 
       passar 38s, o ciclo já se encerrou, portanto devemos resetar as flags e o count 
                      para que o sistema possa ser reiniciado */
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  /* reseta as flags e o count */
  if((btn_on == true) && (restart == false) && ((millis() - millisCarro) > 38000)) {
    reset_flags_count();
  } 

//----------------------------------------------------------------------------------------
  /* Chama as funções que gerenciam o comportamento dos LEDs */
  handle_green();
  handle_yellow();
  handle_red();
}

//========================================================================================