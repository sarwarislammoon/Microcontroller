//#include "ledc_reg.h"




#define LEDC_HSCH0_HPOINT_REG               (DR_REG_LEDC_BASE + 0x0004)

uint32_t dead_time = 10;


const int PWM_resolution = 8;         // PWM resolution in bits
const int PWM_channel_1 =0;
const int PWM_channel_2 =1;

void setup() {
 pwm_init(100000, 5, 17); 
 pwm_duty(255*0.4);
}



void loop() {
  // Your code here
  
  int i=0;
  for (i=10; i< 200; i++){
    pwm_duty(20+i);
    delay(100);
  }
  
  for (i=10; i< 200; i++){
    pwm_duty(250-i);
    delay(100);
  }

}


void pwm_init(uint32_t PWM_frequency, uint8_t PWM_pin_1, uint8_t PWM_pin_2){
 // Configure PWM pins as output
  uint8_t duty = 0;
  pinMode(PWM_pin_1, OUTPUT);
  pinMode(PWM_pin_2, OUTPUT);


  // Configure Timer/Counter for PWM
  ledcSetup(PWM_channel_1, PWM_frequency, PWM_resolution);
  ledcAttachPin(PWM_pin_1, PWM_channel_1);
  REG_WRITE(LEDC_HSCH0_HPOINT_REG, dead_time);
  ledcWrite(PWM_channel_1, duty-2*dead_time);

  ledcSetup(PWM_channel_2, PWM_frequency, PWM_resolution);
  ledcAttachPin(PWM_pin_2, PWM_channel_2);
  ledcWrite(PWM_channel_2, duty);
  //REG_WRITE(GPIO_FUNC17_OUT_SEL_CFG_REG, READ_PERI_REG(GPIO_FUNC17_OUT_SEL_CFG_REG) | GPIO_FUNC17_OUT_INV_SEL); // change pin no accoardingly to invert output 
  

  uint32_t temp_reg_addr=DR_REG_GPIO_BASE + (0x530+0x4*PWM_pin_2);
  REG_WRITE(temp_reg_addr, REG_READ(temp_reg_addr) | GPIO_FUNC17_OUT_INV_SEL);
  
}




void pwm_duty(uint8_t duty){
  REG_WRITE(LEDC_HSCH0_HPOINT_REG, dead_time);
  ledcWrite(PWM_channel_1, duty-2*dead_time);

  ledcWrite(PWM_channel_2, duty);
}
