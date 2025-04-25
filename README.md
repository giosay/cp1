CP1 - Grupo UXcellence

integrantes:Ana Luiza De Franco e Rinaldi, Giovana Gaspar Larocca, Giovanna Lins Sayama, Rayssa Luzia Portela Aquino.

Sistema de Monitoramento de Luminosidade para Vinheria Agnello - UXcellence

- Objetivo:

Este sistema foi desenvolvido para monitorar a luminosidade no ambiente de armazenamento de vinhos da Vinheria Agnello. A qualidade do vinho é influenciada por fatores ambientais, e este projeto implementa alertas visuais e sonoros para manter o controle ideal da luminosidade.

- Funcionalidade:

- Captura de luminosidade pelo LDR.
- Conversão de sinal analógico.
- LEDs para sinalizar o status.
- Buzzer para alerta sonoro.
- Display LCD com logo de nossa empresa, mensagem de boas-vindas e porcentagem da luminosidade.
- Conversão de valor lido com função map() para escala de 0 a 100%.

- Componentes:

- Arduino Uno.
- LDR + resistor de 10k.
- LEDs (Verde, Amarelo, Vermelho).
- Buzzer.
- Display LCD 16x2 com módulo I2C.
- Protoboard.
- Cabos macho-macho/macho-fêmea.


- Como Executar

1. Montar o circuito.
2. Carregar o código no Arduino usando a IDE do Arduino.
3. Conecte o Arduino à alimentação ou USB.
4. O sistema inicia com a logo da empresa (UXcellence) e uma mensagem de boas-vindas.
5. O display mostra o nível de luminosidade em porcentagem.
6. O sistema de LEDs muda dependendo do valor da luminosidade.
7. O buzzer apita sutilmente quando a luz amarela acende, e apita mais forte quando muda para vermelha.
