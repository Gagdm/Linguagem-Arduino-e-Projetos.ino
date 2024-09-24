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

## Detalhes do funcionamento

1. O semáforo para carros deverá ficar aberto até que algum pedestre tenha interesse em atravessar a rua, ou seja, apertar o botão;
2. O semaforo para pedestre deverá permanecer fechado, enquanto existir a possibilidade de transito de carros.
3. Após o botão ser pressionado, irá iniciar um ciclo de 38s;
4. Após os 38s, o semáforo voltará a seu estado base.

### Ciclo:

