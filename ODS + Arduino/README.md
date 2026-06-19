# Sistema Inteligente de Monitoramento de Água

## Descrição

Projeto desenvolvido no Tinkercad utilizando Arduino Uno com o objetivo de monitorar o consumo de água e identificar possíveis situações de desperdício ou vazamento.

O sistema utiliza sensores para acompanhar as condições do reservatório e, com base nas leituras realizadas, aciona alertas visuais e sonoros, além de controlar automaticamente uma válvula simulada por meio de um servo motor.

Este projeto está alinhado ao Objetivo de Desenvolvimento Sustentável (ODS) 6 da ONU, que busca garantir a disponibilidade e o uso sustentável da água para todos.

## Objetivo

Desenvolver um sistema automatizado capaz de:

- Monitorar o nível da água;
- Detectar possíveis vazamentos;
- Identificar consumo elevado;
- Emitir alertas visuais e sonoros;
- Simular o fechamento automático de uma válvula para evitar desperdícios.

## Componentes Utilizados

- Arduino Uno
- Sensor Ultrassônico HC-SR04
- LEDs
  - Verde
  - Vermelho
  - Azul
- Buzzer
- Micro Servo Motor
- Potenciômetro
- Botão
- Resistores
- Protoboard

## Funcionamento

O Arduino realiza leituras contínuas dos sensores e classifica a situação em três estados:

### Consumo Normal
- LED verde aceso;
- Buzzer desligado;
- Válvula aberta.

### Consumo Elevado
- LED azul aceso;
- Alerta sonoro ativado;
- Abertura da válvula reduzida.

### Vazamento Detectado
- LED vermelho aceso;
- Alerta sonoro ativado;
- Válvula fechada automaticamente.

## Recursos Implementados

- Monitoramento automático do nível da água;
- Detecção de vazamentos;
- Controle de válvula com servo motor;
- Alertas visuais por LEDs;
- Alertas sonoros por buzzer;
- Calibração por potenciômetro;
- Rotina de testes pelo Monitor Serial;
- Filtragem de sinais utilizando média móvel.

## Simulação

Link do projeto no Tinkercad:https://www.tinkercad.com/things/g0YAnXtxe2X/editel?returnTo=%2Fdashboard&sharecode=NrMQB3EdHImOPqdON9taIZ-NtFkVkjsjajwpelJbbZk
