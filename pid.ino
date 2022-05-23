void pid (){

atsensor();               //void atualiza sensores na aba sensores


//---------------------------------------------------------------------------------------------------------------------------------------------------------calculos

                                                                            //O proporcional é o coração do segue linha e muitas vezes é usado individualmente.
erro = sensores[1].analogsensors[0] - sensores[1].analogsensors[1];         //O cálculo do erro provém da diferença de sensores, permitindo, assim, identificar a posição do robo em relação a linha


if ((erro > 50) || (erro < -50)){                                           //como o erro está grande, entende que o robo está em curvas
                                                                            //sendo assim, resgata os valores de kp, ki e kd para curvas
  
valpid[0].kp = valpid[0].kp* erro;                                          //e corrigi-lo de acordo com a necessidade.
                                                   


integral = integral + erro;                                                 //No integral, somamos todos os erros em busca de eliminar as leituras acumuladas nos sensores.
valpid[0].ki = valpid[0].ki* integral;                                      //Utilizando o ki como coeficiente de tempo.



derivado = erro - lasterro;                                                 //no derivado, a ideia é comparar o erro atual com o anterior, prevendo o próximo movimento e suavizando a correção
valpid[0].kd = valpid[0].kd* derivado;                                      //ps.       precisamos no final de toda a lógica, tornar o erro atual em erro anterior, assim, na nova leitura, comparamos ambos.
                             

  
turn = valpid[0].kp + valpid[0].ki + valpid[0].kd;                          // ao fim do calculo, somamos todos os resultados, qual será aplicado nos motores para a correção acertiva.
//soma  
  
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

else{                                                                       //entende como se o erro fosse menor, resgatando os valores de kp, ki e kd para reta
        
valpid[1].kp = valpid[1].kp* erro;                                          //e corrigi-lo de acordo com a necessidade.
                                                   


integral = integral + erro;                                                 //No integral, somamos todos os erros em busca de eliminar as leituras acumuladas nos sensores.
valpid[1].ki = valpid[1].ki* integral;                                      //Utilizando o ki como coeficiente de tempo.



derivado = erro - lasterro;                                                 //no derivado, a ideia é comparar o erro atual com o anterior, prevendo o próximo movimento e suavizando a correção
valpid[1].kd = valpid[1].kd* derivado;                                      //ps.       precisamos no final de toda a lógica, tornar o erro atual em erro anterior, assim, na nova leitura, comparamos ambos.
                             

  
turn = valpid[1].kp + valpid[1].ki + valpid[1].kd;                          // ao fim do calculo, somamos todos os resultados, qual será aplicado nos motores para a correção acertiva.
//soma

}


abs(turn);                                                                  //torna o valor positivo
if (turn < forca[0].minimo) {turn = forca[0].minimo;}                       //modula os valores de turn dentro das limitações de velocidade pré-definidas
if (turn > forca[1].maximo) {turn = forca[1].maximo;}  


//----------------------------------------------n--------------------------------execução dos movimentos

if (erro >= 0) {            //significa que o valor do sensor da esquerda é maior que o da direita, ou seja, o robo está à esquerda da linha

  mover (2, 0 - turn, turn);       //primeiro valor: configura o robo para a direita | segundo valor: força motor da esquerda | terceiro valor: força motor da direita
    
  }

else if (erro < 0){         //siginica que o valor do sensor da direita é maior que o da esquerda, ou seja, o robo está à direita da linha

  mover (1, turn, 0 - turn);       //primeiro valor: configura o robo para a esquerda | segundo valor: força motor da esquerda | terceiro valor: força motor da direita
  
  }  
  
erro = lasterro;

}
