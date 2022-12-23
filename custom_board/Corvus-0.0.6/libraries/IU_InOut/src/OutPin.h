class OutPin{
  private:
    uint16_t status;
    const uint8_t latchPin = 8; //Пин подключен к RCLK входу 74HC595
    const uint8_t clockPin = 9; //Пин подключен к SRCLK входу 74HC595
    const uint8_t dataPin = 10; //Пин подключен к SER входу 74HC595
    

  public:
    OutPin(){
		pinMode(this->latchPin, OUTPUT);
		pinMode(this->clockPin, OUTPUT);
		pinMode(this->dataPin, OUTPUT);
		this->status = 0;
		this->registerWrite(this->status);
	};
    void registerWrite(uint16_t value){
		digitalWrite(this->latchPin, LOW);
		byte registerOne = highByte(value);
		byte registerTwo = lowByte(value);
		shiftOut(this->dataPin, this->clockPin, MSBFIRST, registerOne);
		shiftOut(this->dataPin, this->clockPin, MSBFIRST, registerTwo);
		digitalWrite(this->latchPin, HIGH);
	};
    void PinSet(uint8_t pin){
		bitSet(this->status, pin-1);
		this->registerWrite(this->status);
	};
    void PinReset(uint8_t pin){
		bitClear(this->status, pin-1);
		this->registerWrite(this->status);
	};
    void PinToggle(uint8_t pin){
		bool bit;
		if(bit = bitRead(this->status, pin-1)){
			bit = 0;
		}
		else{
			bit = 1;
		}
		bitWrite(this->status, pin-1, bit);
		this->registerWrite(this->status);
	};
    void PortWrite(uint16_t value){
		this->status = value;
		this->registerWrite(this->status);
	};
    bool PinRead(uint8_t pin) {return bitRead(this->status, pin-1);};
    uint16_t PortRead() {return this->status;};
};
