//===========================================================================TODOS OS VALORES SÃO DEMONSTRATIVOS===============================================================================          


struct sensor{
  int analogsensors[2];
  }; 
sensor sensores[2] = {{ {A0, A1} }, { {0, 0} }};                           //sensores[0] = array das portas dos sensores
                                                                           //sensores[1] = array para a leitura dos sensores
                                                                           

struct motors {
  int in[4];
  int pwm[2];
  
  int movimento[5];
  };
motors portasmotor = {5, 6, 7, 8};                                          //portasmotor = sao as portas IN do drive de motor                                       
motors portaspwm = {9, 10};                                                       //spd = portas pwm do robo
motors moves = {1, 2, 3, 4, 5};                                             //reto = 1 esq = 2 dir = 3 tras = 4 parar = 5



struct veloc {
  int minimo;
  int base;
  int maximo;
  }; 
veloc forca[2] = {{50, 100, 150}, {100, 150, 200}};                         //forca[0] = parametros para a curva
                                                                            //forca[1] = parametros para a reta


struct pid {
  int kp;
  int kd;
  int ki;
  }; 
pid valpid[2] = {{2, 0, 0}, {1, 0, 0}};                                     //valpid[0] = parametros para a curva
                                                                            //valpid[1] = parametros para a reta 

int erro, integral, derivado, lasterro, turn; 



void setup(){
  
  int i = 0;
  for (sensores[0].analogsensors[i]; i < 5; i++){                         //seta as portas no for somente para evitar varias linhas de código, levante em conta que temos 5 sensores e 6 portas de motores

    pinMode(sensores[0].analogsensors[i], INPUT);                         //set sensor de refletancia como INPUT
     
    if (i < 4){pinMode(portasmotor.in[i], OUTPUT);}                       //set portas IN dos motores como OUTPUT     

    if (i < 2){pinMode(portaspwm.pwm[i], OUTPUT);}                              //set portas PWM dos motores como OUTPUT
    }
       
}

void loop() {

pid();

}
