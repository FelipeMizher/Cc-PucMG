// ===================================================================
// ==          Hardware e Pinos de Conexão (Hardware)             ==
// ===================================================================
int led_vermelho = 13;
int led_amarelo  = 12;
int led_verde    = 11;
int led_azul     = 10;

// ===================================================================
// ==         Variáveis Globais e Registradores (Simulador)       ==
// ===================================================================
const int tamanho_memoria = 100;
String memoria[tamanho_memoria];
const int INICIO_PROGRAMA = 4;
int contador_instrucoes = 0;
int PC = INICIO_PROGRAMA;
char W = '0';
char X = '0';
char Y = '0';

// ===================================================================
// ==                       Declaração das Funções                    ==
// ===================================================================
void resetar_maquina();
void carregar_memoria_inicial();
void carregar_instrucoes(String entrada);
void executar_instrucoes();
String executar_ula(char opA, char opB, char opS);
int hexchar_para_int(char hexc);
void atualizar_leds(int resultado);
void imprimir_memoria();

// ===================================================================
// ==                        Função Principal SETUP                 ==
// ===================================================================
void setup() {
  Serial.begin(9600);
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo,  OUTPUT);
  pinMode(led_verde,    OUTPUT);
  pinMode(led_azul,     OUTPUT);
}

// ===================================================================
// ==                          Função Principal LOOP                ==
// ===================================================================
void loop() {
  if (Serial.available() > 0) {
    resetar_maquina();

    String entrada_serial = Serial.readString();
    String entrada_limpa = "";
    for (int i = 0; i < entrada_serial.length(); i++) {
      char c = entrada_serial.charAt(i);
      if (isHexadecimalDigit(c)) {
        entrada_limpa += c;
      }
    }

    carregar_instrucoes(entrada_limpa);
    executar_instrucoes();
  }
}

// ===================================================================
// ==                   Implementação das Funções                   ==
// ===================================================================

void resetar_maquina() {
  PC = INICIO_PROGRAMA;
  contador_instrucoes = 0;
  W = '0';
  X = '0';
  Y = '0';
  for (int i = 0; i < tamanho_memoria; i++) {
    memoria[i] = "";
  }
  carregar_memoria_inicial();
}

void carregar_memoria_inicial() {
  memoria[0] = String(PC);
  memoria[1] = "0";
  memoria[2] = "0";
  memoria[3] = "0";
}

void carregar_instrucoes(String entrada) {
  int size = entrada.length();
  int i = 0;
  while (i < size) {
    if (i + 3 <= size) {
      if ((INICIO_PROGRAMA + contador_instrucoes) < tamanho_memoria) {
          memoria[INICIO_PROGRAMA + contador_instrucoes] = entrada.substring(i, i + 3);
          contador_instrucoes++;
          i = i + 3;
      } else {
          Serial.println("ERRO: Memoria cheia durante o carregamento!");
          break;
      }
    } else {
      break;
    }
  }
}

void executar_instrucoes() {
  String instruction = "";
  imprimir_memoria();
  delay(4000); // ALTERADO: Delay de 2s para 4s.

  while (PC < (INICIO_PROGRAMA + contador_instrucoes)) {
    memoria[0] = String(PC);
    instruction = memoria[PC];

    if (instruction.length() == 3) {
      X = instruction.charAt(0);
      Y = instruction.charAt(1);
      char S = instruction.charAt(2);

      String resp_hex = executar_ula(X, Y, S);
      if (resp_hex.length() > 0) {
        W = resp_hex.charAt(0);
      }
    } else {
      Serial.println("ERRO: Tentando executar instrucao mal formada: " + instruction);
    }
    
    memoria[1] = String(W);
    memoria[2] = String(X);
    memoria[3] = String(Y);

    atualizar_leds(hexchar_para_int(W));
    imprimir_memoria();
    delay(4000); // ALTERADO: Delay de 2s para 4s.

    PC = PC + 1;
  }
  Serial.println("Fim da execucao do programa!");
}

String executar_ula(char opA, char opB, char opS) {
  int resp = 0;
  int A = hexchar_para_int(opA);
  int B = hexchar_para_int(opB);
  char opcode = toupper(opS);

  switch (opcode) {
    case '0': resp = 15; break;
    case '1': resp = 0; break;
    case '2': resp = A | ((~B) & 0x0F); break;
    case '3': resp = ((~A) & 0x0F) | ((~B) & 0x0F); break;
    case '4': resp = (~(A & B)) & 0x0F; break;
    case '5': resp = (~B) & 0x0F; break;
    case '6': resp = (~A) & 0x0F; break;
    case '7': resp = ((~A) & 0x0F) ^ ((~B) & 0x0F); break;
    case '8': resp = A ^ B; break;
    case '9': resp = A; break;
    case 'A': resp = B; break;
    case 'B': resp = A & B; break;
    case 'C': resp = A & ((~B) & 0x0F); break;
    case 'D': resp = ((~A) & 0x0F) & B; break;
    case 'E': resp = A | B; break;
    case 'F': resp = (~((~A) & B)) & 0x0F; break;
    default:
      Serial.println("ERRO: Instrucao (opcode) invalida! -> " + String(opcode));
      return "";
  }
  
  resp = resp & 0x0F;
  
  String resultado = String(resp, HEX);
  resultado.toUpperCase();
  return resultado;
}

int hexchar_para_int(char hexc) {
  hexc = toupper(hexc);
  if (hexc >= '0' && hexc <= '9') {
    return hexc - '0';
  } else if (hexc >= 'A' && hexc <= 'F') {
    return 10 + (hexc - 'A');
  }
  return 0;
}

void atualizar_leds(int resultado) {
  digitalWrite(led_vermelho, bitRead(resultado, 3));
  digitalWrite(led_amarelo,  bitRead(resultado, 2));
  digitalWrite(led_verde,    bitRead(resultado, 1));
  digitalWrite(led_azul,     bitRead(resultado, 0));
}

void imprimir_memoria() {
  Serial.print("->|");
  int size = INICIO_PROGRAMA + contador_instrucoes;
  for (int i = 0; i < size; i++) {
    Serial.print(memoria[i]);
    Serial.print("|");
  }
  Serial.println("");
}