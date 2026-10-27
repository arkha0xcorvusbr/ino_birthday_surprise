# Arduino Birthday Trigger & PC Automator

Este projeto integra hardware e software para criar uma "bomba-relógio" de aniversário. Através de um circuito controlado por um Arduino Uno, o sistema realiza uma contagem regressiva, e em seguida, toca a melodia de "Parabéns a Você". Além disso, o Arduino envia um comando via porta Serial para um script em Python rodando em segundo plano no computador, disparando automações para a abertura de arquivos, vídeos, imagens ou outros scripts.

## Hardware Necessário
* 1x Arduino Uno;
* 1x Buzzer (Conectado ao Pino Digital 8);
* 3x LEDs (Conectados aos Pinos Digitais 2, 3 e 4);
* 3x Resistores 220Ω (Cada resitor conectado ao ponto positivo de cada LED);
* 1x Push Button (Conectado ao Pino Digital 7);
* Protoboard e cabos Jumper macho-macho;
* *Nota: O botão utiliza o resistor interno de pull-up do Arduino (`INPUT_PULLUP`).*

## Esquema de Ligação (Hardware)
1. Conecte os LEDs aos pinos 2, 3 e 4, aterrando os polos negativos na linha de GND da protoboard.
2. Conecte o pino positivo do Buzzer ao pino 8 e o negativo ao GND.
3. Conecte uma perna do botão ao pino 7 e a perna diagonal oposta ao GND.
4. Feche o circuito ligando a linha de GND da protoboard a um dos pinos GND do Arduino.

`Exemplos de como a protoboard deve ficar`:

<img width="600" height="400" alt="imagem de exemplo" src="https://github.com/user-attachments/assets/11c8cd19-4656-4152-ab13-78df30444412" />

<img width="600" height="400" alt="WhatsApp Image 2026-10-26 at 00 45 24" src="https://github.com/user-attachments/assets/2a32c085-0daf-44a7-9d2d-47a50a25772c" />

<img width="600" height="400" alt="WhatsApp Image 2026-10-26 at 00 45 25" src="https://github.com/user-attachments/assets/f3ae25ba-5b6c-41a4-a491-97a49fe9b12c" />

## Configuração do Ambiente (Software)

### 1. Arduino
Faça o upload do arquivo `anniversary.ino` para a sua placa utilizando a Arduino IDE. Certifique-se de que a placa e a porta COM estão selecionadas corretamente.

### 2. Python
O script `Aniversario.py` atua como um ouvinte da porta Serial. Para executá-lo, você precisará da biblioteca `pyserial`.

Instale a dependência via terminal:
```bash
pip install pyserial
```
Edite o arquivo Aniversario.py e altere a variável porta_arduino para a porta correspondente ao seu Arduino (ex: COM3, COM5, /dev/ttyUSB0). Execute o script em segundo plano antes de acionar o botão físico.

## Como Utilizar
1. Com o circuito energizado via USB e o script Python em execução, pressione o botão na protoboard;
2. A contagem regressiva de 4 segundos será iniciada com bips curtos e os LEDs piscando simultaneamente;
3. No 5º segundo, o buzzer emitirá frequências rápidas e os LEDs piscarão de forma aleatório;
4. O sinal EXECUTAR_SCRIPT será enviado via Serial para o computador, acionando a automação programada no Python;
5. A música de aniversário começará a tocar com os LEDs alternando o brilho em sincronia com as notas musicais.

Autor: arkha0xcorvus
