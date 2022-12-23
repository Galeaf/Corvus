class InPin{
  private:

  public:
  InPin(){
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(13, OUTPUT);
	pinMode(A0, INPUT);
	pinMode(A1, INPUT);
	pinMode(A2, INPUT);
	pinMode(A3, INPUT);
	pinMode(A4, INPUT);
	pinMode(A5, INPUT);
	pinMode(A6, INPUT);
	pinMode(A7, INPUT);
	};
  uint8_t PinRead(uint8_t pin){
    uint8_t value;
    switch (pin){
    case 1:{
    	digitalWrite(11, LOW); //C
    	digitalWrite(12, HIGH); //B
    	digitalWrite(13, LOW); //A
    	value = digitalRead(A0); //COM
    }
    break;
    case 2:{
    	digitalWrite(11, HIGH); //C
    	digitalWrite(12, LOW); //B
    	digitalWrite(13, HIGH); //A
    	value = digitalRead(A0); //COM
    }
    break;
    case 3:{
    	digitalWrite(11, LOW); //C
    	digitalWrite(12, LOW); //B
    	digitalWrite(13, HIGH); //A
    	value = digitalRead(A0); //COM
    }
    break;
    case 4:{
    	digitalWrite(11, HIGH); //C
    	digitalWrite(12, HIGH); //B
    	digitalWrite(13, HIGH); //A
    	value = digitalRead(A0); //COM
    }
    break;
    case 5:{
    	digitalWrite(11, LOW); //C
    	digitalWrite(12, LOW); //B
    	digitalWrite(13, LOW); //A
    	value = digitalRead(A0); //COM
    }
    break;
    case 6:{
    	digitalWrite(11, HIGH); //C
    	digitalWrite(12, HIGH); //B
    	digitalWrite(13, LOW); //A
    	value = digitalRead(A0); //COM
    }
    break;
    case 7:{
    	digitalWrite(11, LOW); //C
    	digitalWrite(12, HIGH); //B
    	digitalWrite(13, HIGH); //A
    	value = digitalRead(A0); //COM
    }
    break;
    case 8:{
    	digitalWrite(11, HIGH); //C
    	digitalWrite(12, LOW); //B
    	digitalWrite(13, LOW); //A
    	value = digitalRead(A0); //COM
    }
    break;
    case 9:
    	value = digitalRead(A1);
    break;
    case 10:
    	value = digitalRead(A2);
    break;
    case 11:
    	value = digitalRead(A3);
    break;
    case 12:
    	value = digitalRead(A4);
    break;
    case 13:
    	value = digitalRead(A5);
    break;
    case 14:{
    	uint16_t temp = analogRead(A6);
    	if(temp < 250)
    	value = 0;
    	else
    	value = 1;
    }
    break;
    case 15:{
    	uint16_t temp = analogRead(A7);
    	if(temp < 250)
    	value = 0;
    	else
    	value = 1;
    }
    break;
    default:
    	value = 0;
    break;
    }
    return value;
	};
};
