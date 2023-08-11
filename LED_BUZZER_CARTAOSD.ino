// CARTÃO SD

// Bibliotecas Do Cartão SD

#include <SD.h>
#include <SPI.h>

File myFile;

// Pin 53 para Mega / Pin 10 para UNO
int pinoSS = 10;

void setup() {
  // put your setup code here, to run once:

  // Define BaundRate
  Serial.begin(9600);

  // Declara pinoSS como saída
  pinMode(pinoSS, OUTPUT);


  // Inicializa o SD Card
  if (SD.begin()) {

    // Imprime na tela
    Serial.println("SD Card pronto para uso.");

  }

  // Caso o cartão SD não seja inicializado exibe mensagem de erro
  else {
    Serial.println("Falha na inicialização do SD Card.");
    return;
  }

  // Cria e abre um arquivo
  myFile = SD.open("usina.txt", FILE_WRITE);

  // Se o arquivo abrir
  if (myFile) {

    // Imprime Mensagem
    Serial.println("Escrevendo no Arquivo .txt");

    // Escreve no arquivo
    myFile.println("Usinainfo 1, 2 ,3 ...");

    // Fecha o arquivo
    myFile.close();

    // Imprime na tela
    Serial.println("Terminado.");
    Serial.println(" ");

  }

  // Se o arquivo não abrir
  else {

    // Imprime na tela
    Serial.println("Erro ao Abrir Arquivo .txt");
  }

  // Abre o arquivo
  myFile = SD.open("usina.txt");

  // Exibe mensagem na tela e o exibe o conteúdo do arquivo
  if (myFile) {
    Serial.println("Conteúdo do Arquivo:");

    while (myFile.available()) {
      Serial.write(myFile.read());
    }

    // Fecha o arquivo após leitura
    myFile.close();
  }

  // Mensagem de erro ao abrir o arquivo
  else {
    Serial.println("Erro ao Abrir Arquivo .txt");  // Imprime na tela
  }

  // LEDS

  // PINOS DESTINADOS AOS LEDS:

  // LED VERDE GRANDE (LED 05)
  pinMode(7, OUTPUT);

  // LED VERMELHO GRANDE (LED 03)
  pinMode(6, OUTPUT);

  // LED VERDE PEQUENO (LED 02)
  pinMode(5, OUTPUT);

  // LED VERMELHO PEQUENO (LED 01)
  pinMode(4, OUTPUT);

  // BUZZER
  pinMode(3, OUTPUT);
}

void loop() {

  // LEDS
  // PINOS DESTINADOS AOS LEDS
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);

  //  ------------------------

  // BUZZER
  //  tone(3, 1700);
}
