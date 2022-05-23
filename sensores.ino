void atsensor(){        //mapeia a leitura dos sensore p/ trabalharmos com, além de valores mais parecidos entre eles, valores mais fáceis de manipular e testar.
 
sensores[1].analogsensors[0] = map(analogRead(sensores[0].analogsensors[0]), 0, 1023, 0, 100);  //mapeia o sensor da esquerda
sensores[1].analogsensors[1] = map(analogRead(sensores[0].analogsensors[1]), 0, 1023, 0, 100);  //mapeia o sensor da direita



  }
