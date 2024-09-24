# 🚦Semaphore + Accessibility🚦

![Exemple-circuit](https://github.com/user-attachments/assets/63262d62-951e-4416-9e38-bbca50f7e2c0)

> Circuio parecido com o que foi utilizado no projeto, modelo feito no Tinkercard.
## Resumo do projeto

Projeto com Arduino UNO, utilizando as linguagens C e C++. 
 - Esse projeto visa fazer um modelo de semáforo, mesclando o atual sistema com ideias de acessibilidade, auxiliando pessoas com deficiências visuais e auditivas, garantindo o direito de ir e vim das mesmas.

### Componentes: 

 - [x] 1 Arduino UNO;
 - [x] 1 Protoboard, suficientemente grande para a montagem do circuito;
 - [x] 1 LCD 16x2;
 - [x] 1 Buzzer;
 - [x] 1 Potenciômetro (opicional);
 - [x] 2 LEDs verdes;
 - [x] 2 LEDs vermelhos
 - [x] 1 LED azul;
 - [x] 1 LED amarelo;
 - [x] 1 Botão;
 - [x] 6 Resistores 300Ω ou 330Ω;
 - [x] 1 Resistor 10kΩ, a depender do tipo do botão utilizado;
 - [x] Fios para a montagem do circuito. 

## Detalhes de funcionamento

1. O semáforo para carros deverá ficar aberto até que algum pedestre tenha interesse em atravessar a rua, ou seja, apertar o botão;
2. O semaforo para pedestre deverá permanecer fechado, enquanto existir a possibilidade de transito de carros.
3. Após o botão ser pressionado, irá iniciar um ciclo de 38s;
4. Durante o ciclo, os LEDs verde e vermelho, tanto para carros quanto para pedestres, devem piscar para sinalizar os seus últimos 10s de acesso.
5. O mesmo deverá acontecer com o LCD 16x2;
6. Após os 38s, o semáforo voltará a seu estado base.

**OBS¹**: _O ciclo não poderá ser reiniciado enquanto um ciclo já estiver em andamento, mesmo que o botão seja pressionado novamente._

**OBS²**: _Toda contagem regressiva relacionada ao semáforo de pedestres é exibida em números decimais._

**OBS³**: _Toda contagem regressiva relacionada ao semáforo para carros é exibida em "barras", simulando um semáforo real._

### Ciclo:

- ***Após o botão ser apertado (Primeiros 15s):***
  
  - Nos primeiros 5s, o semáforo se mantem inalterado;
  - Nos últimos 10s do semáforo aberto para os carros, o LCD 16x2 mostrará uma contagem regressiva.

- ***Após 15s (15-17s):***
  
  - O semáforo para carros deverá ficar amarelo por 2 segs;
  - Note que o semáforo para pedestre deverá continuar fechado.
 
- ***Após 17s (17-38s):***
  
  - O semáforo para pedestres deverá estar aberto, enquanto o para carros deverá estar fechado;
  - O buzzer deverá sinalizar a abertura do trânsito de pedestre;
  - O LCD deve exibir uma contagem regressiva, com números decimais, para o fechamento do semáforo para pedestres.

  ***Nos últimos 10s do ciclo (28-38s):***
  
  - O buzzer deverá tocar a uma frequência de 0,5 Hz para sinalizar que o semáforo de pedestres está prestes a fechar.
  - O LED azul deverá piscar a uma frequência de 2Hz pelo mesmo motivo;
  - O LCD, além de continuar a contagem regressiva já mencionada, deverá exibir também uma outra para a abertura do semáforo para carros.
 
  ***No último segundo (37-38s):***

  - O buzzer deverá sinalizar o fechamento do semáforo para pedestre.
 
---



