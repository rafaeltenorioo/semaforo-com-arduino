# 💡 Semáforo de Tráfego e Pedestre com Arduino

Este é um projeto pessoal de introdução ao **Arduino**, focado na simulação da lógica de um sistema de semáforo completo. O objetivo foi aplicar conceitos básicos de programação para controlar entradas e saídas digitais, recriando o ciclo de tráfego de um cruzamento com duas vias de carros e uma passagem de pedestres.

## ✨ Motivação

Com um grande interesse na área de eletrônica e programação de hardware, este projeto serviu como um exercício prático para entender a programação de sistemas de controle e a interação do código com o mundo físico.

## 🛠️ Detalhes da Implementação

### Lógica de Controle

O sistema opera em um ciclo de 4 fases, controlado pela leitura de um botão (`pinBotao`):

1.  **Fase 1 (Verde Carros):** Via principal e secundária abertas (Verde). Pedestre **Vermelho**.
2.  **Fase 2 (Atenção):** Vias em Alerta (Amarelo/Azul). Pedestre **Vermelho**.
3.  **Fase 3 (Vermelho Carros):** Vias fechadas (Vermelho). Pedestre **Verde**.
4.  **Fase 4 (Pisca Pedestre):** Vias fechadas (Vermelho). Pedestre piscando entre Vermelho e Apagado.

### ⚠️ Nota sobre o Hardware

Pequena gambiarra do hardware: Como eu não tinha LEDs amarelos disponíveis para esta montagem, utilizei LEDs azuis em seu lugar para sinalizar a fase de atenção (o nosso "amarelo").

## ⚙️ Componentes e Conexões

| Componente | Cor | Pino Digital (Arduino) |
| :--- | :--- | :--- |
| **Via Principal** | Vermelho | 10 |
| | Amarelo (Azul) | 9 |
| | Verde | 8 |
| **Via Secundária** | Vermelho | 11 |
| | Amarelo (Azul) | 4 |
| | Verde | 5 |
| **Pedestre** | Vermelho | 3 |
| | Verde | 2 |
| **Entrada** | Botão de Pressão | 7 |

*Obs.: Todos os componentes de saída (LEDs) estão conectados com seus devidos resistores (220Ω) para limitar a corrente.*

## 🎬 Demonstração

### Circuito Finalizado

![Foto da montagem do semáforo com Arduino na protoboard](imagem_de_apresentacao.jpg)


### OBS: o vídeo completo do circuito funcionando pode ser visto no meu linkedin (https://www.linkedin.com/feed/update/urn:li:activity:7393607108446900225/)
