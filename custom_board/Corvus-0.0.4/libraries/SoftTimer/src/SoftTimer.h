#pragma once

class SoftTimer{
  public:
    SoftTimer(){
      _status = 0;
    }
    SoftTimer(uint32_t time){
      _status = 0;
      _counter = time;
    }
    void Stop(){
      _time = 0;
      _status = 0;
    }
    bool Cycle(){
      if(millis() - _time > _counter && _status == 1){
        _time = millis();
        return 1;
      }
      else{
        return 0;
      }
    }
    bool Status(){
      return _status;
    }
    void Start(){
      _time = millis();
      _status = 1;
    }
    void Start(uint32_t time){
      _time = millis();
      _status = 1;
      _counter = time;
    }
    void SetCounter(uint32_t time){
      _counter = time;
    }
    uint32_t GetCounter(){
      return _counter;
    }
  private:
   uint32_t _time;
   uint32_t _counter;
   bool _status;
};