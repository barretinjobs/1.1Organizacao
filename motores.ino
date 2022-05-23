void mover (int direcao, int forca1, int forca2){  

if (direcao == moves.movimento[0]){                                      //andaria para frente, por exemplo
  
digitalWrite(portasmotor.in[0], HIGH);
digitalWrite(portasmotor.in[1], LOW);
digitalWrite(portasmotor.in[2], LOW);
digitalWrite(portasmotor.in[3], HIGH);

analogWrite(portasmotor.pwm[0], forca1);
analogWrite(portasmotor.pwm[1], forca2);  

}

else if (direcao == moves.movimento[1]){                                 //esquerda
  
digitalWrite(portasmotor.in[0], HIGH);
digitalWrite(portasmotor.in[1], LOW);
digitalWrite(portasmotor.in[2], HIGH);
digitalWrite(portasmotor.in[3], LOW);

analogWrite(portasmotor.pwm[0], forca1);
analogWrite(portasmotor.pwm[1], forca2); 
    
}


else if (direcao == moves.movimento[2]){                                 //direita
  
digitalWrite(portasmotor.in[0], LOW);
digitalWrite(portasmotor.in[1], HIGH);
digitalWrite(portasmotor.in[2], LOW);
digitalWrite(portasmotor.in[3], HIGH);

analogWrite(portasmotor.pwm[0], forca1);
analogWrite(portasmotor.pwm[1], forca2);  
    
}

else if (direcao == moves.movimento[3]){                                 //tras
  
digitalWrite(portasmotor.in[0], LOW);
digitalWrite(portasmotor.in[1], HIGH);
digitalWrite(portasmotor.in[2], HIGH);
digitalWrite(portasmotor.in[3], LOW);

analogWrite(portasmotor.pwm[0], forca1);
analogWrite(portasmotor.pwm[1], forca2);  
    
}

else if (direcao == moves.movimento[4]){                                 //parar
  
digitalWrite(portasmotor.in[0], HIGH);
digitalWrite(portasmotor.in[1], HIGH);
digitalWrite(portasmotor.in[2], HIGH);
digitalWrite(portasmotor.in[3], HIGH);

analogWrite(portasmotor.pwm[0], forca1);
analogWrite(portasmotor.pwm[1], forca2);  
    
  }

}
